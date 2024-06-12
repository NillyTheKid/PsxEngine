#include "TestComponent.h"

TestComponent::TestComponent()
	:_data{0}
{

}

TestComponent::~TestComponent()
{

}

void TestComponent::SetData(int data)
{
	_data = data;
}
