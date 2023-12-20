#include "Rendering.h"
#include "Window.h"
#include <SDL.h>

Rendering::Rendering()
	:_activeWindows{}
	,_closeWindowCallbacks{}
	,_pContext{nullptr}
{

}

Rendering::~Rendering()
{
	for (Window* window : _activeWindows)
	{
		window->CloseWindow();
		delete window;
	}

	delete _pContext;
}

//TODO: Add renderer creation option/main window option
Window* Rendering::createWindow(char* title, int x, int y, int width, int height, uint32_t flags)
{
	Window* result = new Window(this, title, x, y, width, height, flags);
	_activeWindows.push_back(result);
	return result;
}

void* Rendering::createGlContext(Window* mainWindow)
{
	if (_pContext == nullptr)
	{
		_pContext = SDL_GL_CreateContext(mainWindow->getSdlWindow());
	}

	return _pContext;
}


void Rendering::RegisterWindowCallback(Window* window, std::function<void()> function)
{
	_closeWindowCallbacks.emplace(window->getId(), function);
}

void Rendering::RemoveWindow(Window* window)
{
	_activeWindows.erase(std::remove(_activeWindows.begin(), _activeWindows.end(), window), _activeWindows.end());
	_closeWindowCallbacks.erase(window->getId());
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
