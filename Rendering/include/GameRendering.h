#ifndef RENDERING_GAMERENDERING
#define RENDERING_GAMERENDERING
#include "Rendering.h"
#include <functional>

class GameRendering : public Rendering
{
public:
	GameRendering();
	~GameRendering();
	GameRendering(const GameRendering& other) = delete;
	GameRendering(GameRendering&& other) = delete;
	GameRendering& operator=(const GameRendering& other) = delete;
	GameRendering& operator=(GameRendering&& other) = delete;

	Window* createWindow(char* title, int x, int y, int width, int height, uint32_t flags) override;
	void RegisterWindowCallback(Window* window, std::function<void()> function) override;

	//NOTE: Only call this function from Window class
	void RemoveWindow(Window* window) override;

	void Render() override;
	void ParseWindowEvent(SDL_WindowEvent& e) override;

private:
	Window* _activeWindow;
	std::function<void()> _closeWindowCallback;
};

#endif