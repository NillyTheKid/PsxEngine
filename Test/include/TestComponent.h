#ifndef TEST_COMPONENT
#define TEST_COMPONENT
#include "Component.h"

class TestComponent : public Component
{
public:
	TestComponent();
	~TestComponent() override;

	TestComponent(const TestComponent& other) = delete;
	TestComponent operator=(const TestComponent& other) = delete;
	TestComponent(TestComponent&& other) = delete;
	TestComponent operator=(TestComponent&& other) = delete;

	void SetData(int data);

private:
	int _data;
};

#endif