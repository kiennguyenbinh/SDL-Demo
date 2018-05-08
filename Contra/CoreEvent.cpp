#include "CoreEvent.h"



CoreEvent::CoreEvent(int _data, int _type = EventType::NONE_EVENT) 
	: m_data(_data),
	m_type(_type),
	m_flag(EventFlag::FLAG_NORMAL),
	m_status(EventState::STATE_QUEUE)
{
}


CoreEvent::~CoreEvent()
{
}
