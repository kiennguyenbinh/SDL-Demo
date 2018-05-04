#pragma once
#include "Graphics.h"
#include "GameCustom.h"
#include "Object.h"

class objPlayer : public Object
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
	void execute();
	void setPosition(int x, int y);
	Pos getPostion() { return m_position; };
};

