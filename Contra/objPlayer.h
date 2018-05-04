#pragma once
#include "Graphics.h"
#include "GameCustom.h"

class objPlayer
{
private:
	Pos m_position;
	SDL_Rect m_main;
public:
	objPlayer();
	~objPlayer();
	void Init(Pos _pos);
	void Update();
	void Draw();
	void setPosition(int x, int y);
	Pos getPostion() { return m_position; };
};

