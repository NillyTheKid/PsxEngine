#ifndef COMPONENT
#define COMPONENT

class Component
{
public:
	Component();
	~Component();
	Component(const Component& other) = delete;
	Component operator=(const Component& other) = delete;
	Component(Component&& other) = delete;
	Component operator=(Component&& other) = delete;

private:
};

#endif