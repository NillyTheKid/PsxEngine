#include "Exceptions.h"

class Component;

#ifndef GET_COMPONENT_ID
#define GET_COMPONENT_ID
template<typename T>
constexpr unsigned short GetComponentId()
{
	static_cast<Component*>((T*)0);
	throw ComponentIdException();
	return -1;
}
#endif

#define RegisterComponent(ComponentType, TypeId) \
	template<> \
	constexpr unsigned short GetComponentId<ComponentType>() \
	{ \
		static_cast<Component*>((ComponentType*)0); \
		return TypeId; \
	}

#define DefineGetComponentId(ComponentType) \
	template<> \
	constexpr unsigned short GetComponentId<ComponentType>();