#ifndef ECS_CLASS
#define ECS_CLASS

#include <vector>
#include <map>

class EntityManager;
class Scene;

class ECS
{
public:
	ECS();
	~ECS();
	ECS(const ECS& other) = delete;
	ECS operator=(const ECS& other) = delete;
	ECS(ECS&& other) = delete;
	ECS operator=(ECS&& other) = delete;

	std::uint16_t LoadScene(const Scene& scene);
	void UnloadScene(std::uint16_t id);

private:
	EntityManager* _pEntityManager;

	std::map<std::uint16_t, std::vector<std::uint16_t>> _loadedScenes;
};

#endif