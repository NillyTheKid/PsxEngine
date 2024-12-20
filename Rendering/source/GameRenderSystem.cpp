#include "GameRenderSystem.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

GameRenderSystem::GameRenderSystem()
	:System(std::vector<std::uint16_t>({ GetComponentId<TransformComponent>(), GetComponentId<RenderComponent>()}))
{
}

GameRenderSystem::~GameRenderSystem()
{
}

void GameRenderSystem::Update(const float& deltaTime, const std::vector<Component*>& pComps)
{
}
