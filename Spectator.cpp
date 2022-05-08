#include "Header.h"
#include "Functions.h"
#include "Spectator.h"

void Spectator::set_position(const double x, const double y, const double z)
{
	Vector3d tmp(x, y, z);

	position = tmp;
}

void Spectator::set_dist_spec_screen(const double v)
{
	if (Less(v, 0.0, true))
	{
		throw std::runtime_error("All distances must be positive.\n");
	}
	dist_spec_screen_ = v;
}
void Spectator::set_dist_screen_scene(const double v)
{

	if (Less(v, 0.0, true))
	{
		throw std::runtime_error("All distances must be positive.\n");
	}
	
	dist_screen_scene_ = v;
}
void Spectator::set_angle_of_view(const double v)
{
	
	if (Less(v, 0.0, true) || Greater(v, 180.0, true))
	{
		throw std::runtime_error("Uncorrect viewing angle boundaries.\n");
	}

	angle_of_view_ = v;
}

Vector3d Spectator::get_position(void)
{
	return position;
}

double Spectator::get_dist_spec_screen(void)
{
	return dist_spec_screen_;
}
double Spectator::get_dist_screen_scene(void)
{
	return dist_screen_scene_;
}
double Spectator::get_angle_of_view(void)
{
	return angle_of_view_;
}
