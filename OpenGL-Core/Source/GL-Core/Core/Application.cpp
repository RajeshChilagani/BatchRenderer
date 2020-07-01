#include "Application.h"

#include "Core.h"
#include "Log.h"
#include "GL-Core/Events/KeyEvent.h"
#include "GL-Core/Events/MouseEvent.h"
#include "GL-Core/Events/ApplicationEvent.h"
namespace GLCore
{
	Application* Application::s_Instance = nullptr;
	Application::Application(const std::string& i_Name, uint32_t i_Width, uint32_t i_Height)
	{
		if (!s_Instance)
		{
			Log::Init();
		}
		GLCORE_ASSERT(!s_Instance, "Application aleady exists")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create({ i_Name,i_Width,i_Height }));
	}
	void Application::Run()
	{
		LOG_INFO("Application Run Begin");
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}