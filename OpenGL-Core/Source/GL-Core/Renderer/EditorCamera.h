#pragma once
#include "Camera.h"
#include "GL-Core/Events/MouseEvent.h"
#include "GL-Core/Core/Timestep.h"

namespace GLCore
{
	class EditorCamera : public Camera
	{
	public:
		EditorCamera();
		EditorCamera(float FOV, float AspectRatio, float NearPlane, float FarPlane);

		void OnUpdate(Timestep Delta);
		void OnEvent(Event& E);

		glm::quat GetOrientation() const;
		glm::vec3 GetForwardDirection() const;
		glm::vec3 GetUpDirection() const;
		glm::vec3 GetRightDirection() const;
		glm::vec3 GetPosition() const { return m_Position; }
		glm::mat4 GetViewProjection() const { return m_Projection * m_View; }

	private:
		void UpdateProjection();
		void UpdateView();
		bool OnMouseScrolled(MouseScrolledEvent& ScrollEvent);
		void MousePan(const glm::vec2& Delta);
		void MouseRotate(const glm::vec2& Delta);
		void MouseZoom(float Delta);
		glm::vec3 CalculatePosition();
		std::pair<float, float> PanSpeed() const;
		float GetRotationSpeed() const;
		float ZoomSpeed() const;

		float m_FOV = 30.f, m_AspectRatio = 1.77f, m_NearPlane = 0.1f, m_FarPlane = 1000.f;
		float m_ViewportWidth = 1280.f, m_ViewportHeight = 720.f;

		glm::vec3 m_Position = { 0.f,0.f,0.f };
		glm::vec3 m_FocalPoint = { 0.f,0.f,0.f };
		glm::mat4 m_View;
		glm::vec2 m_InitialMousePosition = { 0.0f, 0.0f };

		float m_Distance = 10.0f;
		float m_Pitch = 0.0f, m_Yaw = 0.0f;
		float m_RotationSpeed = 0.8f;
	};
}
