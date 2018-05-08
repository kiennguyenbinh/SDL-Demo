#include "EventManager.h"
#include <algorithm>


EventManager::EventManager()
	: m_event(0, 0),
	m_listener(0)
{
}


EventManager::~EventManager()
{

}

void EventManager::AddListener(Listener* _listen) {
	if (_listen != nullptr) {
		m_listener.push_back(_listen);
	}
}
void EventManager::RaiseEvent(CoreEvent& _event) {
	for each (auto it in m_listener)
	{
		it->OnEvent(_event);
	}
}

void EventManager::Update() {
	std::sort(m_event.begin(), m_event.end());
	for each (auto it in m_event)
	{
		RaiseEvent(it.second);
		m_event.erase(it.first);
	}
}

void EventManager::PostEvent(CoreEvent& _event,EventPriority _priority) {
	m_event.insert(std::pair<EventPriority, CoreEvent>(_priority, _event));
}