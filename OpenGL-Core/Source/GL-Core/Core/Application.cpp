#include "Application.h"

#include <functional>

#include "Log.h"
#include "GL-Core/Events/KeyEvent.h"
#include "GL-Core/Events/MouseEvent.h"
#include "GL-Core/Renderer/Renderer.h"
#include "GL-Core/Core/Input.h"
#include <GLFW/glfw3.h>

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
		m_Window->SetEventCallback(GL_CORE_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		Renderer::ShutDown();
	}

	void Application::Run()
	{
		LOG_INFO("Application Run Begin");
		

		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep frameTime = time - m_LastFrameTime;
			//LOG_TRACE("FrameTime:{0}",frameTime);
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(frameTime);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->ImGuiRender();
			m_ImGuiLayer->End();
			m_Window->OnUpdate();
		}
	}
	
	void Application::OnEvent(Event& e)
	{
		//LOG_TRACE(e);
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(GL_CORE_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
			{
				LOG_INFO("{0} Handled", e);
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}