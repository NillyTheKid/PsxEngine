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
	_pComponents.clear();
}

void System::CheckAddEntity(const System::EntityToAdd& entityToAdd)
{
	std::vector<Component*> compsToAdd{};
	for (std::uint16_t compType : _requiredCompTypes)
	{
		bool found = false;
		for (System::EntityToAdd::ComponentToAdd comp : entityToAdd.comps)
		{
			if (comp.type == compType)
			{
				compsToAdd.push_back(comp.comp);
				found = true;
				break;
			}
		}

		if (!found)
		{
			return;
		}
	}

	//If we make it here we can add
	_ASSERT(_requiredCompTypes.size() == compsToAdd.size());
	_entities.push_back(entityToAdd.entity);
	for (int i = 0; i < compsToAdd.size(); i++)
	{
		_pComponents[i].push_back(compsToAdd[i]);
	}
}
