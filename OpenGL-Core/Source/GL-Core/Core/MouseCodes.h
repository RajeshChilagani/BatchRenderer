#pragma once
#include <iostream>

namespace GLCore
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define GL_MOUSE_BUTTON_0      ::GLCore::Mouse::Button0
#define GL_MOUSE_BUTTON_1      ::GLCore::Mouse::Button1
#define GL_MOUSE_BUTTON_2      ::GLCore::Mouse::Button2
#define GL_MOUSE_BUTTON_3      ::GLCore::Mouse::Button3
#define GL_MOUSE_BUTTON_4      ::GLCore::Mouse::Button4
#define GL_MOUSE_BUTTON_5      ::GLCore::Mouse::Button5
#define GL_MOUSE_BUTTON_6      ::GLCore::Mouse::Button6
#define GL_MOUSE_BUTTON_7      ::GLCore::Mouse::Button7
#define GL_MOUSE_BUTTON_LAST   ::GLCore::Mouse::ButtonLast
#define GL_MOUSE_BUTTON_LEFT   ::GLCore::Mouse::ButtonLeft
#define GL_MOUSE_BUTTON_RIGHT  ::GLCore::Mouse::ButtonRight
#define GL_MOUSE_BUTTON_MIDDLE ::GLCore::Mouse::ButtonMiddle
