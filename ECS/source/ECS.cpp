#include "ECS.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Scene.h"
#include "ComponentManager.h"
#include "Exceptions.h"
#include "Component.h"
#include "ComponentId.h"
#include "System.h"

namespace
{

}

ECS::ECS()
	:_loadedScenes{}
	,_pEntityManager{new EntityManager()}
	,_compManagers{}
	,_pSystems{}
{

}
ECS::~ECS()
{
	//Delete all remaining scenes?

	for (auto it = _compManagers.begin(); it != _compManagers.end(); it++)
	{
		delete it->second;
	}

	delete _pEntityManager;
}

std::uint16_t ECS::LoadScene(const Scene& scene)
{
	std::uint16_t sceneId = scene.GetId();

	//Check to see that scene isnt already loaded
	if (_loadedScenes.find(sceneId) == _loadedScenes.end())
	{
		auto entitiesToload = scene.GetEntities();
		std::vector<std::uint32_t> loadedEntities{};

		for (int i = 0; i < entitiesToload.size(); i++)
		{
			std::uint32_t newEntity = _pEntityManager->CreateEntity();
			auto compsToLoad = entitiesToload[i]->GetComponents();

			for (int j = 0; j < compsToLoad.size(); j++)
			{
				//check if compManager exists for this type of component
				auto compManager = _compManagers[compsToLoad[j]->GetTypeId()];
				if (compManager == nullptr)
				{
					compManager = _compManagers[compsToLoad[j]->GetTypeId()] = new ComponentManager();
				}
				Component* loadedComp = compManager->LoadComponent(newEntity, compsToLoad[j]);
			}

			loadedEntities.push_back(newEntity);
		}

		_loadedScenes.emplace(sceneId, loadedEntities);
	}
	else
	{
		throw LoadException(LoadException::LoadType::Scene, std::uint32_t(sceneId));
	}

	return sceneId;
}

void ECS::UnloadScene(std::uint16_t id)
{
	auto entitiesToRemove = _loadedScenes[id];
	std::vector<std::uint32_t> removedEntities{};

	for (int i = 0; i < entitiesToRemove.size(); i++)
	{
		_pEntityManager->DeleteEntity(entitiesToRemove[i]);
		removedEntities.push_back(entitiesToRemove[i]);
	}

	for (auto it = _compManagers.begin(); it != _compManagers.end(); it++)
	{
		it->second->UnloadComponents(removedEntities);
	}

	_loadedScenes.erase(id);
}
