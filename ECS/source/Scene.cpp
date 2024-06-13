#include "Scene.h"
#include "Entity.h"

namespace {
	static std::uint16_t nrScenes = 0;
}

Scene::Scene()
	:_pEntities{}
	,_id{nrScenes++}
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