#pragma once

#include "Header.h"

class Screen
{
private:

	float x_;
	float y_;
	float z_;

	float normal[3];
	float up[3];
	float tangent[3];

	int width_;
	int height_;

public:
	Screen();
	~Screen();

	void set_x(const float);
	void set_y(const float);
	void set_z(const float);

	void set_norm_x(const float);
	void set_norm_y(const float);
	void set_norm_z(const float);

	void set_up_x(const float);
	void set_up_y(const float);
	void set_up_z(const float);

	void set_width(const int);
	void set_height(const int);

	float get_x(void);
	float get_y(void);
	float get_z(void);

	float get_norm_x(void);
	float get_norm_y(void);
	float get_norm_z(void);

	float get_up_x(void);
	float get_up_y(void);
	float get_up_z(void);

	int get_width(void);
	int get_height(void);

	void tangent_(void);

	float get_tangent_x(void);
	float get_tangent_y(void);
	float get_tangent_z(void);
};
