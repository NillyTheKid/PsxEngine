#include "Engine.h"
#include "ToolRendering.h"
#include "GameRendering.h"
#pragma warning(disable:26451)
#include <SDL.h>

namespace
{
}

Engine::Engine()
	:_isRunning{true}
	,_rendering(nullptr)
{
}

Engine::~Engine()
{
	SDL_Quit();
	delete _rendering;
}

void Engine::Run()
{
	SDL_Event event;
	while (_isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			ParseEvent(event);
		}

		_rendering->Render();
	}
}

Rendering* Engine::CreateRenderer(bool isGameRenderer)
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	if (isGameRenderer)
	{
		_rendering = new GameRendering();
	}
	else
	{
		_rendering = new ToolRendering();
	}
	return _rendering;
}

void Engine::Quit()
{
	_isRunning = false;
}

void Engine::ParseEvent(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_WINDOWEVENT:
	{
		_rendering->ParseWindowEvent(e.window);
	} break;
	}
}