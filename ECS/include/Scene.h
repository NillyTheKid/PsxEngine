#ifndef SCENE
#define SCENE
#include <vector>

class Entity;

class Scene
{
public:
	Scene();
	~Scene();
	Scene(const Scene& other) = delete;
	Scene operator=(const Scene& other) = delete;
	Scene(Scene&& other) = delete;
	Scene operator=(Scene&& other) = delete;

	Entity* CreateEntity();

private:
	std::uint16_t _id;
	std::vector<Entity*> _pEntities;
};

#endif