#ifndef GAME_RENDER_SYSTEM
#define GAME_RENDER_SYSTEM
#include "System.h"

class GameRenderSystem : public System
{
public:
	GameRenderSystem();
	~GameRenderSystem() override;

	GameRenderSystem(const GameRenderSystem& other) = delete;
	GameRenderSystem& operator=(const GameRenderSystem& other) = delete;
	GameRenderSystem(GameRenderSystem&& other) = delete;
	GameRenderSystem& operator=(GameRenderSystem&& other) = delete;

protected:
	void Update(const float& deltaTime, const std::vector<Component*>& pComps) override;
};

#endif