#pragma once

#include "GL-Core/Core/Core.h"
#include "GL-Core/Core/Layer.h"
namespace GLCore
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time;
	};
}