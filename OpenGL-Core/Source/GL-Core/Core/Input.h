#pragma once
#include "Core.h"

namespace GLCore
{
	class Input
	{
	public:
		static bool IsKeyPressed(int i_KeyCode);
		static bool IsMouseButtonPressed(int i_MouseButton);
		static std::pair<float, float> GetMousePosition();
		static float GetMousePositionX();
		static float GetMousePositionY();
	};
}

