#pragma once
enum EventState
{
	STATE_NONE = 0,
	STATE_QUEUE,
	STATE_CANCEL
};
enum EventFlag
{
	FLAG_NONE = 0,
	FLAG_NORMAL
};
enum EventType
{
	NONE_EVENT = 0,
	MOUSE_EVENT,
	KEYBOARD_EVENT,
	SYSTEM_EVENT
};
enum EventPriority
{
	EVENT_LOW = 0,
	EVENT_NORMAL,
	EVENT_HIGH,
	EVENT_URGENT
};
class CoreEvent
{
private:
	int m_flag;
	int m_status;
	int m_data;
	int m_type;
public:
	CoreEvent(int m_type, int m_data);
	virtual ~CoreEvent();
};

