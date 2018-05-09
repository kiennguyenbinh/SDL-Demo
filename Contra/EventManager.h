#pragma once
#include "CoreEvent.h"
#include "Listener.h"
#include <deque>
#include <iostream>
#include <string>
#include <vector>
class EventManager
{
private:
	std::deque<CoreEvent> m_event;
	std::vector<Listener*> m_listener;
public:
	EventManager();
	~EventManager();
	static EventManager* getInstance();
	void Update();
	void RaiseEvent(CoreEvent& _event);
	void PostEvent(CoreEvent& _event, EventPriority _priority);
	void AddListener(Listener* _listen);

};

