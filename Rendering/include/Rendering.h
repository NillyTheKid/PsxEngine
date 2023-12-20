#ifndef RENDERING
#define RENDERING
#include <vector>
#include <map>
#include <functional>

class Window;

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

	Window* createWindow(char* title, int x, int y, int width, int height, uint32_t flags);
	void* createGlContext(Window* mainWindow);
	void RegisterWindowCallback(Window* window, std::function<void()> function);

	//NOTE: Only call this function from Window class
	void RemoveWindow(Window* window);

	void Render();
	void ParseWindowEvent(SDL_WindowEvent& e);

private:
	void* _pContext;

	std::vector<Window*> _activeWindows;
	std::map<uint32_t, std::function<void()>> _closeWindowCallbacks;
};

#endif