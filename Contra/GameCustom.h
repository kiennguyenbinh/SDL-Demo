#pragma once


#define STEP_MOVE 1
#define MAX_ENEMY 15
const int FPS_LIMIT = 30;

enum MOVE_EVENT
{
	EVENT_MOVE_NONE = -1,
	EVENT_MOVE_UP,
	EVENT_MOVE_DOWN,
	EVENT_MOVE_LEFT,
	EVENT_MOVE_RIGHT
};

struct Pos
{

	int x;
	int y;
	int w;
	int h;
	Pos(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {};
};

