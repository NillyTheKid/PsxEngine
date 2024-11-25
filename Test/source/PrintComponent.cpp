#include "PrintComponent.h"
//#include "ComponentId.h"

//RegisterComponent(TestComponent)
DefineGetComponentId(PrintComponent)
static const unsigned short typeId = GetComponentId<PrintComponent>();

PrintComponent::PrintComponent()
	:Component(typeId)
{

}

PrintComponent::~PrintComponent()
{

}

PrintComponent::PrintComponent(const PrintComponent& other)
	:Component(typeId)
{
}

PrintComponent* PrintComponent::Clone()
{
	return new PrintComponent(*this);
}
