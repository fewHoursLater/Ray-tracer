#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Box.h"
#include "Vector3d.h"

Box::Box(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2)
{

	if (Less(x2, x1, true) || Less(y2, y1, true) || Less(z2, z1, true))
	{
		throw std::runtime_error("The diagonal of the box should be directed to the first quadrant.\n");
	}

	Vector3d A(x1, y1, z1);
	Vector3d B(x2, y2, z2);

	begin = A;
	end = B;
}

bool Box::ray_intersect(Vector3d origin, Vector3d direction)
{
	Vector3d diagonal = end - begin;
	Vector3d Ex(1.0, 0.0, 0.0);
	Vector3d Ey(0.0, 1.0, 0.0);
	Vector3d Ez(0.0, 0.0, 1.0);

	double px = diagonal.get_v1();
	double py = diagonal.get_v2();
	double pz = diagonal.get_v3();

	Vector3d vertex1 = begin;
	Vector3d vertex2 = begin + Ez *pz;
	Vector3d vertex3 = begin + Ey * py + Ez * pz;
	Vector3d vertex4 = begin + Ey * py;
	Vector3d vertex5 = begin + Ex * px;
	Vector3d vertex6 = begin + Ex * px + Ez * pz;
	Vector3d vertex7 = end;
	Vector3d vertex8 = begin + Ex * px + Ey * py;

	if (Rectangle_intersection(origin, direction, vertex1, vertex2, vertex3, vertex4))
	{
		return true;
	}

	if (Rectangle_intersection(origin, direction, vertex5, vertex6, vertex2, vertex1))
	{
		return true;
	}

	if (Rectangle_intersection(origin, direction, vertex8, vertex7, vertex6, vertex5))
	{
		return true;
	}

	if (Rectangle_intersection(origin, direction, vertex8, vertex7, vertex3, vertex4))
	{
		return true;
	}

	if (Rectangle_intersection(origin, direction, vertex2, vertex6, vertex7, vertex3))
	{
		return true;
	}

	if (Rectangle_intersection(origin, direction, vertex1, vertex5, vertex8, vertex4))
	{
		return true;
	}

	return false;

}

Vector3d Box::ret_point(Vector3d origin, Vector3d direction)
{
	Vector3d diagonal = end - begin;
	Vector3d Ex(1.0, 0.0, 0.0);
	Vector3d Ey(0.0, 1.0, 0.0);
	Vector3d Ez(0.0, 0.0, 1.0);

	double px = diagonal.get_v1();
	double py = diagonal.get_v2();
	double pz = diagonal.get_v3();

	Vector3d vertex1 = begin;
	Vector3d vertex2 = begin + Ez * pz;
	Vector3d vertex3 = begin + Ey * py + Ez * pz;
	Vector3d vertex4 = begin + Ey * py;
	Vector3d vertex5 = begin + Ex * px;
	Vector3d vertex6 = begin + Ex * px + Ez * pz;
	Vector3d vertex7 = end;
	Vector3d vertex8 = begin + Ex * px + Ey * py;

	vector<double> parameters;

	double t = -1.0;

	if (Rectangle_intersection_for_point(origin, direction, vertex1, vertex2, vertex3, vertex4,t))
	{
		parameters.push_back(t);
	}

	if (Rectangle_intersection_for_point(origin, direction, vertex5, vertex6, vertex2, vertex1,t))
	{
		parameters.push_back(t);
	}

	if (Rectangle_intersection_for_point(origin, direction, vertex8, vertex7, vertex6, vertex5,t))
	{
		parameters.push_back(t);
	}

	if (Rectangle_intersection_for_point(origin, direction, vertex8, vertex7, vertex3, vertex4,t))
	{
		parameters.push_back(t);
	}

	if (Rectangle_intersection_for_point(origin, direction, vertex2, vertex6, vertex7, vertex3,t))
	{
		parameters.push_back(t);
	}

	if (Rectangle_intersection_for_point(origin, direction, vertex1, vertex5, vertex8, vertex4,t))
	{
		parameters.push_back(t);
	}

	double min_t;

	if (parameters.capacity() == 0)
	{
		throw std::runtime_error("Unexpected error.\n");
	}

	if (parameters.capacity() == 1)
	{
		min_t = parameters[0];
	}
	
	if (parameters.capacity() == 2)
	{
		min_t = min(parameters[0], parameters[1]);
	}

	if (parameters.capacity() == 3)
	{
		min_t = min(min(parameters[0],parameters[1]),parameters[2]);
	}

	if (parameters.capacity() == 4)
	{
		min_t = min(min(parameters[0], parameters[1]), min(parameters[2], parameters[3]));
	}

	if (parameters.capacity() == 5)
	{
		min_t = min(min(min(parameters[0], parameters[1]), min(parameters[2], parameters[3])), parameters[4]);
	}

	if (parameters.capacity() == 6)
	{
		min_t = min(min(min(min(parameters[0], parameters[1]),min(parameters[2], parameters[3])), parameters[4]),parameters[5]);
	}

	Vector3d tmp = origin + direction * min_t;

	return tmp;
}

Vector3d Box::ret_normal(Vector3d point) 
{

	Vector3d diagonal = end - begin;
	Vector3d Ex(1.0, 0.0, 0.0);
	Vector3d Ey(0.0, 1.0, 0.0);
	Vector3d Ez(0.0, 0.0, 1.0);

	double px = diagonal.get_v1();
	double py = diagonal.get_v2();
	double pz = diagonal.get_v3();

	Vector3d vertex1 = begin;
	Vector3d vertex2 = begin + Ez * pz;
	Vector3d vertex3 = begin + Ey * py + Ez * pz;
	Vector3d vertex4 = begin + Ey * py;
	Vector3d vertex5 = begin + Ex * px;
	Vector3d vertex6 = begin + Ex * px + Ez * pz;
	Vector3d vertex7 = end;
	Vector3d vertex8 = begin + Ex * px + Ey * py;

	Vector3d N1(1.0, 0.0, 0.0);
	Vector3d N2(0.0, 1.0, 0.0);
	Vector3d N3(0.0, 0.0, 1.0);

	Vector3d M1(-1.0, 0.0, 0.0);
	Vector3d M2(0.0, -1.0, 0.0);
	Vector3d M3(0.0, 0.0, -1.0);

	if (Does_the_point_belong_to_the_plane(point,vertex1,vertex2,vertex4))
	{
		return M1;
	}
	
	if (Does_the_point_belong_to_the_plane(point, vertex2, vertex5, vertex6))
	{
		return M2;
	}

	if (Does_the_point_belong_to_the_plane(point, vertex6, vertex7, vertex8))
	{
		return N1;
	}

	if (Does_the_point_belong_to_the_plane(point, vertex3, vertex4, vertex8))
	{
		return N2;
	}

	if (Does_the_point_belong_to_the_plane(point, vertex2, vertex3, vertex7))
	{
		return N3;
	}

	if (Does_the_point_belong_to_the_plane(point, vertex1, vertex4, vertex5))
	{
		return M3;
	}

	throw std::runtime_error("Unexpected error.\n");
}

Vector3d Box::return_centroid()
{
	Vector3d tmp = (end - begin) / 2.0;

	return tmp;
}

void Box::set_color(int color)
{
	color_ = color;
}

int Box::get_color()
{
	return color_;
}