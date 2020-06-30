#pragma once
#include <sstream>
#include "Event.h"

namespace GLCore
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float i_X, float i_Y) :m_MouseX(i_X), m_MouseY(i_Y) {}
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss<<"MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float i_XOffset, float i_YOffset) :m_XOffset(i_XOffset), m_YOffset(i_YOffset) {}
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffet() const { return m_YOffset; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int i_Button) :m_Button(i_Button) {}
		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int i_Button) :MouseButtonEvent(i_Button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
	private:

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int i_Button) :MouseButtonEvent(i_Button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)
			std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
	private:

	};
}