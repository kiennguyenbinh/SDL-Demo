#include "StateManager.h"
#include "PlayerState.h"
#include "Timer.h"

bool isExit = false;
int main()
{
	//setting windows
	WindowsSetting *cs = new WindowsSetting();
	cs->positionX = cs->positionY = SDL_WINDOWPOS_UNDEFINED;
	cs->width = 600;
	cs->height = 400;
	cs->flag = SDL_WINDOW_SHOWN;
	cs->title = "ConTra SDL";

	
	//setting render
	cs->RenderSetting = new RenderSetting();
	cs->RenderSetting->flag = SDL_RENDERER_ACCELERATED;
	
	//setting IMG external
	cs->IMGFlag = IMG_INIT_PNG;

	//Init default state
	
	StateManager::getInstance()->SwitchState(new PlayerState());
	//Init FPS
	Timer fps;

	if (Graphics::getInstance()->Init(cs))
	{
		//MainLoop
		while (!isExit) {
			fps.start();
			StateManager::getInstance()->getCurrentState()->Update();
			Graphics::getInstance()->CleanDraw();
			StateManager::getInstance()->getCurrentState()->Draw();
			Graphics::getInstance()->Draw();
			if (fps.get_ticks() < 1000 / FPS_LIMIT)
			{
				SDL_Delay((1000 / FPS_LIMIT) - fps.get_ticks());
			}
		}
	}
	
	//EndMain
	Graphics::getInstance()->Destroy();
	exit(0);
}