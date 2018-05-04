#pragma once
#include <SDL.h>
#undef main
#include <SDL_image.h>

#include <iostream>
#include <string>

struct RenderSetting
{
	int index = -1;
	Uint32 flag;
};

struct WindowsSetting
{
	int width;
	int height;
	int positionX;
	int positionY;
	std::string title;
	Uint32 flag;
	int IMGFlag = 0;
	RenderSetting *RenderSetting;
};

class Graphics
{
private:
	SDL_Window *gWindows;
	SDL_Renderer *gRender;

public:

	Graphics();
	~Graphics();

	bool Init(WindowsSetting *cs);
	bool Update() { return true; };
	bool CleanDraw();
	bool Draw();
	bool Destroy();
	SDL_Renderer* GetRender() { return gRender; }
	static Graphics* getInstance();
};

