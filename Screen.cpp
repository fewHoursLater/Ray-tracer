#include "Header.h"
#include "Functions.h"
#include "Screen.h"
#include "Vector3d.h"

void Screen::set_center_of_screen(const double x, const double y, const double z)
{
	Vector3d tmp(x,y,z);

	center_of_screen = tmp;
}

void Screen::set_normal_to_screen(const double x, const double y, const double z)
{
	Vector3d tmp(x, y, z);

	tmp.normalize();

	if (is_equal(tmp.magnitude(), 0.0))
	{
		throw std::runtime_error("The direction of the normal is not defined.\n");
	}
	
	normal = tmp;
}

void Screen::set_up_direction_on_screen(const double x, const double y, const double z)
{
	Vector3d tmp(x, y, z);

	tmp.normalize();
	
	if (is_equal(tmp.magnitude(), 0.0))
	{
		throw std::runtime_error("The upward direction is not defined.\n");
	}

	up = tmp;
}

void Screen::set_width(const int v)
{
	
	if (v <= 0)
	{
		throw std::runtime_error("The width must be positive.\n");
	}

	width_ = v;
}
void Screen::set_height(const int v)
{
	
	if (v <= 0)
	{
		throw std::runtime_error("The height must be positive.\n");
	}

	height_ = v;
}

void Screen::create_tangent_on_screen(void)
{

	Vector3d tmp(normal.get_v2()*up.get_v3()-normal.get_v3()*up.get_v2(),normal.get_v3()*up.get_v1()-normal.get_v1()*up.get_v3(),normal.get_v1()*up.get_v2()-normal.get_v2()*up.get_v1());

	tmp.normalize();

	tangent = tmp;

}

Vector3d Screen::get_center_of_screen(void)
{
	return center_of_screen;
}

Vector3d Screen::get_normal_to_screen(void)
{
	return normal;
}

Vector3d Screen::get_up_direction_on_screen(void)
{
	return up;
}

Vector3d Screen::get_tangent_on_screen(void)
{
	return tangent;
}

int Screen::get_width(void)
{
	return width_;
}
int Screen::get_height(void)
{
	return height_;
}