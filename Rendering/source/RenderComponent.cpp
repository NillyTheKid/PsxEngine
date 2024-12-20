#include "RenderComponent.h"

DefineGetComponentId(RenderComponent)
static const unsigned short typeId = GetComponentId<RenderComponent>();

RenderComponent::RenderComponent()
	:Component(typeId)
	,_window{0}
{
}

RenderComponent::~RenderComponent()
{
}

RenderComponent::RenderComponent(const RenderComponent& other)
	:Component(typeId)
	,_window{other._window}
{
}

RenderComponent* RenderComponent::Clone()
{
	return new RenderComponent(*this);
}
