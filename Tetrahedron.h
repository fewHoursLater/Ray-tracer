#pragma once

#include "Header.h"
#include "Vector_3_float.h"

class Tetrahedron : public Figure
{
private:

	Vector_3_float first_vertex;
	Vector_3_float second_vertex;
	Vector_3_float third_vertex;
	Vector_3_float fourth_vertex;
	Vector_3_float Normal_;
	Vector_3_float Point_;

public:

	Tetrahedron(const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
	~Tetrahedron();

	bool ray_intersect(const float, const float, const float, const float, const float, const float) override;

	Vector_3_float ret_point(const float, const float, const float, const float, const float, const float) override;
	Vector_3_float ret_normal(const float, const float, const float) override;
	Vector_3_float return_centroid() override;

	friend bool Triangle_intersection(const float, const float, const float, const float, const float, const float, Vector_3_float, Vector_3_float, Vector_3_float);
	friend float return_param(const float, const float, const float, const float, const float, const float, Vector_3_float, Vector_3_float, Vector_3_float);

	void set_color(int) override;
	int get_color() override;
};
