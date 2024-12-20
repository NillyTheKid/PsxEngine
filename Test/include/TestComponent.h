#ifndef TEST_COMPONENT
#define TEST_COMPONENT
#include "Component.h"
#include "ComponentId.h"

class TestComponent : public Component
{
public:
	TestComponent();
	~TestComponent() override;

	TestComponent(const TestComponent& other);
	TestComponent operator=(const TestComponent& other) = delete;
	TestComponent(TestComponent&& other) = delete;
	TestComponent operator=(TestComponent&& other) = delete;

	TestComponent* Clone() override;

	void SetData(int data);
	int GetData() const;

private:
	//static const unsigned short _typeId = GetComponentId<TestComponent>();
	int _data;
};

RegisterComponent(TestComponent,2)

#endif