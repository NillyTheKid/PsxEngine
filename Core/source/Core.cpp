#include "Core.h"
#include "Rendering.h"
#pragma warning(disable:26451)
#include <SDL.h>

namespace
{
}

Core::Core()
	:_isRunning{true}
	,_rendering(nullptr)
{
}

Core::~Core()
{
	SDL_Quit();
	delete _rendering;
}

void Core::Run()
{
	SDL_Event event;
	while (_isRunning)
	{
		SDL_PollEvent(&event);
		ParseEvent(event);
	}
}

Rendering* Core::CreateRenderer()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	_rendering = new Rendering();
	return _rendering;
}

void Core::Quit()
{
	_isRunning = false;
}

void Core::ParseEvent(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_WINDOWEVENT:
	{
		_rendering->ParseWindowEvent(e.window);
	} break;
	}
}