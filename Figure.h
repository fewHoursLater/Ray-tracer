#pragma once

#include "Header.h"
#include "Vector_3_float.h"

class Figure
{
protected:

	int color;

public:
	Figure();
	~Figure();

	virtual bool ray_intersect(const float, const float, const float, const float, const float, const float) = 0;
	virtual Vector_3_float ret_point(const float, const float, const float, const float, const float, const float) = 0;
	virtual Vector_3_float ret_normal(const float, const float, const float) = 0;
	virtual Vector_3_float return_centroid() = 0;

	virtual void set_color(int) = 0;
	virtual int get_color() = 0;

};
