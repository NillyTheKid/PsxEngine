#include "Window.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include "Rendering.h"

Window::Window(Rendering* rendering, char* title, int x, int y, int width, int height, unsigned int flags)
	:_pWindow{nullptr}
	,_pRendering{rendering}
{
	_pWindow = SDL_CreateWindow(title, x, y, width, height, flags);
	_id = SDL_GetWindowID(_pWindow);
}

Window::~Window()
{
	//CloseWindow();
	//delete _pWindow;
	_pRendering = nullptr;
}

void Window::setBackgroundColour(Colour c)
{
	_backgroundColour = c;
}

void Window::StartRendering(void* context)
{
	SDL_GL_MakeCurrent(_pWindow, context);
	glClearColor(_backgroundColour.r, _backgroundColour.g, _backgroundColour.b, _backgroundColour.a);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Window::FinishRendering()
{
	SDL_GL_SwapWindow(_pWindow);
}
void Window::CloseWindow()
{
	SDL_DestroyWindow(_pWindow);
	_pRendering->RemoveWindow(this);
}

unsigned int Window::getId() const
{
	return _id;
}
SDL_Window* Window::getSdlWindow() const
{
	return _pWindow;
}