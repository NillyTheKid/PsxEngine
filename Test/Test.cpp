#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Core.h"
#include "Rendering.h"
#pragma warning(disable:26451)
#include <SDL.h>
#include <functional>

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
		rendering->RegisterWindowCallback(testWindow, std::bind(&Core::Quit, &core));

		core.Run();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}