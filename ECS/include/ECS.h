#ifndef ECS_CLASS
#define ECS_CLASS

class ECS
{
public:
	ECS();
	~ECS();
	ECS(const ECS& other) = delete;
	ECS operator=(const ECS& other) = delete;
	ECS(ECS&& other) = delete;
	ECS operator=(ECS&& other) = delete;

private:
};

#endif