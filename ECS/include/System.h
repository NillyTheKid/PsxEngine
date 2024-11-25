#ifndef SYSTEM
#define SYSTEM

#include <vector>

class Component;

class System
{
public:
	struct EntityToAdd
	{
		struct ComponentToAdd
		{
			std::uint16_t type;
			Component* comp;
		};

		std::uint32_t entity;
		std::vector<ComponentToAdd> comps;
	};

public:
	System(std::vector<std::uint16_t> requiredCompTypes);
	virtual ~System();
	System(const System& other) = delete;
	System operator=(const System& other) = delete;
	System(System&& other) = delete;
	System operator=(System&& other) = delete;

private:
	std::vector<std::uint16_t> _requiredCompTypes;
	std::vector<std::uint32_t> _entities;
	std::vector<std::vector<Component*>> _pComponents;
};

#endif