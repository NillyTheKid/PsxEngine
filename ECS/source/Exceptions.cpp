#include "Exceptions.h"
#include <string>
#include <iostream>

LoadException::LoadException(LoadType type, std::uint32_t id)
	:_type{type}
	,_id{id}
{
}

LoadException::~LoadException()
{
}

LoadException::LoadException(const LoadException& other)
	:_type{other._type}
	,_id{other._id}
{
}

LoadException LoadException::operator=(const LoadException& other)
{
	return LoadException(other._type, other._id);
}

LoadException::LoadException(LoadException&& other)
	:_type{other._type}
	,_id{other._id}
{
}

LoadException LoadException::operator=(LoadException&& other)
{
	return LoadException(other._type, other._id);
}

const char* LoadException::what() const
{
	switch (_type)
	{
	case LoadType::Scene:
	{
		return (std::string("Failed to load Scene with ID: ") + std::to_string(_id) + "\n").c_str();
		break;
	}
	default:
	{
		return "Failed to load unknown type\n";
	}
	}
}
