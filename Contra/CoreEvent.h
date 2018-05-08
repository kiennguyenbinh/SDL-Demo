#pragma once
enum EventState
{
	NONE = 0,
	QUEUE,
	CANCEL
};
enum EventFlag
{
	NONE = 0,
	NORMAL,

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
	LOW = 0,
	NORMAL,
	HIGH,
	URGENT
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

