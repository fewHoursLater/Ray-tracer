#pragma once

#include "Header.h"
#include "Vector3d.h"

class Figure
{
protected:

	int color_ = 0;

public:
	
	virtual bool ray_intersect(Vector3d, Vector3d) = 0;
	virtual Vector3d ret_point(Vector3d, Vector3d) = 0;
	virtual Vector3d ret_normal(Vector3d) = 0;
	virtual Vector3d return_centroid() = 0;

	virtual void set_color(int) = 0;
	virtual int get_color() = 0;

};
