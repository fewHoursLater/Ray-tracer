#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Tetrahedron.h"
#include "Vector3d.h"

Tetrahedron::Tetrahedron( double x1,  double y1,  double z1,  double x2,  double y2,  double z2,  double x3,  double y3,  double z3,  double x4,  double y4,  double z4)
{

	Vector3d A(x1, y1, z1);
	Vector3d B(x2, y2, z2);
	Vector3d C(x3, y3, z3);
	Vector3d D(x4, y4, z4);

	first_vertex = A;
	second_vertex = B;
	third_vertex = C;
	fourth_vertex = D;
	
}


bool Tetrahedron::ray_intersect(Vector3d origin, Vector3d direction)
{
	if (Triangle_intersection(origin,direction,first_vertex,second_vertex,third_vertex) || Triangle_intersection(origin, direction, second_vertex, third_vertex, fourth_vertex) || Triangle_intersection(origin, direction, first_vertex, second_vertex, fourth_vertex) || Triangle_intersection(origin, direction, first_vertex, third_vertex, fourth_vertex))
	{
		return true;
	}

	return false;
}

Vector3d Tetrahedron::ret_normal(Vector3d point)
{
	if (Does_the_point_belong_to_the_plane(point, first_vertex, second_vertex, third_vertex))
	{
		Vector3d inside = fourth_vertex - first_vertex;

		Vector3d u = second_vertex - first_vertex;
		Vector3d v = third_vertex - first_vertex;

		Vector3d N = u.V_product(v);

		if (N.D_product(inside)> 0.0)  ////////////////
		{
			N = N * (-1.0);
		}

		N.normalize();

		return N;


	}

	if (Does_the_point_belong_to_the_plane(point, second_vertex, third_vertex, fourth_vertex))
	{
		Vector3d inside = first_vertex - second_vertex;

		Vector3d u = third_vertex - second_vertex;
		Vector3d v = fourth_vertex - second_vertex;

		Vector3d N = u.V_product(v);

		if (N.D_product(inside) > 0.0)  ////////////////
		{
			N = N * (-1.0);
		}

		N.normalize();

		return N;
	}

	if (Does_the_point_belong_to_the_plane(point, first_vertex, second_vertex, fourth_vertex))
	{
		Vector3d inside = third_vertex - first_vertex;

		Vector3d u = second_vertex - first_vertex;
		Vector3d v = fourth_vertex - first_vertex;

		Vector3d N = u.V_product(v);

		if (N.D_product(inside) > 0.0)  ////////////////
		{
			N = N * (-1.0);
		}

		N.normalize();

		return N;
	}

	if (Does_the_point_belong_to_the_plane(point, first_vertex, third_vertex, fourth_vertex))
	{
		Vector3d inside = second_vertex - first_vertex;

		Vector3d u = third_vertex - first_vertex;
		Vector3d v = fourth_vertex - first_vertex;

		Vector3d N = u.V_product(v);

		if (N.D_product(inside) > 0.0)  ////////////////
		{
			N = N * (-1.0);
		}

		N.normalize();

		return N;
	}

	return Vector3d(0, 0, 0);
}


Vector3d Tetrahedron::ret_point(Vector3d origin, Vector3d direction)
{
	vector<double> parameters;

	double t = -1.0;

	if (Triangle_intersection_for_point(origin, direction, first_vertex, second_vertex, third_vertex, t))
	{
		parameters.push_back(t);
	}

	if (Triangle_intersection_for_point(origin, direction, second_vertex, third_vertex, fourth_vertex, t))
	{
		parameters.push_back(t);
	}

	if (Triangle_intersection_for_point(origin, direction, first_vertex, second_vertex, fourth_vertex, t))
	{
		parameters.push_back(t);
	}

	if (Triangle_intersection_for_point(origin, direction, first_vertex, third_vertex, fourth_vertex, t))
	{
		parameters.push_back(t);
	}

	if (parameters.capacity() == 0)
	{
		throw std::runtime_error("Unexpected error.\n");
	}

	if (parameters.capacity() == 1)
	{
		double min_t = parameters[0];

		Vector3d tmp = origin + direction * min_t;

		return tmp;

	}

	if (parameters.capacity() == 2)
	{
		double min_t = min(parameters[0], parameters[1]);

		Vector3d tmp = origin + direction * min_t;

		return tmp;
	}

	if (parameters.capacity() == 3)
	{
		double min_t = min(min(parameters[0], parameters[1]), parameters[2]);

		Vector3d tmp = origin + direction * min_t;

		return tmp;
	}

	if (parameters.capacity() == 4)
	{
		double min_t = min(min(parameters[0], parameters[1]), min(parameters[2], parameters[3]));

		Vector3d tmp = origin + direction * min_t;

		return tmp;
	}
}


Vector3d Tetrahedron::return_centroid(void)
{
	Vector3d centroid = (first_vertex + second_vertex + third_vertex + fourth_vertex) / 4.0;

	return centroid;
}

void Tetrahedron::set_color(const int color)
{
	color_ = color;
}

int Tetrahedron::get_color(void)
{
	return color_;
}