#ifndef RENDERING_WINDOW
#define RENDERING_WINDOW
#include "Structs.h"

class SDL_Window;
class Rendering;

class Window
{
public:
	Window(Rendering* rendering, char* title, int x, int y, int width, int height, unsigned int flags);
	~Window();
	Window(const Window& other) = delete;
	Window operator=(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window operator=(Window&& other) = delete;

	void setBackgroundColour(Colour c);

	void StartRendering(void* context);
	void FinishRendering();
	void CloseWindow();

	unsigned int getId() const;
	SDL_Window* getSdlWindow() const;

private:
	Rendering* _pRendering;
	SDL_Window* _pWindow;
	Colour _backgroundColour;
	unsigned int _id;
};

#endif