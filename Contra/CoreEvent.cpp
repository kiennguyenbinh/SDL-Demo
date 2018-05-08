#include "CoreEvent.h"



CoreEvent::CoreEvent(int _data, int _type = EventType::NONE_EVENT) 
	: m_data(_data),
	m_type(_type),
	m_flag(EventFlag::NORMAL),
	m_status(EventState::QUEUE)
{
}


CoreEvent::~CoreEvent()
{
}
