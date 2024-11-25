#include "System.h"

System::System(std::vector<std::uint16_t> requiredCompTypes)
	:_requiredCompTypes{requiredCompTypes}
	,_entities{}
	,_pComponents{}
{
	for (int i = 0; i < _requiredCompTypes.size(); i++)
	{
		_pComponents.push_back(std::vector<Component*>());
	}
}
System::~System()
{

}