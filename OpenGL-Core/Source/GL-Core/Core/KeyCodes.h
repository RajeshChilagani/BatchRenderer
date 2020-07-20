#pragma once
#include <iostream>

namespace GLCore
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39,      /* ' */
		Comma = 44,           /* , */
		Minus = 45,           /* - */
		Period = 46,          /* . */
		Slash = 47,           /* / */

		D0 = 48,              /* 0 */
		D1 = 49,              /* 1 */
		D2 = 50,              /* 2 */
		D3 = 51,              /* 3 */
		D4 = 52,              /* 4 */
		D5 = 53,              /* 5 */
		D6 = 54,              /* 6 */
		D7 = 55,              /* 7 */
		D8 = 56,              /* 8 */
		D9 = 57,              /* 9 */

		Semicolon = 59,       /* ; */
		Equal = 61,           /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,     /* [ */
		Backslash = 92,       /* \ */
		RightBracket = 93,    /* ] */
		GraveAccent = 96,     /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define GL_KEY_SPACE           ::GLCore::Key::Space
#define GL_KEY_APOSTROPHE      ::GLCore::Key::Apostrophe    /* ' */
#define GL_KEY_COMMA           ::GLCore::Key::Comma         /* , */
#define GL_KEY_MINUS           ::GLCore::Key::Minus         /* - */
#define GL_KEY_PERIOD          ::GLCore::Key::Period        /* . */
#define GL_KEY_SLASH           ::GLCore::Key::Slash         /* / */
#define GL_KEY_0               ::GLCore::Key::D0
#define GL_KEY_1               ::GLCore::Key::D1
#define GL_KEY_2               ::GLCore::Key::D2
#define GL_KEY_3               ::GLCore::Key::D3
#define GL_KEY_4               ::GLCore::Key::D4
#define GL_KEY_5               ::GLCore::Key::D5
#define GL_KEY_6               ::GLCore::Key::D6
#define GL_KEY_7               ::GLCore::Key::D7
#define GL_KEY_8               ::GLCore::Key::D8
#define GL_KEY_9               ::GLCore::Key::D9
#define GL_KEY_SEMICOLON       ::GLCore::Key::Semicolon     /* ; */
#define GL_KEY_EQUAL           ::GLCore::Key::Equal         /* = */
#define GL_KEY_A               ::GLCore::Key::A
#define GL_KEY_B               ::GLCore::Key::B
#define GL_KEY_C               ::GLCore::Key::C
#define GL_KEY_D               ::GLCore::Key::D
#define GL_KEY_E               ::GLCore::Key::E
#define GL_KEY_F               ::GLCore::Key::F
#define GL_KEY_G               ::GLCore::Key::G
#define GL_KEY_H               ::GLCore::Key::H
#define GL_KEY_I               ::GLCore::Key::I
#define GL_KEY_J               ::GLCore::Key::J
#define GL_KEY_K               ::GLCore::Key::K
#define GL_KEY_L               ::GLCore::Key::L
#define GL_KEY_M               ::GLCore::Key::M
#define GL_KEY_N               ::GLCore::Key::N
#define GL_KEY_O               ::GLCore::Key::O
#define GL_KEY_P               ::GLCore::Key::P
#define GL_KEY_Q               ::GLCore::Key::Q
#define GL_KEY_R               ::GLCore::Key::R
#define GL_KEY_S               ::GLCore::Key::S
#define GL_KEY_T               ::GLCore::Key::T
#define GL_KEY_U               ::GLCore::Key::U
#define GL_KEY_V               ::GLCore::Key::V
#define GL_KEY_W               ::GLCore::Key::W
#define GL_KEY_X               ::GLCore::Key::X
#define GL_KEY_Y               ::GLCore::Key::Y
#define GL_KEY_Z               ::GLCore::Key::Z
#define GL_KEY_LEFT_BRACKET    ::GLCore::Key::LeftBracket   /* [ */
#define GL_KEY_BACKSLASH       ::GLCore::Key::Backslash     /* \ */
#define GL_KEY_RIGHT_BRACKET   ::GLCore::Key::RightBracket  /* ] */
#define GL_KEY_GRAVE_ACCENT    ::GLCore::Key::GraveAccent   /* ` */
#define GL_KEY_WORLD_1         ::GLCore::Key::World1        /* non-US #1 */
#define GL_KEY_WORLD_2         ::GLCore::Key::World2        /* non-US #2 */
								 
