#pragma once

#include "Header.h"
#include "Figure.h"
#include "Vector3d.h"

class Tetrahedron : public Figure
{
private:
	Vector3d first_vertex;
	Vector3d second_vertex;
	Vector3d third_vertex;
	Vector3d fourth_vertex;

public:

	Tetrahedron( double,  double,  double,  double,  double,  double,  double,  double,  double,  double,  double,  double);

	bool ray_intersect(Vector3d, Vector3d) override;

	Vector3d ret_normal(Vector3d) override;
	Vector3d ret_point(Vector3d, Vector3d) override;
	Vector3d return_centroid(void) override;

	void set_color(const int) override;
	int get_color(void) override;
};
