#pragma once

#include "Header.h"

class Vector3d
{
public:
	Vector3d();
	~Vector3d();
	Vector3d(const double, const double, const double);
	Vector3d(const Vector3d&);
	Vector3d& operator=(const Vector3d&);
	
	Vector3d operator+(const Vector3d&);
	Vector3d operator-(const Vector3d&);
	Vector3d operator*(const double&);
	Vector3d operator/(const double&);
	double operator^(const Vector3d&);

	Vector3d V_product(const Vector3d&);
	double D_product(const Vector3d&);

	void normalize(void);
	double magnitude(void);

	double get_v1(void);
	double get_v2(void);
	double get_v3(void);

private:
	double vec1_;
	double vec2_;
	double vec3_;
};
