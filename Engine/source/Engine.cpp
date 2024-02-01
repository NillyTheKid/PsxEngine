#include "Engine.h"
#include "ToolRendering.h"
#include "GameRendering.h"
#include "Input.h"
#pragma warning(disable:26451)
#include <SDL.h>

#include <iostream>

namespace
{
}

Engine::Engine()
	:_isRunning{true}
	,_rendering(nullptr)
	,_input(nullptr)
{
}

Engine::~Engine()
{
	SDL_Quit();
	delete _rendering;
	delete _input;
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
	if (_rendering == nullptr)
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
	}
	return _rendering;
}

Input* Engine::CreateInput()
{
	if (_input == nullptr)
	{
		_input = new Input();
	}

	return _input;
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
	case SDL_KEYDOWN:
	{
		_input->HandleKeyDownEvent(e.key);
	} break;
	case SDL_KEYUP:
	{
		_input->HandleKeyUpEvent(e.key);
	} break;
	}
}