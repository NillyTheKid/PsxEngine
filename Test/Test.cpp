#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Core.h"
#include "Rendering.h"
#pragma warning(disable:26451)
#include <SDL.h>
#include <functional>
#include "Window.h"

namespace
{
}

int main(int argc, char* argv[])
{
	//Have this in separate scope so all destructors are called before dumping memory leaks
	{
		Core core{};
		Rendering* rendering = core.CreateRenderer();		

		auto testWindow = rendering->createWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
		testWindow->setBackgroundColour(Colour(0.0f, 0.0f, 0.0f, 1.0f));
		rendering->RegisterWindowCallback(testWindow, std::bind(&Core::Quit, &core));

		rendering->createGlContext(testWindow);

		auto testWindow2 = rendering->createWindow("Test but small", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 500, SDL_WINDOW_OPENGL);
		testWindow2->setBackgroundColour(Colour(1.0f, 0.0f, 0.0f, 1.0f));
		rendering->RegisterWindowCallback(testWindow2, std::bind(&Window::CloseWindow, testWindow2));

		core.Run();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}