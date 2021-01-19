#include "EditorCamera.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/quaternion.hpp"
#include "GL-Core/Core/Input.h"

namespace GLCore
{
	class Mat4
	{
	public:
		Mat4() = default;
		Mat4(glm::quat Rot, glm::vec3 Pos)
		{
			value[3] = glm::vec4(Pos, 1.0f);
			const auto _2x = Rot.x + Rot.x;
			const auto _2y = Rot.y + Rot.y;
			const auto _2z = Rot.z + Rot.z;
			const auto _2xx = Rot.x * _2x;
			const auto _2xy = _2x * Rot.y;
			const auto _2xz = _2x * Rot.z;
			const auto _2xw = _2x * Rot.w;
			const auto _2yy = _2y * Rot.y;
			const auto _2yz = _2y * Rot.z;
			const auto _2yw = _2y * Rot.w;
			const auto _2zz = _2z * Rot.z;
			const auto _2zw = _2z * Rot.w;

			value[0][0] = 1.0f - _2yy - _2zz;
			value[1][0] = _2xy - _2zw;
			value[2][0] = _2xz + _2yw;

			value[0][1] = _2xy + _2zw;
			value[1][1] = 1.0f - _2xx - _2zz;
			value[2][1] = _2yz - _2xw;

			value[0][2] = _2xz - _2yw;
			value[1][2] = _2yz + _2xw;
			value[2][2] = 1.0f - _2xx - _2yy;
		}
		glm::vec4 value[4] = { {1.f,0.f,0.f,0.f},{0.f,1.f,0.f,0.f},{0.f,0.f,1.f,0.f},{0.f,0.f,0.f,1.f} };
	};
	
	EditorCamera::EditorCamera()
		:Camera(glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane))
	{

	}
	EditorCamera::EditorCamera(float FOV, float AspectRatio, float NearPlane, float FarPlane)
		: Camera(glm::perspective(glm::radians(FOV), AspectRatio, NearPlane, FarPlane)), m_FOV(FOV), m_AspectRatio(AspectRatio), m_NearPlane(NearPlane), m_FarPlane(FarPlane)
	{
		UpdateView();
	}
	void EditorCamera::OnUpdate(Timestep Delta)
	{
		if (Input::IsKeyPressed(KeyCode::LeftAlt))
		{
			const glm::vec2& MousePosition{ Input::GetMousePositionX(), Input::GetMousePositionY() };
			glm::vec2 Delta = (MousePosition - m_InitialMousePosition) * 0.003f;
			m_InitialMousePosition = MousePosition;
			if (Input::IsMouseButtonPressed(Mouse::ButtonLeft))
				MouseRotate(Delta);

		}
		UpdateView();
	}
	void EditorCamera::OnEvent(Event& E)
	{
		EventDispatcher dispatcher(E);
		dispatcher.Dispatch<MouseScrolledEvent>(GL_CORE_BIND_EVENT_FN(EditorCamera::OnMouseScrolled));
	}

	glm::quat EditorCamera::GetOrientation() const
	{
		//return glm::quat(glm::vec3(m_Pitch,m_Yaw,0.0f));
		return glm::quat(glm::vec3(-m_Pitch, -m_Yaw, 0.0f));
	}
	glm::vec3 EditorCamera::GetForwardDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
	}
	glm::vec3 EditorCamera::GetUpDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.f, 1.f, 0.f));
	}
	glm::vec3 EditorCamera::GetRightDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(1.f, 0.f, 0.f));
	}
	void EditorCamera::UpdateProjection()
	{
		m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
		m_Projection = glm::perspective(m_FOV, m_AspectRatio, m_NearPlane, m_FarPlane);
	}
	void EditorCamera::UpdateView()
	{
		m_Position = CalculatePosition();
		glm::quat orientation = GetOrientation();
		m_View = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
		m_View = glm::inverse(m_View);
	}
	bool EditorCamera::OnMouseScrolled(MouseScrolledEvent& ScrollEvent)
	{
		float delta = ScrollEvent.GetYOffset() * 0.1f;
		MouseZoom(delta);
		UpdateView();
		return false;
	}
	void EditorCamera::MouseRotate(const glm::vec2& Delta)
	{
		float yawSign = GetUpDirection().y < 0 ? -1.0f : 1.0f;
		m_Yaw += yawSign * Delta.x * m_RotationSpeed;
		m_Pitch += Delta.y * GetRotationSpeed();
	}
	void EditorCamera::MouseZoom(float Delta)
	{
		m_Distance -= Delta * ZoomSpeed();
		if (m_Distance < 1.0f)
		{
			m_FocalPoint += GetForwardDirection();
			m_Distance = 1.0f;
		}
	}
	glm::vec3 EditorCamera::CalculatePosition()
	{
		return m_FocalPoint - GetForwardDirection() * m_Distance;
	}
	float EditorCamera::GetRotationSpeed() const
	{
		return m_RotationSpeed;
	}
	float EditorCamera::ZoomSpeed() const
	{
		float distance = m_Distance * 0.2f;
		distance = std::max(distance, 0.0f);
		float speed = distance * distance;
		speed = std::min(speed, 100.0f); // max speed = 100
		return speed;
	}

}