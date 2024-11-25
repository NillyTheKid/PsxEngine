#include "TestSystem.h"

#include "TestComponent.h"

TestSystem::TestSystem()
	:System(std::vector<std::uint16_t>({ GetComponentId<TestComponent>() }))
{
}

TestSystem::~TestSystem()
{
}