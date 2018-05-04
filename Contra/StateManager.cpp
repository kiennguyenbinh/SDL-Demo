#include "StateManager.h"



StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

StateManager* StateManager::getInstance() {
	static StateManager* instance;
	if (instance != nullptr) {
		return instance;
	}
	instance = new StateManager();
	return instance;
}

bool StateManager::SwitchState(StateBase* _state) {
	if (_state != nullptr) {
		PopAllState();
		if (PushState(_state)) {
			m_stackstate.back()->Init();
			m_stackstate.back()->Resume();
			return true;
		}

	}
	return false;
	
}

bool StateManager::PushState(StateBase* _new_state) {
	if (_new_state != nullptr) {
		m_stackstate.push_front(_new_state);
		return true;
	}
	return false;
}

bool StateManager::PopState() {

	if (m_stackstate.back() != nullptr) {
		m_stackstate.back()->Suppend();
		m_stackstate.back()->Destroy();
		delete m_stackstate.back();
		m_stackstate.pop_back();
	}

	if (m_stackstate.size() > 0) {
		m_stackstate.back()->Resume();
	}
	return true;
}
bool StateManager::PopAllState() {
	while (m_stackstate.size() != 0) {
		PopState();
	}
	return true;
}