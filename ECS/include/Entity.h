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

	template<class T> T* CreateComponent()
	{
		T* result = new T();
		_pComponents.push_back(static_cast<Component*>(result));

		return result;
	}

private:
	std::vector<Component*> _pComponents;
};

#endif