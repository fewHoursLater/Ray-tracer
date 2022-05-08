#include "Header.h"
#include "Vector3d.h"
#include "Light.h"


void Light::set_position(const double x, const double y, const double z)
{
	Vector3d tmp(x, y, z);

	position = tmp;
}

Vector3d Light::get_position(void)
{
	return position;
}