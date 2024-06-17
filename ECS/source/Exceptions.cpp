#include "Exceptions.h"
#include <string>
#include <iostream>

LoadException::LoadException(LoadType type, std::uint32_t id)
{
	ConstructMessage(type, id);
}

LoadException::LoadException(std::string message)
	:_message{message}
{

}


LoadException::~LoadException()
{
}

LoadException::LoadException(const LoadException& other)
	:_message{ other._message }
{
}

LoadException LoadException::operator=(const LoadException& other)
{
	return LoadException(other._message);
}

LoadException::LoadException(LoadException&& other) noexcept
	:_message{ other._message }
{
}

LoadException LoadException::operator=(LoadException&& other) noexcept
{
	return LoadException(other._message);
}

const char* LoadException::what() const
{
	return _message.c_str();
}

void LoadException::ConstructMessage(LoadType type, std::uint32_t id)
{
	switch (type)
	{
	case LoadType::Scene:
	{
		_message = "Failed to load Scene with ID: " + std::to_string(id) + "\n";
		break;
	}
	default:
	{
		_message = "Failed to load unknown type\n";
	}
	}
}

ComponentIdException::ComponentIdException()
{
}

const char* ComponentIdException::what() const
{
	return "Attempted to use a component without registering it!!";
}
