#include "Rendering.h"
#include "Window.h"
#include <SDL.h>

Rendering::Rendering()
	:_pContext{nullptr}
{

}

Rendering::~Rendering()
{
	if (_pContext != nullptr)
	{
		SDL_GL_DeleteContext(_pContext);
	}
}

void* Rendering::createGlContext(Window* mainWindow)
{
	if (_pContext == nullptr)
	{
		_pContext = SDL_GL_CreateContext(mainWindow->getSdlWindow());
	}

	return _pContext;
}
