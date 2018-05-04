#include "PlayerState.h"



PlayerState::PlayerState() : 
	main_mc(nullptr),
	_event_state(EVENT_MOVE_NONE){
	
}


PlayerState::~PlayerState() {
	delete main_mc;
	main_mc = nullptr;
}
bool PlayerState::Init() {

	main_mc = new objPlayer();
	main_mc->Init(Pos(20, 20, 20, 20));
	int rand_enemy = rand() % MAX_ENEMY + 1 ;
	for (int i = 0; i < rand_enemy; i++) {
		m_vEnemy.push_back(new enemy());
		m_vEnemy.back()->Init(rand() % 580 + 20 , rand() % 20 + 380);
	}
	return true;
}
bool PlayerState::Update() {

	main_mc->Update();
	for each (enemy* it in m_vEnemy)
	{
		it->Update();
	}
	if (_event_state == EVENT_MOVE_UP) {
		main_mc->setPosition(main_mc->getPostion().x, main_mc->getPostion().y - STEP_MOVE);
	}
	else if (_event_state == EVENT_MOVE_DOWN) {
		main_mc->setPosition(main_mc->getPostion().x, main_mc->getPostion().y + STEP_MOVE);
	}
	else if (_event_state == EVENT_MOVE_LEFT) {
		main_mc->setPosition(main_mc->getPostion().x - STEP_MOVE, main_mc->getPostion().y);
	}
	else if (_event_state == EVENT_MOVE_RIGHT) {
		main_mc->setPosition(main_mc->getPostion().x + STEP_MOVE, main_mc->getPostion().y);
	}
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type)
		{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				OnEvent(m_event.key);
				break;
		}
			
				
	}
	return true;
}
bool PlayerState::Draw() {

	main_mc->Draw();
	for each (enemy* it in m_vEnemy)
	{
		it->Draw();
	}
	return true;
}
void PlayerState::OnEvent(SDL_KeyboardEvent &event) {
	//SDL_Log("Event type :: %d", event.keysym.sym);
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.keysym.sym) {
		case SDLK_w:
			SetMoveEventState(EVENT_MOVE_UP);
			break;
		case SDLK_s:
			SetMoveEventState(EVENT_MOVE_DOWN);
			break;
		case SDLK_a:
			SetMoveEventState(EVENT_MOVE_LEFT);
			break;
		case SDLK_d:
			SetMoveEventState(EVENT_MOVE_RIGHT);
			break;
		default:
			SetMoveEventState(EVENT_MOVE_NONE);
			break;
		}
		break;
	case SDL_KEYUP:
		SetMoveEventState(EVENT_MOVE_NONE);
		break;
	}
	
}
bool PlayerState::Suppend() {
	return true;
}
bool PlayerState::Resume() {
	return true;
}
bool PlayerState::Destroy() {
	return true;
}

