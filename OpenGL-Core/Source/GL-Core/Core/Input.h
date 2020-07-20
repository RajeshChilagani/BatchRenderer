#pragma once
#include "Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace GLCore
{
	class Input
	{
	public:
		static bool IsKeyPressed(Key i_KeyCode);
		static bool IsMouseButtonPressed(Mouse i_MouseButton);
		static std::pair<float, float> GetMousePosition();
		static float GetMousePositionX();
		static float GetMousePositionY();
	};
}

