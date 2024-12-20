#ifndef RENDER_COMPONENT
#define RENDER_COMPONENT
#include "Component.h"
#include "ComponentId.h"

class RenderComponent : public Component
{
public:
	RenderComponent();
	~RenderComponent() override;

	RenderComponent(const RenderComponent& other);
	RenderComponent operator=(const RenderComponent& other) = delete;
	RenderComponent(RenderComponent&& other) = delete;
	RenderComponent operator=(RenderComponent&& other) = delete;

	RenderComponent* Clone() override;

private:
	uint8_t _window;
};

RegisterComponent(RenderComponent, 1)

#endif