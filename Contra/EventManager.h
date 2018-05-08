#pragma once
#include "CoreEvent.h"
#include "Listener.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
class EventManager
{
private:
	std::map<EventPriority, CoreEvent> m_event;
	std::vector<Listener*> m_listener;
public:
	EventManager();
	~EventManager();
	void Update();
	void RaiseEvent(CoreEvent& _event);
	void PostEvent(CoreEvent& _event, EventPriority _priority);
	void AddListener(Listener* _listen);

	
};

