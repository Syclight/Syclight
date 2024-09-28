#pragma once

#include "Event.h"

namespace syc 
{
	class SYC_API KeyEvent : public Event
	{
	public:
		inline int16 GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int16 keycode)
			: m_KeyCode(keycode) {}
		int16 m_KeyCode;
	};

	class SYC_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int16 keycode, int16 repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		inline int GetRepratCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode<< " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int16 m_RepeatCount;
	};

	class SYC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int16 keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};
}