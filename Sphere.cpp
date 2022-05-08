#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Sphere.h"
#include "Vector3d.h"


Sphere::Sphere(const double x, const double y, const double z, const double R)
{
	if (Less(R,0.0,true))
	{
		throw std::runtime_error("The radius must be positive.\n");
	}

	x_ = x;
	y_ = y;
	z_ = z;
	R_ = R;
}

double Sphere::get_x(void)
{
	return x_;
}
double Sphere::get_y(void)
{
	return y_;
}
double Sphere::get_z(void)
{
	return z_;
}
double Sphere::get_R(void)
{
	return R_;
}

bool Sphere::ray_intersect(Vector3d origin, Vector3d direction)  // Луч, выходящий из точки в данном направлении пересекает ли сферу?
{

	double a = (direction.get_v1() * direction.get_v1() + direction.get_v2() * direction.get_v2() + direction.get_v3() * direction.get_v3());
	double b = (2.0 * ((direction.get_v1()) * (origin.get_v1() - x_) + direction.get_v2() * (origin.get_v2() - y_) + direction.get_v3() * (origin.get_v3() - z_)));
	double c = origin.get_v1() * origin.get_v1() + origin.get_v2() * origin.get_v2() + origin.get_v3() * origin.get_v3() + x_ * x_ + y_ * y_ + z_ * z_ - 2.0 * ((origin.get_v1() * x_) + origin.get_v2() * y_ + origin.get_v3() * z_) - (R_ * R_);

	double D = b * b - 4.0 * a * c;

	if (Less(D, 0.0))
	{
		return false;
	}

	if (is_equal(a, 0.0))
	{
		throw std::runtime_error("Unexpected error.\n");
	}

	double t = (-b - sqrt(D)) / (2.0 * a);

	if (Greater(D, 0.0) || is_equal(D, 0.0))
	{
		if (Greater(t, 0.0))
		{
			return true;
		}

		if (Less(t, 0.0))
		{
			return false;
		}

	}

	return false;

}


Vector3d Sphere::ret_point(Vector3d origin, Vector3d direction)
{
	double a = (direction.get_v1() * direction.get_v1() + direction.get_v2() * direction.get_v2() + direction.get_v3() * direction.get_v3());
	double b = (2.0 * ((direction.get_v1()) * (origin.get_v1() - x_) + direction.get_v2() * (origin.get_v2() - y_) + direction.get_v3() * (origin.get_v3() - z_)));
	double c = origin.get_v1() * origin.get_v1() + origin.get_v2() * origin.get_v2() + origin.get_v3() * origin.get_v3() + x_ * x_ + y_ * y_ + z_ * z_ - 2.0 * ((origin.get_v1() * x_) + origin.get_v2() * y_ + origin.get_v3() * z_) - (R_ * R_);

	double D = b * b - 4.0 * a * c;

	double t = (-b - sqrt(D)) / (2.0 * a);

	Vector3d point = origin + direction * t;

	return point;
}

Vector3d Sphere::ret_normal(Vector3d point)
{
	Vector3d normal_surface(point.get_v1() - x_, point.get_v2() - y_, point.get_v3() - z_);

	normal_surface.normalize();

	return normal_surface;
}

void Sphere::set_x(const double x)
{
	x_ = x;
}
void Sphere::set_y(const double y)
{
	y_ = y;
}
void Sphere::set_z(const double z)
{
	z_ = z;
}
void Sphere::set_R(const double R)
{
	R_ = R;
}

Vector3d Sphere::return_centroid(void)
{
	Vector3d tmp(x_, y_, z_);

	return tmp;
}

void Sphere::set_color(const int color)
{
	color_ = color;
}

int Sphere::get_color(void)
{
	return color_;
}
