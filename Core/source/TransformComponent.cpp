#include "TransformComponent.h"

DefineGetComponentId(TransformComponent)
static const unsigned short typeId = GetComponentId<TransformComponent>();

TransformComponent::TransformComponent()
	:Component(typeId)
	,_posX{0} ,_posY{0} ,_posZ{0}
{
}

TransformComponent::~TransformComponent()
{
}

TransformComponent::TransformComponent(const TransformComponent& other)
	:Component(typeId)
	,_posX{other._posX} ,_posY{other._posY}, _posZ{other._posZ}
{
}

TransformComponent* TransformComponent::Clone()
{
	return new TransformComponent(*this);
}
