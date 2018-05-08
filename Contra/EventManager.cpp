#include "EventManager.h"



EventManager::EventManager()
	: m_event(0, 0),
	m_listener(0)
{
}


EventManager::~EventManager()
{

}

void EventManager::AddListener(int x) {
	if (x) {
		m_listener.push_back(x);
	}
}
void EventManager::RaiseEvent(CoreEvent& _event) {
	for each (auto it in m_listener)
	{
		//TODO: process onEvent
	}
}

void EventManager::Update() {
	for each (auto it in m_event)
	{
		RaiseEvent(it.second);
	}
}

void EventManager::PostEvent(CoreEvent& _event,EventPriority _priority) {
	m_event.insert(std::pair<EventPriority, CoreEvent>(_priority, _event));
}