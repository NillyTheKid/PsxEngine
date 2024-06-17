#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>
#include <string>

class LoadException : public std::exception
{
public:
	enum class LoadType
	{
		Scene = 0
	};

public:
	LoadException(LoadType type, std::uint32_t id);
	~LoadException() override;
	LoadException(const LoadException& other);
	LoadException operator=(const LoadException& other);
	LoadException(LoadException&& other) noexcept;
	LoadException operator=(LoadException&& other) noexcept;

	const char* what() const override;

private:
	LoadException(std::string message);
	void ConstructMessage(LoadType type, std::uint32_t id);

	std::string _message;
};

class ComponentIdException : public std::exception
{
public:
	ComponentIdException();

	const char* what() const override;

private:
};

#endif