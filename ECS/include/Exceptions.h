#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>

class LoadException : public std::exception
{
public:
	enum class LoadType
	{
		Scene = 0
	};

public:
	LoadException(LoadType type, std::uint16_t id);
	~LoadException() override;
	LoadException(const LoadException& other);
	LoadException operator=(const LoadException& other);
	LoadException(LoadException&& other);
	LoadException operator=(LoadException&& other);

	const char* what() const override;

private:
	LoadType _type;
	std::uint16_t _id;
};

#endif