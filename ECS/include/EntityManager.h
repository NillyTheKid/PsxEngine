#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

#include <queue>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	EntityManager(const EntityManager& other) = delete;
	EntityManager operator=(const EntityManager& other) = delete;
	EntityManager(EntityManager&& other) = delete;
	EntityManager operator=(EntityManager&& other) = delete;

	std::uint32_t CreateEntity();
	void DeleteEntity(std::uint32_t id);

private:
	std::queue<std::uint32_t> _unusedIds;
};

#endif