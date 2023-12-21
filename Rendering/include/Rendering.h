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
	virtual ~Rendering();
	Rendering(const Rendering& other) = delete;
	Rendering(Rendering&& other) = delete;
	Rendering& operator=(const Rendering& other) = delete;
	Rendering& operator=(Rendering&& other) = delete;

	virtual Window* createWindow(char* title, int x, int y, int width, int height, uint32_t flags) = 0;
	void* createGlContext(Window* mainWindow);
	virtual void RegisterWindowCallback(Window* window, std::function<void()> function) = 0;

	//NOTE: Only call this function from Window class
	virtual void RemoveWindow(Window* window) = 0;

	virtual void Render() = 0;
	virtual void ParseWindowEvent(SDL_WindowEvent& e) = 0;

protected:
	void* _pContext;
};

#endif