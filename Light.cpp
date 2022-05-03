#include "Header.h"
#include "Light.h"

Light::Light()
{
	x_ = 0.;
	y_ = 0.;
	z_ = 0.;
}

void Light::set_x(const float x)
{
	x_ = x;
}
void Light::set_y(const float y)
{
	y_ = y;
}
void Light::set_z(const float z)
{
	z_ = z;
}

float Light::get_x()
{
	return x_;
}

float Light::get_y()
{
	return y_;
}

float Light::get_z()
{
	return z_;
}


Light::~Light()
{
}