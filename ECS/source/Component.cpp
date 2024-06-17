#include "Component.h"

Component::Component(unsigned short typeId)
	:_typeId{typeId}
{

}
Component::~Component()
{

}

unsigned short Component::GetTypeId() const
{
	return _typeId;
}
