#pragma once
#include <string>

#include "Core.h"
#include "GL-Core/Events/Event.h"
#include "GL-Core/Events/ApplicationEvent.h"
#include "GL-Core/ImGui/ImGuiLayer.h"
#include "LayerStack.h"
#include "Window.h"

namespace GLCore
{
	class Application
	{
	public:
		Application(const std::string& i_Name="OpenGLCore", uint32_t i_Width=1280, uint32_t i_Height=720);
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
	private:
		static Application* s_Instance;
	};
}

