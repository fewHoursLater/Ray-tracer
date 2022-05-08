#pragma once

#include "Header.h"
#include "Figure.h"
#include "Vector3d.h"

class Sphere : public Figure
{
private:

	Vector3d center;

	double x_;
	double y_;
	double z_;

	double R_;

public:
	Sphere(const double, const double, const double, const double);
	
	void set_x(const double);
	void set_y(const double);
	void set_z(const double);
	void set_R(const double);

	bool ray_intersect(Vector3d, Vector3d) override;
	Vector3d ret_point(Vector3d, Vector3d) override;
	Vector3d ret_normal(Vector3d) override;
	Vector3d return_centroid(void) override;

	void set_color(const int) override;
	int get_color(void) override;

	double get_x(void);
	double get_y(void);
	double get_z(void);
	double get_R(void);
};