/* FunctGLn keys */				 
#define GL_KEY_ESCAPE          ::GLCore::Key::Escape
#define GL_KEY_ENTER           ::GLCore::Key::Enter
#define GL_KEY_TAB             ::GLCore::Key::Tab
#define GL_KEY_BACKSPACE       ::GLCore::Key::Backspace
#define GL_KEY_INSERT          ::GLCore::Key::Insert
#define GL_KEY_DELETE          ::GLCore::Key::Delete
#define GL_KEY_RIGHT           ::GLCore::Key::Right
#define GL_KEY_LEFT            ::GLCore::Key::Left
#define GL_KEY_DOWN            ::GLCore::Key::Down
#define GL_KEY_UP              ::GLCore::Key::Up
#define GL_KEY_PAGE_UP         ::GLCore::Key::PageUp
#define GL_KEY_PAGE_DOWN       ::GLCore::Key::PageDown
#define GL_KEY_HOME            ::GLCore::Key::Home
#define GL_KEY_END             ::GLCore::Key::End
#define GL_KEY_CAPS_LOCK       ::GLCore::Key::CapsLock
#define GL_KEY_SCROLL_LOCK     ::GLCore::Key::ScrollLock
#define GL_KEY_NUM_LOCK        ::GLCore::Key::NumLock
#define GL_KEY_PRINT_SCREEN    ::GLCore::Key::PrintScreen
#define GL_KEY_PAUSE           ::GLCore::Key::Pause
#define GL_KEY_F1              ::GLCore::Key::F1
#define GL_KEY_F2              ::GLCore::Key::F2
#define GL_KEY_F3              ::GLCore::Key::F3
#define GL_KEY_F4              ::GLCore::Key::F4
#define GL_KEY_F5              ::GLCore::Key::F5
#define GL_KEY_F6              ::GLCore::Key::F6
#define GL_KEY_F7              ::GLCore::Key::F7
#define GL_KEY_F8              ::GLCore::Key::F8
#define GL_KEY_F9              ::GLCore::Key::F9
#define GL_KEY_F10             ::GLCore::Key::F10
#define GL_KEY_F11             ::GLCore::Key::F11
#define GL_KEY_F12             ::GLCore::Key::F12
#define GL_KEY_F13             ::GLCore::Key::F13
#define GL_KEY_F14             ::GLCore::Key::F14
#define GL_KEY_F15             ::GLCore::Key::F15
#define GL_KEY_F16             ::GLCore::Key::F16
#define GL_KEY_F17             ::GLCore::Key::F17
#define GL_KEY_F18             ::GLCore::Key::F18
#define GL_KEY_F19             ::GLCore::Key::F19
#define GL_KEY_F20             ::GLCore::Key::F20
#define GL_KEY_F21             ::GLCore::Key::F21
#define GL_KEY_F22             ::GLCore::Key::F22
#define GL_KEY_F23             ::GLCore::Key::F23
#define GL_KEY_F24             ::GLCore::Key::F24
#define GL_KEY_F25             ::GLCore::Key::F25
		
/* KeypaGL*/					 
#define GL_KEY_KP_0            ::GLCore::Key::KP0
#define GL_KEY_KP_1            ::GLCore::Key::KP1
#define GL_KEY_KP_2            ::GLCore::Key::KP2
#define GL_KEY_KP_3            ::GLCore::Key::KP3
#define GL_KEY_KP_4            ::GLCore::Key::KP4
#define GL_KEY_KP_5            ::GLCore::Key::KP5
#define GL_KEY_KP_6            ::GLCore::Key::KP6
#define GL_KEY_KP_7            ::GLCore::Key::KP7
#define GL_KEY_KP_8            ::GLCore::Key::KP8
#define GL_KEY_KP_9            ::GLCore::Key::KP9
#define GL_KEY_KP_DECIMAL      ::GLCore::Key::KPDecimal
#define GL_KEY_KP_DIVIDE       ::GLCore::Key::KPDivide
#define GL_KEY_KP_MULTIPLY     ::GLCore::Key::KPMultiply
#define GL_KEY_KP_SUBTRACT     ::GLCore::Key::KPSubtract
#define GL_KEY_KP_ADD          ::GLCore::Key::KPAdd
#define GL_KEY_KP_ENTER        ::GLCore::Key::KPEnter
#define GL_KEY_KP_EQUAL        ::GLCore::Key::KPEqual
		
#define GL_KEY_LEFT_SHIFT      ::GLCore::Key::LeftShift
#define GL_KEY_LEFT_CONTROL    ::GLCore::Key::LeftControl
#define GL_KEY_LEFT_ALT        ::GLCore::Key::LeftAlt
#define GL_KEY_LEFT_SUPER      ::GLCore::Key::LeftSuper
#define GL_KEY_RIGHT_SHIFT     ::GLCore::Key::RightShift
#define GL_KEY_RIGHT_CONTROL   ::GLCore::Key::RightControl
#define GL_KEY_RIGHT_ALT       ::GLCore::Key::RightAlt
#define GL_KEY_RIGHT_SUPER     ::GLCore::Key::RightSuper
#define GL_KEY_MENU            ::GLCore::Key::Menu
