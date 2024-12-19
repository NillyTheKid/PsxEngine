#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT
#include "Component.h"
#include "ComponentId.h"

//class Vector3;

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent() override;

	TransformComponent(const TransformComponent& other);
	TransformComponent operator=(const TransformComponent& other) = delete;
	TransformComponent(TransformComponent&& other) = delete;
	TransformComponent operator=(TransformComponent&& other) = delete;

	TransformComponent* Clone() override;

private:
	float _posX, _posY, _posZ;
};

RegisterComponent(TransformComponent, 0)

#endif