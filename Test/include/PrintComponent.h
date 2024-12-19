#ifndef PRINT_COMPONENT
#define PRINT_COMPONENT
#include "Component.h"
#include "ComponentId.h"

class PrintComponent : public Component
{
public:
	PrintComponent();
	~PrintComponent() override;

	PrintComponent(const PrintComponent& other);
	PrintComponent operator=(const PrintComponent& other) = delete;
	PrintComponent(PrintComponent&& other) = delete;
	PrintComponent operator=(PrintComponent&& other) = delete;

	PrintComponent* Clone() override;
private:
	//static const unsigned short _typeId = GetComponentId<TestComponent>();
};

RegisterComponent(PrintComponent,2)

#endif