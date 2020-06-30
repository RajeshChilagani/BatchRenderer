#pragma once
#include <sstream>
#include "Event.h"

namespace GLCore
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
	protected:
		KeyEvent(int i_KeyCode) :m_KeyCode(i_KeyCode) {}
		int m_KeyCode;
	};
	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int i_KeyCode, int i_RepeatCount) : KeyEvent(i_KeyCode), m_RepeatCount(i_RepeatCount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss<< "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();

		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	
	};
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int i_KeyCode) : KeyEvent(i_KeyCode){}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();

		}
		EVENT_CLASS_TYPE(KeyReleased)
	private:

	};
	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int i_KeyCode) : KeyEvent(i_KeyCode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();

		}
		EVENT_CLASS_TYPE(KeyTyped)
	private:

	};
}
