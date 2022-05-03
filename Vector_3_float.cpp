#include "Header.h"
#include "Vector_3_float.h"

Vector_3_float::Vector_3_float()
{
	vec1_ = 1.0;
	vec2_ = 1.0;
	vec3_ = 1.0;
}

Vector_3_float::Vector_3_float(const float v1, const float v2, const float v3)
{
	vec1_ = v1;
	vec2_ = v2;
	vec3_ = v3;
}

Vector_3_float::Vector_3_float(const Vector_3_float& other)
{
	this->vec1_ = other.vec1_;
	this->vec2_ = other.vec2_;
	this->vec3_ = other.vec3_;
}

Vector_3_float& Vector_3_float::operator=(const Vector_3_float& other)
{
	this->vec1_ = other.vec1_;
	this->vec2_ = other.vec2_;
	this->vec3_ = other.vec3_;

	return *this;
}

Vector_3_float Vector_3_float::operator+(const Vector_3_float& other)
{
	Vector_3_float rez(this->vec1_ + other.vec1_, this->vec2_ + other.vec2_, this->vec3_ + other.vec3_);
	return rez;
}

Vector_3_float Vector_3_float::operator-(const Vector_3_float& other)
{
	Vector_3_float rez(this->vec1_ - other.vec1_, this->vec2_ - other.vec2_, this->vec3_ - other.vec3_);
	return rez;
}

Vector_3_float Vector_3_float::operator*(const float& value)
{

	Vector_3_float rez(value * this->get_v1(), value * this->get_v2(), value * this->get_v3());

	return rez;
}

Vector_3_float Vector_3_float::operator/(const float& value)
{
	Vector_3_float rez(this->get_v1() / value, this->get_v2() / value, this->get_v3() / value);

	return rez;
}


float Vector_3_float::operator^(const Vector_3_float& other)
{
	float cos_angle = (this->get_v1() * other.vec1_ + this->get_v2() * other.vec2_ + this->get_v3() * other.vec3_) / (this->magnitude() * (sqrtf(other.vec1_ * other.vec1_ + other.vec2_ * other.vec2_ + other.vec3_ * other.vec3_)));

	float angle = (180.0f * acos(cos_angle) / Pi);

	return angle;

}


Vector_3_float Vector_3_float::V_product(const Vector_3_float& other)
{
	Vector_3_float rez(vec2_ * other.vec3_ - vec3_ * other.vec2_, vec3_ * other.vec1_ - vec1_ * other.vec3_, vec1_ * other.vec2_ - vec2_ * other.vec1_);

	float tmp = vec2_ * other.vec3_ - vec3_ * other.vec2_;


	return rez;
}

float Vector_3_float::D_product(const Vector_3_float& other)
{
	float dot_product = this->vec1_ * other.vec1_ + this->vec2_ * other.vec2_ + this->vec3_ * other.vec3_;

	return dot_product;
}



float Vector_3_float::get_v1(void)
{
	return vec1_;
}

float Vector_3_float::get_v2(void)
{
	return vec2_;
}

float Vector_3_float::get_v3(void)
{
	return vec3_;
}


void Vector_3_float::normalize(void)
{
	float tmp = this->magnitude();

	vec1_ = vec1_ / tmp;
	vec2_ = vec2_ / tmp;
	vec3_ = vec3_ / tmp;
}

float Vector_3_float::magnitude(void)
{
	return sqrtf(vec1_ * vec1_ + vec2_ * vec2_ + vec3_ * vec3_);
}

Vector_3_float::~Vector_3_float()
{
}