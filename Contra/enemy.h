#pragma once
#include "Graphics.h"
#include "GameCustom.h"

class enemy
{
private:
	SDL_Rect m_enemy;
	int reverse;
public:
	enemy();
	~enemy();
	void Init(int _x, int _y);
	void Update();
	void Draw();
};
