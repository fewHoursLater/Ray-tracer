#pragma once

#include "Header.h"
#include "Vector3d.h"

bool is_equal(double left, double right);
bool Less(double left, double right, bool orequal = false);
bool Greater(double left, double right, bool orequal = false);

bool Triangle_intersection(Vector3d, Vector3d, Vector3d, Vector3d, Vector3d);
bool Triangle_intersection_for_point(Vector3d, Vector3d, Vector3d, Vector3d, Vector3d, double&);
bool Does_the_point_belong_to_the_plane(Vector3d, Vector3d, Vector3d, Vector3d);

bool Rectangle_intersection(Vector3d, Vector3d, Vector3d, Vector3d, Vector3d, Vector3d);
bool Rectangle_intersection_for_point(Vector3d, Vector3d, Vector3d, Vector3d, Vector3d, Vector3d, double&);

double Triangle_square(Vector3d, Vector3d, Vector3d);