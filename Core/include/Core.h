#ifndef CORE
#define CORE
class Rendering;

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
private:
	Rendering* _rendering;

	bool _isRunning;
};

#endif