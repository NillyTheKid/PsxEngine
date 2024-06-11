#ifndef SYSTEM
#define SYSTEM

class System
{
public:
	System();
	~System();
	System(const System& other) = delete;
	System operator=(const System& other) = delete;
	System(System&& other) = delete;
	System operator=(System&& other) = delete;

private:
};

#endif