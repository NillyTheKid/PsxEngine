#include "Core.h"
#include "Rendering.h"
#pragma warning(disable:26451)
#include <SDL.h>

Core::Core()
	:_isRunning{true}
{
}

Core::~Core()
{
	SDL_Quit();
	delete _rendering;
}

void Core::Run()
{
	while (_isRunning)
	{

	}
}

Rendering* Core::CreateRenderer()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	return new Rendering();
}