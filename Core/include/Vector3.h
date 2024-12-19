#ifndef VECTOR3
#define VECTOR3

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3(const Vector3& other);
	Vector3& operator=(const Vector3& other);
	Vector3(Vector3&& other);
	Vector3& operator=(Vector3&& other);

	float GetX() const;
	float GetY() const;
	float GetZ() const;

private:
	float _x, _y, _z;
};

#endif