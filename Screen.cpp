#include "Header.h"
#include "Screen.h"

Screen::Screen()
{

	x_ = 0.;
	y_ = 0.;
	z_ = 0.;

	normal[0] = 1.;
	normal[1] = 0.;
	normal[2] = 0.;

	up[0] = 0.;
	up[1] = 0.;
	up[2] = 1.;

	tangent[0] = 0.;
	tangent[1] = 1.;
	tangent[2] = 0.;

	width_ = 500;
	height_ = 500;
}

int Screen::get_width(void)
{
	return width_;
}
int Screen::get_height(void)
{
	return height_;
}

void Screen::tangent_(void)
{
	tangent[0] = up[1] * normal[2] - up[2] * normal[1];
	tangent[1] = up[2] * normal[0] - up[0] * normal[2];
	tangent[2] = up[0] * normal[1] - up[1] * normal[0];
}

float Screen::get_norm_x(void)
{
	return normal[0];
}
float Screen::get_norm_y(void)
{
	return normal[1];
}
float Screen::get_norm_z(void)
{
	return normal[2];
}

float Screen::get_up_x(void)
{
	return up[0];
}
float Screen::get_up_y(void)
{
	return up[1];
}
float Screen::get_up_z(void)
{
	return up[2];
}

float Screen::get_tangent_x(void)
{
	return tangent[0];
}
float Screen::get_tangent_y(void)
{
	return tangent[1];
}
float Screen::get_tangent_z(void)
{
	return tangent[2];
}

float Screen::get_x(void)
{
	return x_;
}
float Screen::get_y(void)
{
	return y_;
}
float Screen::get_z(void)
{
	return z_;
}

void Screen::set_norm_x(const float x)
{
	normal[0] = x;
}
void Screen::set_norm_y(const float y)
{
	normal[1] = y;

}
void Screen::set_norm_z(const float z)
{
	normal[2] = z;
}

void Screen::set_up_x(const float x)
{
	up[0] = x;

}
void Screen::set_up_y(const float y)
{
	up[1] = y;
}
void Screen::set_up_z(const float z)
{
	up[2] = z;
}

void Screen::set_x(const float x)
{
	x_ = x;
}
void Screen::set_y(const float y)
{
	y_ = y;
}
void Screen::set_z(const float z)
{
	z_ = z;
}

void Screen::set_width(const int v)
{

	width_ = v;
}
void Screen::set_height(const int v)
{
	height_ = v;
}

Screen::~Screen()
{
}