#ifndef COMPONENT_MANAGER
#define COMPONENT_MANAGER
#include <vector>

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
	std::vector<std::uint32_t> _entityComponentMap;
	std::vector<Component*> _pComponents;
};

#endif