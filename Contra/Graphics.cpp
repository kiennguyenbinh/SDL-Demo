#include "Graphics.h"

Graphics::Graphics() : 
	gWindows(nullptr), 
	gRender(nullptr) {

}


Graphics::~Graphics() {

}

bool Graphics::Init(WindowsSetting *cs) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("SDL Init failed :: Cause %s", SDL_GetError());
		return false;
	}

	gWindows = SDL_CreateWindow(
		cs->title.c_str(), 
		cs->positionX, 
		cs->positionY, 
		cs->width, 
		cs->height, 
		cs->flag
	);
	if (gWindows == nullptr) {
		SDL_Log("Windows created error :: Cause %s", SDL_GetError());
		return false;
	}
	gRender = SDL_CreateRenderer(
		gWindows, 
		cs->RenderSetting->index, 
		cs->RenderSetting->flag
	);
	if (gRender == nullptr) {
		SDL_Log("Render Created error :: Cause %s", SDL_GetError());
		return false;
	}
	SDL_RenderSetLogicalSize(gRender, cs->width, cs->height);
	SDL_SetRenderDrawColor(gRender, 0xFF, 0xFF, 0xFF, 0xFF); //set default 
	if (cs->IMGFlag != 0) {
		if (!(IMG_Init(cs->IMGFlag) && cs->IMGFlag)) {
			SDL_Log("IMG Plugin created error :: Cause %s", IMG_GetError());
			return false;
		}
	}

	return true;
}


bool Graphics::CleanDraw() {
	return SDL_RenderClear(gRender);
}
bool Graphics::Draw() {
	// set color to default
	SDL_SetRenderDrawColor(gRender, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderPresent(gRender);
	return true;
}

bool Graphics::Destroy() {
	
	//safe delete pointer
	SDL_DestroyRenderer(gRender);
	gRender = nullptr;

	SDL_DestroyWindow(gWindows);
	gWindows = nullptr;

	IMG_Quit();
	SDL_Quit();
	return true;
}

Graphics* Graphics::getInstance()
{
	static Graphics *instance;

	if (instance != nullptr) {
		return instance;
	}
	instance = new Graphics();
	return instance;
}