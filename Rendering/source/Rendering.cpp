#include "Rendering.h"
#include <SDL.h>

Rendering::Rendering()
	:_activeWindows{}
	,_closeWindowCallbacks{}
{

}

Rendering::~Rendering()
{
	for (SDL_Window* window : _activeWindows)
	{
		SDL_DestroyWindow(window);
	}
}

//TODO: Add renderer creation option/main window option
SDL_Window* Rendering::createWindow(char* title, int x, int y, int width, int height, uint32_t flags)
{
	SDL_Window* result = SDL_CreateWindow(title, x, y, width, height, flags);
	_activeWindows.push_back(result);
	return result;
}

void Rendering::RegisterWindowCallback(SDL_Window* window, std::function<void()> function)
{
	uint32_t windowId = SDL_GetWindowID(window);
	_closeWindowCallbacks.emplace(windowId, function);
}


void Rendering::ParseWindowEvent(SDL_WindowEvent& e)
{
	switch (e.event)
	{
	case SDL_WINDOWEVENT_CLOSE:
	{
		_closeWindowCallbacks[e.windowID]();
	} break;
	}
}
