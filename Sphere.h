#pragma once

#include "Header.h"
#include "Vector_3_float.h"

class Sphere : public Figure
{
private:

	float x_;
	float y_;
	float z_;

	float R_;

public:
	Sphere();
	Sphere(const float, const float, const float, const float);
	~Sphere();

	void set_x(const float);
	void set_y(const float);
	void set_z(const float);
	void set_R(const float);

	bool ray_intersect(const float, const float, const float, const float, const float, const float) override;
	Vector_3_float ret_point(const float, const float, const float, const float, const float, const float) override;
	Vector_3_float ret_normal(const float, const float, const float) override;
	Vector_3_float return_centroid() override;

	void set_color(int) override;
	int get_color() override;

	float get_x(void);
	float get_y(void);
	float get_z(void);
	float get_R(void);
};
