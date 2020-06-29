#include "Application.h"

#include "Core.h"
#include "Log.h"
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
		while (1)
		{

		}
	}
}