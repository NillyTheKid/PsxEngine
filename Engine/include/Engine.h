#ifndef ENGINE
#define ENGINE
class Rendering;
class Input;
class ECS;

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
	ECS* CreateEcs();

public:
	void Quit();

private:
	void ParseEvent(SDL_Event& e);
private:
	Rendering* _rendering;
	Input* _input;
	ECS* _ecs;

	bool _isRunning;
};

#endif