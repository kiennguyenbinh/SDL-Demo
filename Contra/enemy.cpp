#include "enemy.h"



enemy::enemy() : reverse(-1)
{

}


enemy::~enemy()
{
}

void enemy::Init(int _x, int _y)
{
	m_enemy.x = _x;
	m_enemy.y = _y;
	m_enemy.w = 20;
	m_enemy.h = 20;
}

void enemy::Update()
{
	if ((m_enemy.y < 20))
	{
		reverse = 1;
	}
	else if (m_enemy.y > 380)
	{
		reverse = -1;
	}
	m_enemy.y += (reverse) * STEP_MOVE;
}

void enemy::Draw()
{
	SDL_SetRenderDrawColor(Graphics::getInstance()->GetRender(), 255, 0, 255, 255);
	SDL_RenderFillRect(Graphics::getInstance()->GetRender(), &m_enemy);
}
void enemy::execute() {

}