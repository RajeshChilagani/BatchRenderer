#pragma once
#include <functional>
#include <string>

#include "GL-Core/Core/Core.h"
#include "GL-Core/Events/Event.h"

namespace GLCore
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;
		WindowProps(const std::string& i_Title="Batch Renderer", uint32_t i_Width=1280, uint32_t i_Height=720) :Title(i_Title), Width(i_Width), Height(i_Height) {}
	};

	//Window Interface which will be implemented per platform
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() = default;
		virtual void OnUpdate() = 0;
		virtual uint32_t GetWidth() const= 0;
		virtual uint32_t GetHeight() const= 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const= 0;

		virtual void* GetNativeWindow() const = 0;
		static Window* Create(const WindowProps& i_Props = WindowProps());

	private:
	};
}
