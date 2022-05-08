#include "Header.h"
#include "Functions.h"

bool is_equal(double left, double right)
{
	return (fabs(left - right) < epsi);
}

bool Less(double left, double right, bool orequal) // Добавить true в параметры, будет <=
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left < right);

}

bool Greater(double left, double right, bool orequal) // Добавить true в параметры, будет >=
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left > right);

}

bool Triangle_intersection(Vector3d origin, Vector3d direction, Vector3d v0, Vector3d v1, Vector3d v2)
{

	Vector3d E1 = v1 - v0;
	Vector3d E2 = v2 - v0;

	Vector3d N = E1.V_product(E2);

	double det = direction.D_product(N) * (-1.0);
	double inv_det = 1.0 / det;

	Vector3d AO = origin - v0;
	Vector3d DAO = AO.V_product(direction);

	double u = E2.D_product(DAO) * inv_det;
	double v = E1.D_product(DAO) * inv_det * (-1.0);

	double t = AO.D_product(N) * inv_det;

	return (fabs(det) >= 1e-8 && t >= 1e-6 && u >= 1e-6 && v >= 1e-6 && (u + v) <= 1.0); ////////////////

}

bool Triangle_intersection_for_point(Vector3d origin, Vector3d direction, Vector3d v0, Vector3d v1, Vector3d v2, double& t)
{

	Vector3d E1 = v1 - v0;
	Vector3d E2 = v2 - v0;

	Vector3d N = E1.V_product(E2);

	double det = direction.D_product(N) * (-1.0);
	double inv_det = 1.0 / det;

	Vector3d AO = origin - v0;
	Vector3d DAO = AO.V_product(direction);

	double u = E2.D_product(DAO) * inv_det;
	double v = E1.D_product(DAO) * inv_det * (-1.0);

	t = AO.D_product(N) * inv_det;

	return (fabs(det) >= 1e-6 && t >= 1e-6 && u >= 1e-6 && v >= 1e-6 && (u + v) <= 1.0);  ////////////////

}


bool Does_the_point_belong_to_the_plane(Vector3d point, Vector3d v0, Vector3d v1, Vector3d v2)
{
	Vector3d u = v1 - v0;
	Vector3d v = v2 - v0;

	Vector3d N = u.V_product(v);
	Vector3d is_on_the_plane = point - v0;

	if (N.D_product(is_on_the_plane) < 0.00001)		////////////////
	{
		return true;
	}

	return false;
}


bool Rectangle_intersection(Vector3d origin, Vector3d direction, Vector3d vertex1, Vector3d vertex2, Vector3d vertex3,Vector3d vertex4)
{

	if (Triangle_intersection(origin,direction,vertex1,vertex2,vertex4))
	{
		return true;
	}

	if (Triangle_intersection(origin, direction, vertex3, vertex2, vertex4))
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

	if (Triangle_intersection_for_point(origin,direction,vertex3,vertex2,vertex4,t))
	{
		return true;
	}

	return false;

}