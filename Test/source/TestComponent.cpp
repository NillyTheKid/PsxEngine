#include "TestComponent.h"
#include "ComponentId.h"

RegisterComponent(TestComponent)
static const unsigned short typeId = GetComponentId<TestComponent>();

TestComponent::TestComponent()
	:_data{0}
	,Component(typeId)
{

}

TestComponent::~TestComponent()
{

}

void TestComponent::SetData(int data)
{
	_data = data;
}
