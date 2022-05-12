#include "Header.h"
#include "Functions.h"

bool is_equal(double left, double right)
{
	return (fabs(left - right) < epsi);
}

bool Less(double left, double right, bool orequal)
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left < right);

}

bool Greater(double left, double right, bool orequal)
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left > right);

}

bool Triangle_intersection(Vector3d origin, Vector3d direction, Vector3d v1, Vector3d v2, Vector3d v3)
{
	Vector3d e1 = v2 - v1;
	Vector3d e2 = v3 - v1;

	Vector3d pvec = direction.V_product(e2);
	
	double det = e1.D_product(pvec);

	if (det < 1e-8 && det > -1e-8) {
		return false;
	}

	double inv_det = 1 / det;
	
	Vector3d tvec = origin - v1;
	
	double u = (tvec.D_product(pvec)) * inv_det;
	
	if (u < 0 || u > 1)
	{
		return false;
	}

	Vector3d qvec = tvec.V_product(e1);
	
	double v = (direction.D_product(qvec)) * inv_det;
	
	if (v < 0 || u + v > 1)
	{
		return false;
	}

	double t = e2.D_product(qvec) * inv_det;

	if (t > 0)
	{
		return true;
	}

	return false;
}



bool Triangle_intersection_for_point(Vector3d origin, Vector3d direction, Vector3d v1, Vector3d v2, Vector3d v3, double& t)
{

	Vector3d e1 = v2 - v1;
	Vector3d e2 = v3 - v1;

	Vector3d pvec = direction.V_product(e2);

	double det = e1.D_product(pvec);

	if (det < 1e-8 && det > -1e-8)
	{
		return false;
	}

	double inv_det = 1 / det;

	Vector3d tvec = origin - v1;

	double u = (tvec.D_product(pvec)) * inv_det;

	if (u < 0 || u > 1)
	{
		return false;
	}

	Vector3d qvec = tvec.V_product(e1);

	double v = (direction.D_product(qvec)) * inv_det;

	if (v < 0 || u + v > 1)
	{
		return false;
	}

	t = e2.D_product(qvec) * inv_det;

	if (t > 0)
	{
		return true;
	}

	return false;

}


bool Does_the_point_belong_to_the_plane(Vector3d point, Vector3d v0, Vector3d v1, Vector3d v2)
{
	Vector3d u = v1 - v0;
	Vector3d v = v2 - v0;

	Vector3d N = u.V_product(v);
	Vector3d is_on_the_plane = point - v0;

	if (N.D_product(is_on_the_plane) < 0.000001)
	{
		return true;
	}

	return false;
}


bool Rectangle_intersection(Vector3d origin, Vector3d direction, Vector3d vertex1, Vector3d vertex2, Vector3d vertex3,Vector3d vertex4)
{

	if (Triangle_intersection(origin, direction, vertex1, vertex2, vertex4) || Triangle_intersection(origin, direction, vertex2, vertex3, vertex4))
	{
		return true;
	}

	return false;

}

bool Rectangle_intersection_for_point(Vector3d origin, Vector3d direction, Vector3d vertex1, Vector3d vertex2, Vector3d vertex3, Vector3d vertex4, double& t)
{

	if (Triangle_intersection_for_point(origin,direction,vertex1,vertex2,vertex4,t))
	{
		return true;
	}

	if (Triangle_intersection_for_point(origin,direction,vertex2,vertex3,vertex4,t))
	{
		return true;
	}

	return false;

}