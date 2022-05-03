#include "Header.h"
#include "Spectator.h"

Spectator::Spectator()
{
	x_ = 0.;
	y_ = 0.;
	z_ = 0.;

	dist_spec_screen_ = 5.;
	dist_spec_scene_ = 10.;
	angle_of_view_ = 70.;
}

void Spectator::set_x(const float x)
{
	x_ = x;
}
void Spectator::set_y(const float y)
{
	y_ = y;
}
void Spectator::set_z(const float z)
{
	z_ = z;
}

void Spectator::set_dist_spec_screen(const float v)
{
	dist_spec_screen_ = v;
}
void Spectator::set_dist_spec_scene(const float v)
{
	dist_spec_scene_ = v;
}
void Spectator::set_angle_of_view(const float v)
{
	angle_of_view_ = v;
}

float Spectator::get_x(void)
{
	return x_;
}
float Spectator::get_y(void)
{
	return y_;
}
float Spectator::get_z(void)
{
	return z_;
}

float Spectator::get_dist_spec_screen(void)
{
	return dist_spec_screen_;
}
float Spectator::get_dist_spec_scene(void)
{
	return dist_spec_scene_;
}
float Spectator::get_angle_of_view(void)
{
	return angle_of_view_;
}

Spectator::~Spectator()
{
}