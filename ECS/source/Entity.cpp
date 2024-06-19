#include "Entity.h"
#include "Component.h"

Entity::Entity()
	:_pComponents{}
{

}
Entity::~Entity()
{
	for (int i = 0; i < _pComponents.size(); i++)
	{
		delete _pComponents[i];
	}

	_pComponents.clear();
}

std::vector<Component*> Entity::GetComponents() const
{
	return _pComponents;
}

//template<class T> T* Entity::CreateComponent()
//{
//	T* result = new T();
//	_pComponents.push_back(static_cast<Component*>(result));
//
//	return result;
//}