#ifndef SYSTEM
#define SYSTEM

#include <vector>

class System
{
public:
	System(std::vector<std::uint16_t> requiredCompTypes);
	virtual ~System();
	System(const System& other) = delete;
	System operator=(const System& other) = delete;
	System(System&& other) = delete;
	System operator=(System&& other) = delete;

private:
	std::vector<std::uint16_t> _requiredCompTypes;
};

#endif