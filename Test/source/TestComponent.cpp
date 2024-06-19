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

TestComponent::TestComponent(const TestComponent& other)
	:_data{other._data}
	,Component{typeId}
{
}

TestComponent* TestComponent::Clone()
{
	return new TestComponent(*this);
}

void TestComponent::SetData(int data)
{
	_data = data;
}
