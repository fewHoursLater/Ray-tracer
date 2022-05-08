#include "Header.h"
#include "Vector3d.h"

Vector3d::Vector3d()
{

}

Vector3d::Vector3d(const double v1, const double v2, const double v3)
{
	vec1_ = v1;
	vec2_ = v2;
	vec3_ = v3;
}

Vector3d::Vector3d(const Vector3d& other)
{
	this->vec1_ = other.vec1_;
	this->vec2_ = other.vec2_;
	this->vec3_ = other.vec3_;
}

Vector3d& Vector3d::operator=(const Vector3d& other)
{
	this->vec1_ = other.vec1_;
	this->vec2_ = other.vec2_;
	this->vec3_ = other.vec3_;

	return *this;
}

Vector3d Vector3d::operator+(const Vector3d& other)
{
	Vector3d rez(this->vec1_ + other.vec1_, this->vec2_ + other.vec2_, this->vec3_ + other.vec3_);
	return rez;
}

Vector3d Vector3d::operator-(const Vector3d& other)
{
	Vector3d rez(this->vec1_ - other.vec1_, this->vec2_ - other.vec2_, this->vec3_ - other.vec3_);
	return rez;
}

Vector3d Vector3d::operator*(const double& value)
{
	Vector3d rez(value * this->get_v1(), value * this->get_v2(), value * this->get_v3());

	return rez;
}

Vector3d Vector3d::operator/(const double& value)
{
	Vector3d rez(this->get_v1() / value, this->get_v2() / value, this->get_v3() / value);

	return rez;
}


double Vector3d::operator^(const Vector3d& other)
{

	double cos_angle = (this->get_v1() * other.vec1_ + this->get_v2() * other.vec2_ + this->get_v3() * other.vec3_) / (this->magnitude() * (sqrt(other.vec1_ * other.vec1_ + other.vec2_ * other.vec2_ + other.vec3_ * other.vec3_))		);

	double angle = (180.0 * acos(cos_angle) / Pi);

	return angle;

}


Vector3d Vector3d::V_product(const Vector3d& other)
{
	Vector3d rez(vec2_ * other.vec3_ - vec3_ * other.vec2_, vec3_ * other.vec1_ - vec1_ * other.vec3_, vec1_ * other.vec2_ - vec2_ * other.vec1_);

	return rez;
}

double Vector3d::D_product(const Vector3d& other)
{
	double dot_product = this->vec1_ * other.vec1_ + this->vec2_ * other.vec2_ + this->vec3_ * other.vec3_;

	return dot_product;
}



double Vector3d::get_v1(void)
{
	return vec1_;
}

double Vector3d::get_v2(void)
{
	return vec2_;
}

double Vector3d::get_v3(void)
{
	return vec3_;
}


void Vector3d::normalize(void)
{
	double tmp = this->magnitude();

	vec1_ = vec1_ / tmp;
	vec2_ = vec2_ / tmp;
	vec3_ = vec3_ / tmp;
}

double Vector3d::magnitude(void)
{
	return sqrt(vec1_ * vec1_ + vec2_ * vec2_ + vec3_ * vec3_);
}

Vector3d::~Vector3d()
{

}