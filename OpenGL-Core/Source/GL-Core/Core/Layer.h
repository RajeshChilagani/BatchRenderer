#pragma once
#include <iostream>
#include <string>

#include "Core.h"
#include "GL-Core/Events/Event.h"
#include "Timestep.h"

namespace GLCore
{
	class Layer
	{
	public:
		Layer(const std::string& i_LayerName) :m_DebugName(i_LayerName) {}
		virtual ~Layer() = default;

		virtual void OnAttach()  {}
		virtual void OnDetach()  {}
		virtual void OnUpdate(Timestep dt)  {}
		virtual void ImGuiRender() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}