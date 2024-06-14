#ifndef COMPONENT_MANAGER
#define COMPONENT_MANAGER
#include <map>

class Component;

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	ComponentManager(const ComponentManager& other) = delete;
	ComponentManager operator=(const ComponentManager& other) = delete;
	ComponentManager(ComponentManager&& other) = delete;
	ComponentManager operator=(ComponentManager&& other) = delete;

private:
	std::map<std::uint32_t, std::uint32_t> _entityComponentMap;
};

#endif