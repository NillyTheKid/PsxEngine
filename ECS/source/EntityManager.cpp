#include "EntityManager.h"

namespace {
	static std::uint16_t newId = 0;
}

EntityManager::EntityManager()
	:_unusedIds{}
{

}
EntityManager::~EntityManager()
{
}

std::uint16_t EntityManager::CreateEntity()
{
	if (_unusedIds.empty())
	{
		return newId++;
	}

	std::uint16_t result = _unusedIds.front();
	_unusedIds.pop();
	return result;
}

void EntityManager::DeleteEntity(std::uint16_t id)
{
	//TODO?: Remove all components attached to this (or have scene unload also tell comp managers to nuke stuff)
	_unusedIds.push(id);
}
