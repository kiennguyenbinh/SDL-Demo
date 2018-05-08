#include "EventManager.h"
#include <algorithm>


EventManager::EventManager()
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
	for each (auto it in m_event)
	{
		RaiseEvent(it.second);
		m_event.erase(it.first);
	}
}

void EventManager::PostEvent(CoreEvent& _event,EventPriority _priority) {
	m_event.insert(std::make_pair(_priority, _event));
}

EventManager* EventManager::getInstance() {
	static EventManager* instance = nullptr;
	if (instance) {
		return instance;
	}
	instance = new EventManager();
	return instance;
}
