#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Tetrahedron.h"
#include "Vector_3_float.h"

Tetrahedron::Tetrahedron(const float x1, const float y1, const float z1, const float x2, const float y2, const float z2, const float x3, const float y3, const float z3, const float x4, const float y4, const float z4)
{

	Vector_3_float A(x1, y1, z1);
	Vector_3_float B(x2, y2, z2);
	Vector_3_float C(x3, y3, z3);
	Vector_3_float D(x4, y4, z4);
	Vector_3_float E(1.0, 0.0, 0.0);
	Vector_3_float F(1.0, 0.0, 0.0);


	first_vertex = A;
	second_vertex = B;
	third_vertex = C;
	fourth_vertex = D;
	Normal_ = E;
	Point_ = F;
}


Vector_3_float Tetrahedron::ret_point(const float a, const float b, const float c, const float d, const float e, const float f)
{
	return Point_;
}

Vector_3_float Tetrahedron::ret_normal(const float a, const float b, const float c)
{
	return Normal_;
}


bool Triangle_intersection(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z, Vector_3_float v0_, Vector_3_float v1_, Vector_3_float v2_)
{

	Vector_3_float origin(origin_x, origin_y, origin_z);
	Vector_3_float direction(dir_x, dir_y, dir_z);

	const float EPSILON = 0.0001f;

	Vector_3_float vertex0 = v0_;
	Vector_3_float vertex1 = v1_;
	Vector_3_float vertex2 = v2_;
	Vector_3_float edge1, edge2, h, s, q;

	float a, f, u, v;

	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;

	h = direction.V_product(edge2);
	a = edge1.D_product(h);

	if (a > -EPSILON && a < EPSILON)
	{
		return false;
	}

	f = 1.0 / a;
	s = origin - vertex0;
	u = f * s.D_product(h);

	if (u < 0.0 || u > 1.0)
	{
		return false;
	}

	q = s.V_product(edge1);
	v = f * direction.D_product(q);

	if (v < 0.0 || u + v > 1.0)
	{
		return false;
	}

	float t = f * edge2.D_product(q);

	if (t > EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}

}
float return_param(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z, Vector_3_float v0_, Vector_3_float v1_, Vector_3_float v2_)
{
	Vector_3_float origin(origin_x, origin_y, origin_z);
	Vector_3_float direction(dir_x, dir_y, dir_z);

	const float EPSILON = 0.0001f;

	Vector_3_float vertex0 = v0_;
	Vector_3_float vertex1 = v1_;
	Vector_3_float vertex2 = v2_;

	Vector_3_float edge1, edge2, h, s, q;

	float a, f, u, v;

	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;

	h = direction.V_product(edge2);
	a = edge1.D_product(h);

	if (a > -EPSILON && a < EPSILON)
	{
		throw std::runtime_error("Failed \n");
	}

	f = 1.0 / a;
	s = origin - vertex0;
	u = f * s.D_product(h);

	if (u < 0.0 || u > 1.0)
	{
		throw std::runtime_error("Failed.\n");
	}

	q = s.V_product(edge1);
	v = f * direction.D_product(q);

	if (v < 0.0 || u + v > 1.0)
	{
		throw std::runtime_error("Failed \n");
	}

	float t = f * edge2.D_product(q);

	if (t > EPSILON)
	{
		return t;
	}
	else
	{
		throw std::runtime_error("Failed \n");
	}


}
bool Tetrahedron::ray_intersect(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z)
{
	map <float, Vector_3_float> pairs;

	if (Triangle_intersection(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, second_vertex, third_vertex))
	{


		Vector_3_float u = second_vertex - first_vertex;
		Vector_3_float v = third_vertex - first_vertex;
		Vector_3_float D = fourth_vertex - first_vertex;

		Vector_3_float Normal = u.V_product(v);

		if (Normal.D_product(D) > 0.0)
		{
			Normal = Normal * -1.0;

		}

		Normal.normalize();

		pairs.insert(make_pair(return_param(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, second_vertex, third_vertex), Normal));

	}

	if (Triangle_intersection(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, second_vertex, third_vertex, fourth_vertex))
	{

		Vector_3_float u = third_vertex - second_vertex;
		Vector_3_float v = fourth_vertex - second_vertex;
		Vector_3_float D = first_vertex - second_vertex;

		Vector_3_float Normal = u.V_product(v);

		if (Normal.D_product(D) > 0.0)
		{
			Normal = Normal * -1.0;

		}

		Normal.normalize();

		pairs.insert(make_pair(return_param(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, second_vertex, third_vertex, fourth_vertex), Normal));
	}

	if (Triangle_intersection(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, second_vertex, fourth_vertex))
	{

		Vector_3_float u = second_vertex - first_vertex;
		Vector_3_float v = fourth_vertex - first_vertex;
		Vector_3_float D = third_vertex - first_vertex;

		Vector_3_float Normal = u.V_product(v);

		if (Normal.D_product(D) > 0.0)
		{
			Normal = Normal * -1.0;

		}

		Normal.normalize();

		pairs.insert(make_pair(return_param(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, second_vertex, fourth_vertex), Normal));
	}

	if (Triangle_intersection(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, third_vertex, fourth_vertex))
	{

		Vector_3_float u = third_vertex - first_vertex;
		Vector_3_float v = fourth_vertex - first_vertex;
		Vector_3_float D = second_vertex - first_vertex;

		Vector_3_float Normal = u.V_product(v);

		if (Normal.D_product(D) > 0.0)
		{
			Normal = Normal * -1.0;

		}

		Normal.normalize();

		pairs.insert(make_pair(return_param(origin_x, origin_y, origin_z, dir_x, dir_y, dir_z, first_vertex, third_vertex, fourth_vertex), Normal));
	}


	if (pairs.size() == 0)
	{
		return false;
	}

	map <float, Vector_3_float> ::iterator it = pairs.begin();

	Vector_3_float origin(origin_x, origin_y, origin_z);
	Vector_3_float direction(dir_x, dir_y, dir_z);

	float param = it->first;

	Normal_ = it->second;

	Point_ = origin + direction * param;

	return true;

}


Vector_3_float Tetrahedron::return_centroid()
{
	Vector_3_float center = (first_vertex + second_vertex + third_vertex + fourth_vertex) / 4.0f;

	return center;
}

void Tetrahedron::set_color(int color_)
{
	color = color_;
}

int Tetrahedron::get_color()
{
	return color;
}

Tetrahedron::~Tetrahedron()
{
}