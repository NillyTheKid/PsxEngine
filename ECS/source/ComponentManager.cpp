#include "ComponentManager.h"
#include "Component.h"
#include <unordered_set>

namespace {
}

ComponentManager::ComponentManager()
	:_entityComponentMap{}
	,_pComponents{}
{
}
ComponentManager::~ComponentManager()
{
	for (int i = 0; i < _pComponents.size(); i++)
	{
		delete _pComponents[i];
	}
}

Component* ComponentManager::LoadComponent(std::uint32_t entity, Component* pComp)
{
	_pComponents.push_back(pComp->Clone());
	_entityComponentMap.push_back(entity);
	return _pComponents.back();
}

void ComponentManager::UnloadComponents(const std::vector<std::uint32_t>& entities)
{
	std::unordered_set<std::uint32_t> entitiesSet{ entities.begin(), entities.end() };

	for (int i = 0; i < _entityComponentMap.size(); i++)
	{
		if (entitiesSet.find(_entityComponentMap[i]) != entitiesSet.end())
		{
			delete _pComponents[i];
			_pComponents.erase(_pComponents.begin() + i); //Turns out you can erase by index, all you have to is increment begin it by index. Pretty cool
			_entityComponentMap.erase(_entityComponentMap.begin() + i);

			i--;
		}
	}
}
