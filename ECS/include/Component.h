#ifndef COMPONENT
#define COMPONENT

class Component
{
public:
	Component(unsigned short typeId);
	virtual ~Component();
	Component(const Component& other) = delete;
	Component operator=(const Component& other) = delete;
	Component(Component&& other) = delete;
	Component operator=(Component&& other) = delete;

	unsigned short GetTypeId() const;

private:
	const unsigned short _typeId;
};

#endif