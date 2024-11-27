#include "TestSystem.h"

#include "TestComponent.h"
#include "PrintComponent.h"

#include <iostream>

TestSystem::TestSystem()
	:System(std::vector<std::uint16_t>({ GetComponentId<TestComponent>(), GetComponentId<PrintComponent>()}))
{
}

TestSystem::~TestSystem()
{
}

void TestSystem::Update(const float& deltaTime, const std::vector<Component*>& pComps)
{
	TestComponent* testComp = (TestComponent*)pComps[0];

	std::cout << "Data: " << testComp->GetData() << "\n";
	std::cout << "DeltaTime: " << deltaTime << "\n";
}
