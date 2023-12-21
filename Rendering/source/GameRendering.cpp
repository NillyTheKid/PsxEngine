#include "GameRendering.h"
#include "Window.h"
#include <SDL.h>

GameRendering::GameRendering()
	:_activeWindow{nullptr}
	,_closeWindowCallback{}
{

}

GameRendering::~GameRendering()
{
	_activeWindow->CloseWindow();
	delete _activeWindow;
}

Window* GameRendering::createWindow(char* title, int x, int y, int width, int height, uint32_t flags)
{
	if (_activeWindow == nullptr)
	{
		_activeWindow = new Window(this, title, x, y, width, height, flags);
	}
	return _activeWindow;
}

void GameRendering::RegisterWindowCallback(Window* window, std::function<void()> function)
{
	_closeWindowCallback = function;
}

void GameRendering::RemoveWindow(Window* window)
{
	//DO nothing if gameRenderer
}

void GameRendering::Render()
{
	_activeWindow->StartRendering(_pContext, false);
	//TODO: Render components attached to this window
	_activeWindow->FinishRendering();
}

void GameRendering::ParseWindowEvent(SDL_WindowEvent& e)
{
	switch (e.event)
	{
	case SDL_WINDOWEVENT_CLOSE:
	{
		_closeWindowCallback();
	} break;
	}
}
