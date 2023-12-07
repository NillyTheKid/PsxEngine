#ifndef CORE
#define CORE
class Rendering;

union SDL_Event;

class Core
{
public:
	Core();
	~Core();
	Core(const Core& other) = delete;
	Core(Core&& other) = delete;
	Core& operator=(const Core& other) = delete;
	Core& operator=(Core&& other) = delete;

	void Run();

	Rendering* CreateRenderer();

public:
	void Quit();

private:
	void ParseEvent(SDL_Event& e);
private:
	Rendering* _rendering;

	bool _isRunning;
};

#endif