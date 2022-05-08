#pragma once

#include "Header.h"
#include "Vector3d.h"


class Spectator
{
private:
	
	Vector3d position;

	double dist_spec_screen_;
	double dist_screen_scene_;
	double angle_of_view_;

public:

	void set_position(const double, const double, const double);

	void set_dist_spec_screen(const double);
	void set_dist_screen_scene(const double);
	void set_angle_of_view(const double);

	Vector3d get_position(void);

	double get_dist_spec_screen(void);
	double get_dist_screen_scene(void);
	double get_angle_of_view(void);
};
