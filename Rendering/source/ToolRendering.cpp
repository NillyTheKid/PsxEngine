#include "ToolRendering.h"
#include "Window.h"
#include <SDL.h>

ToolRendering::ToolRendering()
	:_activeWindows{}
	,_closeWindowCallbacks{}
{

}

ToolRendering::~ToolRendering()
{
	for (Window* window : _activeWindows)
	{
		window->CloseWindow();
		delete window;
	}
}

Window* ToolRendering::createWindow(char* title, int x, int y, int width, int height, uint32_t flags)
{
	Window* result = new Window(this, title, x, y, width, height, flags);
	_activeWindows.push_back(result);
	return result;
}

void ToolRendering::RegisterWindowCallback(Window* window, std::function<void()> function)
{
	_closeWindowCallbacks.emplace(window->getId(), function);
}

void ToolRendering::RemoveWindow(Window* window)
{
	_activeWindows.erase(std::remove(_activeWindows.begin(), _activeWindows.end(), window), _activeWindows.end());
	_closeWindowCallbacks.erase(window->getId());
}

void ToolRendering::Render()
{
	for (Window* window : _activeWindows)
	{
		window->StartRendering(_pContext, true);
		//TODO: Render components attached to this window
		window->FinishRendering();
	}
}

void ToolRendering::ParseWindowEvent(SDL_WindowEvent& e)
{
	switch (e.event)
	{
	case SDL_WINDOWEVENT_CLOSE:
	{
		_closeWindowCallbacks[e.windowID]();
	} break;
	}
}
