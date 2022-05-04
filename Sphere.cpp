#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Sphere.h"
#include "Vector_3_float.h"

Sphere::Sphere()
{
	x_ = 0.;
	y_ = 0.;
	z_ = 0.;

	R_ = 1.;


}
Sphere::Sphere(const float x, const float y, const float z, const float R)
{
	if (R < 0)
	{
		throw std::runtime_error("Negative radius.\n");
	}

	x_ = x;
	y_ = y;
	z_ = z;
	R_ = R;
}

float Sphere::get_x(void)
{
	return x_;
}
float Sphere::get_y(void)
{
	return y_;
}
float Sphere::get_z(void)
{
	return z_;
}
float Sphere::get_R(void)
{
	return R_;
}

bool Sphere::ray_intersect(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z)  // Луч, выходящий из точки в данном направлении пересекает ли сферу?
{

	float a = (dir_x * dir_x + dir_y * dir_y + dir_z * dir_z);
	float b = (2.0 * ((dir_x) * (origin_x - x_) + dir_y * (origin_y - y_) + dir_z * (origin_z - z_)));
	float c = origin_x * origin_x + origin_y * origin_y + origin_z * origin_z + x_ * x_ + y_ * y_ + z_ * z_ - 2.0 * ((origin_x * x_) + origin_y * y_ + origin_z * z_) - (R_ * R_);

	float D = b * b - 4.0 * a * c;

	if (Less(D, 0.0f))
	{
		return false;
	}

	if (is_equal(a, 0.0f))
	{
		cout << "Error." << endl;
	}

	float t = (-b - sqrtf(D)) / (2.0f * a);


	if (Greater(D, 0.0f) || is_equal(D, 0.0))
	{
		if (Greater(t, 0.0f))
		{
			return true;
		}

		if (Less(t, 0.0f))
		{
			return false;
		}

	}

	return false;

}


Vector_3_float Sphere::ret_point(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z)
{
	float a = dir_x * dir_x + dir_y * dir_y + dir_z * dir_z;
	float b = 2.0f * (dir_x * (origin_x - x_) + dir_y * (origin_y - y_) + dir_z * (origin_z - z_));
	float c = origin_x * origin_x + origin_y * origin_y + origin_z * origin_z + x_ * x_ + y_ * y_ + z_ * z_ - 2.0f * (origin_x * x_ + origin_y * y_ + origin_z * z_) - R_ * R_;

	float D = b * b - 4.0f * a * c;

	float t = (-b - sqrtf(D)) / (2.0f * a);

	Vector_3_float pixel(origin_x + dir_x * t, origin_y + dir_y * t, origin_z + dir_z * t);

	return pixel;
}

Vector_3_float Sphere::ret_normal(const float x, const float y, const float z)
{
	Vector_3_float normal_surface(x - x_, y - y_, z - z_);

	return normal_surface;
}

void Sphere::set_x(const float x)
{
	x_ = x;
}
void Sphere::set_y(const float y)
{
	y_ = y;
}
void Sphere::set_z(const float z)
{
	z_ = z;
}
void Sphere::set_R(const float R)
{
	R_ = R;
}

Vector_3_float Sphere::return_centroid()
{
	return Vector_3_float(x_, y_, z_);
}

void Sphere::set_color(int color_)
{
	color = color_;
}

int Sphere::get_color()
{
	return color;
}

Sphere::~Sphere()
{
}