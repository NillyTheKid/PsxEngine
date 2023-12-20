#ifndef RENDERING_STRUCTS
#define RENDERING_STRUCTS

struct Colour
{
	Colour();
	Colour(float r, float g, float b, float a);

	float r, g, b, a;
};

#endif