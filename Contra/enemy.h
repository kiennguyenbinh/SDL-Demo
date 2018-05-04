#pragma once
#include "Graphics.h"
#include "GameCustom.h"
#include "Object.h"

class enemy : public Object
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
	void execute();
};
