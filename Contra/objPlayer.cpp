#include "objPlayer.h"



objPlayer::objPlayer(): m_position(0,0,0,0) {

}


objPlayer::~objPlayer() {

}
void objPlayer::Init(Pos _pos) {
	m_position = Pos(_pos);
}
void objPlayer::Update() {
	m_main.x = m_position.x;
	m_main.y = m_position.y;
	m_main.w = m_position.w;
	m_main.h = m_position.h;
}
void objPlayer::Draw() {
	SDL_SetRenderDrawColor(Graphics::getInstance()->GetRender(), 255, 0, 0, 255);
	SDL_RenderFillRect(Graphics::getInstance()->GetRender(), &m_main);
}
void objPlayer::execute() {

}
void objPlayer::setPosition(int x, int y) {
	m_position.x = x;
	m_position.y = y;
}