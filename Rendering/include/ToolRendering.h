#ifndef RENDERING_TOOLRENDERING
#define RENDERING_TOOLRENDERING
#include "Rendering.h"
#include <vector>
#include <map>
#include <functional>

class ToolRendering : public Rendering
{
public:
	ToolRendering();
	~ToolRendering();
	ToolRendering(const ToolRendering& other) = delete;
	ToolRendering(ToolRendering&& other) = delete;
	ToolRendering& operator=(const ToolRendering& other) = delete;
	ToolRendering& operator=(ToolRendering&& other) = delete;

	Window* createWindow(char* title, int x, int y, int width, int height, uint32_t flags) override;
	void RegisterWindowCallback(Window* window, std::function<void()> function) override;

	//NOTE: Only call this function from Window class
	void RemoveWindow(Window* window) override;

	void Render() override;
	void ParseWindowEvent(SDL_WindowEvent& e) override;

private:
	std::vector<Window*> _activeWindows;
	std::map<uint32_t, std::function<void()>> _closeWindowCallbacks;
};

#endif