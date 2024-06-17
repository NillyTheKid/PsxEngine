#include "Exceptions.h"

class Component;

template<typename T>
unsigned short GetComponentId()
{
	static_cast<Component*>((T*)0);
	throw ComponentIdException();
	return -1;
}

#define RegisterComponent(ComponentType) \
	template<> \
	unsigned short GetComponentId<ComponentType>() \
	{ \
		static_cast<Component*>((ComponentType*)0); \
		return __COUNTER__; \
	}