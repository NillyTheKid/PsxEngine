#ifndef ENGINE
#define ENGINE
class Rendering;
class Input;

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
	Input* CreateInput();

public:
	void Quit();

private:
	void ParseEvent(SDL_Event& e);
private:
	Rendering* _rendering;
	Input* _input;

	bool _isRunning;
};

#endif