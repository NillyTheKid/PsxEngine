#include "ECS.h"
#include "EntityManager.h"
#include "Scene.h"
#include "Exceptions.h"

ECS::ECS()
	:_loadedScenes{}
	,_pEntityManager{new EntityManager()}
{

}
ECS::~ECS()
{
	//Delete all remaining scenes?

	delete _pEntityManager;
}

std::uint16_t ECS::LoadScene(const Scene& scene)
{
	std::uint16_t sceneId = scene.GetId();

	if (_loadedScenes.find(sceneId) == _loadedScenes.end())
	{
		auto entitiesToload = scene.GetEntities();
		std::vector<std::uint16_t> loadedEntities{};

		for (int i = 0; i < entitiesToload.size(); i++)
		{
			std::uint16_t newEntity = _pEntityManager->CreateEntity();
			//Load in components to wherever they need to go

			loadedEntities.push_back(newEntity);
		}

		_loadedScenes.emplace(sceneId, loadedEntities);
	}
	else
	{
		throw LoadException(LoadException::LoadType::Scene, sceneId);
	}

	return sceneId;
}

void ECS::UnloadScene(std::uint16_t id)
{
	auto entitiesToRemove = _loadedScenes[id];

	for (int i = 0; i < entitiesToRemove.size(); i++)
	{
		_pEntityManager->DeleteEntity(entitiesToRemove[i]);

		//Remove all components attached to this entity
	}

	_loadedScenes.erase(id);
}
