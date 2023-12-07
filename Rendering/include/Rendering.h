#ifndef RENDERING
#define RENDERING
#include <vector>
#include <map>
#include <functional>

class SDL_Window;

struct SDL_WindowEvent;

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
	void RegisterWindowCallback(SDL_Window* window, std::function<void()> function);

	void ParseWindowEvent(SDL_WindowEvent& e);

private:
	std::vector<SDL_Window*> _activeWindows;
	std::map<uint32_t, std::function<void()>> _closeWindowCallbacks;
};

#endif