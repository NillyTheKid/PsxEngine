#include "Scene.h"
#include "Entity.h"

Scene::Scene()
	:_pEntities{}
{

}
Scene::~Scene()
{
	for (int i = 0; i < _pEntities.size(); i++)
	{
		delete _pEntities[i];
	}

	_pEntities.clear();
}

Entity* Scene::CreateEntity()
{
	Entity* result = new Entity();
	_pEntities.push_back(result);

	return result;
}