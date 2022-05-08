#pragma once

#include "Header.h"
#include "Vector3d.h"

class Screen
{
private:

	Vector3d center_of_screen;
	Vector3d normal;
	Vector3d up;
	Vector3d tangent;

	int width_;
	int height_;

public:


	void set_center_of_screen(const double, const double, const double);
	void set_normal_to_screen(const double, const double, const double);
	void set_up_direction_on_screen(const double, const double, const double);

	void set_width(const int);
	void set_height(const int);

	Vector3d get_center_of_screen(void);
	Vector3d get_normal_to_screen(void);
	Vector3d get_up_direction_on_screen(void);
	Vector3d get_tangent_on_screen(void);
	
	void create_tangent_on_screen(void);

	int get_width(void);
	int get_height(void);

	
};
