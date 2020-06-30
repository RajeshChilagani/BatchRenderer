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
	}
	void Application::Run()
	{
		KeyPressedEvent K(2, 23);
		LOG_TRACE(K);
		MouseButtonPressedEvent mb(23);
		LOG_INFO(mb);
		WindowResizeEvent wr(100, 200);
		LOG_WARN(wr);
		while (1)
		{

		}
	}
}