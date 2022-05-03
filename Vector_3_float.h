#pragma once

#include "Header.h"

class Vector_3_float
{
public:
	Vector_3_float();
	Vector_3_float(const float, const float, const float);
	Vector_3_float(const Vector_3_float&);
	Vector_3_float& operator=(const Vector_3_float&);
	~Vector_3_float();

	Vector_3_float operator+(const Vector_3_float&);
	Vector_3_float operator-(const Vector_3_float&);
	Vector_3_float operator*(const float&);
	Vector_3_float operator/(const float&);
	float operator^(const Vector_3_float&);

	Vector_3_float V_product(const Vector_3_float&);
	float D_product(const Vector_3_float&);

	void normalize(void);
	float magnitude(void);

	float get_v1(void);
	float get_v2(void);
	float get_v3(void);

private:
	float vec1_;
	float vec2_;
	float vec3_;
};
