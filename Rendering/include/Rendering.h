#ifndef RENDERING
#define RENDERING
#include <vector>

class SDL_Window;

class Rendering
{
public:
	Rendering();
	~Rendering();
	Rendering(const Rendering& other) = delete;
	Rendering(Rendering&& other) = delete;
	Rendering& operator=(const Rendering& other) = delete;
	Rendering& operator=(Rendering&& other) = delete;

	SDL_Window* createWindow(char* title, int x, int y, int width, int height, uint32_t flags);

private:
	std::vector<SDL_Window*> _activeWindows;
};

#endif