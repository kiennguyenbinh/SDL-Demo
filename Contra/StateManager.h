#pragma once
#include <deque>
#include <iostream>
#include "StateBase.h"

class StateManager
{
private:
	std::deque<StateBase*> m_stackstate;
public:
	StateManager();
	~StateManager();
	static StateManager* getInstance();
	bool PushState(StateBase* _state);
	bool PopState();
	bool PopAllState();
	bool SwitchState(StateBase* _new_state);
	StateBase* getCurrentState() { return m_stackstate.size() != 0 ? m_stackstate.back() : nullptr; };
};

