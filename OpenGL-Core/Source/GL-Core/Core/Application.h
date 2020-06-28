#pragma once
#include <string>

namespace GLCore
{
	class Application
	{
	public:
		Application(const std::string& i_Name="OpenGLCore", uint32_t i_Width=1280, uint32_t i_Height=720);
		virtual ~Application()=default;

		void Run();

		inline static Application& Get() { return *s_Instance; }
	private:
		bool m_Running = true;
		static Application* s_Instance;
	};
}

