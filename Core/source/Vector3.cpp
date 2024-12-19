#include "Vector3.h"

Vector3::Vector3()
	:_x{0} ,_y{0}, _z{0}
{
}
Vector3::Vector3(float x, float y, float z)
	:_x{x} ,_y{y} ,_z{z}
{
}
Vector3::~Vector3()
{
}

Vector3::Vector3(const Vector3& other)
	:_x{other._x} ,_y{other._y} ,_z{other._z}
{
}
Vector3& Vector3::operator=(const Vector3& other)
{
	return Vector3(other);
}
Vector3::Vector3(Vector3&& other)
	:_x{other._x} ,_y{other._y} ,_z{other._z}
{
}
Vector3& Vector3::operator=(Vector3&& other)
{
	return Vector3(other);
}

float Vector3::GetX() const
{
	return _x;
}
float Vector3::GetY() const
{
	return _y;
}
float Vector3::GetZ() const
{
	return _z;
}