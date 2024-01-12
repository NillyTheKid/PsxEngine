#ifndef ENGINE
#define ENGINE
class Rendering;

union SDL_Event;

class Engine
{
public:
	Engine();
	~Engine();
	Engine(const Engine& other) = delete;
	Engine(Engine&& other) = delete;
	Engine& operator=(const Engine& other) = delete;
	Engine& operator=(Engine&& other) = delete;

	void Run();

	Rendering* CreateRenderer(bool isGameRenderer = true);

public:
	void Quit();

private:
	void ParseEvent(SDL_Event& e);
private:
	Rendering* _rendering;

	bool _isRunning;
};

#endif