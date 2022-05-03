#pragma once

#include "Header.h"
#include "Vector_3_float.h"

class Box : public Figure
{
private:
	Vector_3_float begin;
	Vector_3_float end;

public:
	Box();
	Box(const float, const float, const float, const float, const float, const float);
	~Box();

	bool ray_intersect(const float, const float, const float, const float, const float, const float) override;
	Vector_3_float ret_point(const float, const float, const float, const float, const float, const float) override;
	Vector_3_float ret_normal(const float, const float, const float) override;
	Vector_3_float return_centroid() override;

	void set_color(int) override;
	int get_color() override;


};