#include "Core.h"
#include "Rendering.h"
#pragma warning(disable:26451)
#include <SDL.h>

int main(int argc, char* argv[])
{
	Core core{};
	Rendering* rendering = core.CreateRenderer();

	auto testWindow = rendering->createWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	core.Run();

	return 0;
}