#pragma once
#include "StateBase.h"
#include "objPlayer.h"
#include "enemy.h"
#include <vector>
#include <random>


class PlayerState :
	public StateBase
{
private:
	SDL_Event m_event;
	objPlayer* main_mc;
	std::vector<enemy*> m_vEnemy;
	int _event_state;
public:
	PlayerState();
	~PlayerState();
	bool Init();
	bool Update();
	bool Draw();
	bool Suppend();
	bool Resume();
	bool Destroy();
	void OnEvent(SDL_KeyboardEvent &env);
	void SetMoveEventState(int state) { _event_state = state; };
};

