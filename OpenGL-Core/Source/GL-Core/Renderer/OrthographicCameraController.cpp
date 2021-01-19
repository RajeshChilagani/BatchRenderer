#include "OrthographicCameraController.h"

#include "GL-Core/Core/Core.h"
#include "GL-Core/Core/Input.h"
#include "GL-Core/Core/KeyCodes.h"
#include <GLFW/glfw3.h>

namespace GLCore
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		:m_AspectRatio(aspectRatio), m_Camera(-m_ZoomLevel * m_AspectRatio, m_ZoomLevel * m_AspectRatio, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{

	}

	OrthographicCameraController::OrthographicCameraController(uint32_t width, uint32_t height, bool rotation)
		:m_AspectRatio((float)width/(float)height), m_Camera(-m_ZoomLevel * m_AspectRatio, m_ZoomLevel* m_AspectRatio, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{

	}

	void OrthographicCameraController::OnUpdate(Timestep dt)
	{
		if (Input::IsKeyPressed(KeyCode::A))
		{
			m_CameraPosition.x -= m_CameraTranslationSpeed;
		}
		else if (Input::IsKeyPressed(KeyCode::D))
		{
			m_CameraPosition.x += m_CameraTranslationSpeed;
		}

		if (Input::IsKeyPressed(KeyCode::W))
		{
			m_CameraPosition.y += m_CameraTranslationSpeed;
		}
		else if (Input::IsKeyPressed(KeyCode::S))
		{
			m_CameraPosition.y -= m_CameraTranslationSpeed;
		}
		else if (Input::IsKeyPressed(KeyCode::Z))
		{
			m_CameraPosition.z -= m_CameraTranslationSpeed;
		}
		else if (Input::IsKeyPressed(KeyCode::C))
		{
			m_CameraPosition.z += m_CameraTranslationSpeed;
		}

		if (m_Rotation)
		{
			if (Input::IsKeyPressed(KeyCode::Q))
			{
				m_CameraRotation += m_CameraRotationSpeed * dt;
			}
			else if (Input::IsKeyPressed(KeyCode::E))
			{
				m_CameraRotation -= m_CameraRotationSpeed * dt;
			}
			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPositon(m_CameraPosition);
	}

	

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(GL_CORE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(GL_CORE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		//m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		OnResize((float)e.GetWidth(), (float)e.GetHeight());
		return false;
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

}