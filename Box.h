#pragma once

#include "Header.h"
#include "Figure.h"
#include "Vector3d.h"

class Box : public Figure
{
private:
	Vector3d begin;
	Vector3d end;

public:
	
	Box() = default;
	Box(const double, const double, const double, const double, const double, const double);

	bool ray_intersect(Vector3d, Vector3d) override;
	Vector3d ret_point(Vector3d, Vector3d) override;
	Vector3d ret_normal(Vector3d) override;
	Vector3d return_centroid() override;

	void set_color(int) override;
	int get_color() override;


};