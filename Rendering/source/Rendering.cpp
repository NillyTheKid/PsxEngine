#include "Rendering.h"
#include <SDL.h>

Rendering::Rendering()
	:_activeWindows{}
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
