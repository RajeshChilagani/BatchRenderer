#pragma once
#include "OrthographicCamera.h"
#include "GL-Core/Events/ApplicationEvent.h"
#include "GL-Core/Events/MouseEvent.h"
#include "GL-Core/Core/Timestep.h"

#include <glm/glm.hpp>
namespace GLCore
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation=false);
		OrthographicCameraController(uint32_t width, uint32_t height, bool rotation=false);
		void OnUpdate(Timestep dt);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const  { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; }

		void OnResize(float width, float height);
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		glm::vec3 m_CameraPosition{0.0f,0.0f,0.0f};
		float m_CameraRotation=0.0f;               //rotation in degrees
		float m_CameraTranslationSpeed = 0.1f, m_CameraRotationSpeed = 90.0f;
	};
}