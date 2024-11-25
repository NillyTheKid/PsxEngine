#ifndef TEST_SYSTEM
#define TEST_SYSTEM
#include "System.h"

class TestSystem : public System
{
public:
	TestSystem();
	~TestSystem() override;

	TestSystem(const TestSystem& other) = delete;
	TestSystem operator=(const TestSystem& other) = delete;
	TestSystem(TestSystem&& other) = delete;
	TestSystem operator=(TestSystem&& other) = delete;

private:
};

#endif