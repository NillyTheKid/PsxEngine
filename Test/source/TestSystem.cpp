#include "TestSystem.h"

#include "TestComponent.h"
#include "PrintComponent.h"

TestSystem::TestSystem()
	:System(std::vector<std::uint16_t>({ GetComponentId<TestComponent>(), GetComponentId<PrintComponent>()}))
{
}

TestSystem::~TestSystem()
{
}