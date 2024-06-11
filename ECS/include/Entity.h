#ifndef ENTITY
#define ENTITY
#include <vector>

class Component;

class Entity
{
public:
	Entity();
	~Entity();
	Entity(const Entity& other) = delete;
	Entity operator=(const Entity& other) = delete;
	Entity(Entity&& other) = delete;
	Entity operator=(Entity&& other) = delete;

private:
	std::vector<Component> _components;
};

#endif