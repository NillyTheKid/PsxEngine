#include "Engine.h"
#include "ToolRendering.h"
#include "GameRendering.h"
#include "Input.h"
#include "ECS.h"
#pragma warning(disable:26451)
#include <SDL.h>

#include <iostream>
#include <chrono>

namespace
{
}

Engine::Engine()
	:_isRunning{true}
	,_rendering(nullptr)
	,_input(nullptr)
	,_ecs(nullptr)
{
}

Engine::~Engine()
{
	SDL_Quit();
	delete _rendering;
	delete _input;
	delete _ecs;
}

void Engine::Run()
{
	auto prevTime = std::chrono::steady_clock::now().time_since_epoch();
	SDL_Event event;
	while (_isRunning)
	{
		auto currTime = std::chrono::steady_clock::now().time_since_epoch();
		while (SDL_PollEvent(&event))
		{
			ParseEvent(event);
		}

		float deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currTime - prevTime).count() / 1000.0f;
		_ecs->UpdateSystems(deltaTime);
		_rendering->Render();

		prevTime = currTime;
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

ECS* Engine::CreateEcs()
{
	if (_ecs == nullptr)
	{
		_ecs = new ECS();
	}

	return _ecs;
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