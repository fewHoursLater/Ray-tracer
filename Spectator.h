#pragma once

#include "Header.h"


class Spectator
{
private:
	float x_;
	float y_;
	float z_;

	float dist_spec_screen_;
	float dist_spec_scene_;
	float angle_of_view_;

public:
	Spectator();

	~Spectator();

	void set_x(const float);
	void set_y(const float);
	void set_z(const float);

	void set_dist_spec_screen(const float);
	void set_dist_spec_scene(const float);
	void set_angle_of_view(const float);

	float get_x(void);
	float get_y(void);
	float get_z(void);

	float get_dist_spec_screen(void);
	float get_dist_spec_scene(void);
	float get_angle_of_view(void);
};
