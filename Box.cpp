#include "Header.h"
#include "Functions.h"
#include "Figure.h"
#include "Box.h"
#include "Vector_3_float.h"

Box::Box()
{
	Vector_3_float A((float)0.0, (float)0.0, (float)0.0);
	Vector_3_float B((float)1.0, (float)1.0, (float)1.0);

}

Box::Box(const float x1, const float y1, const float z1, const float x2, const float y2, const float z2)
{

	if (Less(x2 - x1, 0.0f) || Less(y2 - y1, 0.0f) || Less(z2 - z1, 0.0f) || is_equal(x2 - x1, 0.0f) || is_equal(y2 - y1, 0.0f) || is_equal(z2 - z1, 0.0f))
	{
		throw std::runtime_error("Failed to create box.\n");
	}


	Vector_3_float A(x1, y1, z1);
	Vector_3_float B(x2, y2, z2);

	begin = A;
	end = B;

}

bool Box::ray_intersect(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z)
{

	if (!is_equal(dir_x, 0.0) && !is_equal(dir_y, 0.0) && !is_equal(dir_z, 0.0))
	{
		float t1 = (begin.get_v1() - origin_x) / dir_x;
		float Y1 = origin_y + dir_y * t1;
		float Z1 = origin_z + dir_z * t1;

		if (Greater(t1, 0.0f) && Less(begin.get_v2(), Y1, true) && Less(Y1, end.get_v2(), true) && Less(begin.get_v3(), Z1, true) && Less(Z1, end.get_v3(), true))
		{

			return true;
		}

		float t2 = (begin.get_v2() - origin_y) / dir_y;
		float X2 = origin_x + dir_x * t2;
		float Z2 = origin_z + dir_z * t2;

		if (Greater(t2, 0.0f) && Less(begin.get_v1(), X2, true) && Less(X2, end.get_v1(), true) && Less(begin.get_v3(), Z2, true) && Less(Z2, end.get_v3(), true))
		{
			return true;
		}

		float t3 = (begin.get_v3() - origin_z) / dir_z;
		float X3 = origin_x + dir_x * t3;
		float Y3 = origin_y + dir_y * t3;

		if (Greater(t3, 0.0f) && Less(begin.get_v1(), X3, true) && Less(X3, end.get_v1(), true) && Less(begin.get_v2(), Y3, true) && Less(Y3, end.get_v2(), true))
		{

			return true;
		}

		float t4 = (end.get_v1() - origin_x) / dir_x;
		float Y4 = origin_y + dir_y * t4;
		float Z4 = origin_z + dir_z * t4;

		if (Greater(t4, 0.0f) && Less(begin.get_v2(), Y4, true) && Less(Y4, end.get_v2(), true) && Less(begin.get_v3(), Z4, true) && Less(Z4, end.get_v3(), true))
		{

			return true;
		}

		float t5 = (end.get_v2() - origin_y) / dir_y;
		float X5 = origin_x + dir_x * t5;
		float Z5 = origin_z + dir_z * t5;

		if (Greater(t5, 0.0f) && Less(begin.get_v1(), X5, true) && Less(X5, end.get_v1(), true) && Less(begin.get_v3(), Z5, true) && Less(Z5, end.get_v3(), true))
		{

			return true;
		}

		float t6 = (end.get_v3() - origin_z) / dir_z;
		float X6 = origin_x + dir_x * t6;
		float Y6 = origin_y + dir_y * t6;

		if (Greater(t6, 0.0f) && Less(begin.get_v1(), X6, true) && Less(X6, end.get_v1(), true) && Less(begin.get_v2(), Y6, true) && Less(Y6, end.get_v2(), true))
		{

			return true;
		}

	}
	if (is_equal(dir_x, 0.0f) && !is_equal(dir_y, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true))
		{


			float t7 = (begin.get_v2() - origin_y) / dir_y;
			float Z7 = origin_z + dir_z * t7;

			if (Greater(t7, 0.0f) && Less(begin.get_v3(), Z7, true) && Less(Z7, end.get_v3(), true))
			{

				return true;
			}

			float t8 = (end.get_v2() - origin_y) / dir_y;
			float Z8 = origin_z + dir_z * t8;

			if (Greater(t8, 0.0f) && Less(begin.get_v3(), Z8, true) && Less(Z8, end.get_v3(), true))
			{

				return true;
			}

			float t9 = (begin.get_v3() - origin_z) / dir_z;
			float Y9 = origin_y + dir_y * t9;

			if (Greater(t9, 0.0f) && Less(begin.get_v2(), Y9, true) && Less(Y9, end.get_v2(), true))
			{

				return true;

			}

			float t10 = (end.get_v3() - origin_z) / dir_z;
			float Y10 = origin_y + dir_y * t10;

			if (Greater(t10, 0.0f) && Less(begin.get_v2(), Y10, true) && Less(Y10, end.get_v2(), true))
			{

				return true;

			}

		}
	}
	if (is_equal(dir_y, 0.0f) && !is_equal(dir_x, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true))
		{

			float t11 = (begin.get_v1() - origin_x) / dir_x;
			float Z11 = origin_z + dir_z * t11;

			if (Greater(t11, 0.0f) && Less(begin.get_v3(), Z11, true) && Less(Z11, end.get_v3(), true))
			{

				return true;
			}


			float t12 = (end.get_v1() - origin_x) / dir_x;
			float Z12 = origin_z + dir_z * t12;

			if (Greater(t12, 0.0f) && Less(begin.get_v3(), Z12, true) && Less(Z12, end.get_v3(), true))
			{

				return true;
			}


			float t13 = (begin.get_v3() - origin_z) / dir_z;
			float X13 = origin_x + dir_x * t13;

			if (Greater(t13, 0.0f) && Less(begin.get_v1(), X13, true) && Less(X13, end.get_v1(), true))
			{

				return true;
			}


			float t14 = (end.get_v3() - origin_z) / dir_z;
			float X14 = origin_x + dir_x * t14;

			if (Greater(t14, 0.0f) && Less(begin.get_v1(), X14, true) && Less(X14, end.get_v1(), true))
			{

				return true;
			}
		}
	}
	if (is_equal(dir_z, 0.0f) && !is_equal(dir_x, 0.0f) && !is_equal(dir_y, 0.0f))
	{

		if (Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{

			float t15 = (begin.get_v1() - origin_x) / dir_x;
			float Y15 = origin_y + dir_y * t15;

			if (Greater(t15, 0.0f) && Less(begin.get_v2(), Y15, true) && Less(Y15, end.get_v2(), true))
			{
				return true;
			}


			float t16 = (end.get_v1() - origin_x) / dir_x;
			float Y16 = origin_y + dir_y * t16;

			if (Greater(t16, 0.0f) && Less(begin.get_v2(), Y16, true) && Less(Y16, end.get_v2(), true))
			{

				return true;
			}


			float t17 = (begin.get_v2() - origin_y) / dir_y;
			float X17 = origin_x + dir_x * t17;

			if (Greater(t17, 0.0f) && Less(begin.get_v1(), X17, true) && Less(X17, end.get_v1(), true))
			{

				return true;
			}

			float t18 = (end.get_v2() - origin_y) / dir_y;
			float X18 = origin_x + dir_x * t18;

			if (Greater(t18, 0.0f) && Less(begin.get_v1(), X18, true) && Less(X18, end.get_v1(), true))
			{

				return true;
			}

		}

	}
	if (is_equal(dir_x, 0.0f) && is_equal(dir_y, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true) && Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true))
		{

			float t19 = (begin.get_v3() - origin_z) / dir_z;

			if (Greater(t19, 0.0f))
			{

				return true;
			}

			float t20 = (end.get_v3() - origin_z) / dir_z;

			if (Greater(t20, 0.0f))
			{

				return true;
			}


		}
	}
	if (is_equal(dir_y, 0.0f) && is_equal(dir_z, 0.0f) && !is_equal(dir_x, 0.0f))
	{
		if (Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true) && Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{
			float t21 = (begin.get_v1() - origin_x) / dir_x;

			if (Greater(t21, 0.0f))
			{

				return true;
			}

			float t22 = (end.get_v1() - origin_x) / dir_x;

			if (Greater(t22, 0.0f))
			{

				return true;
			}

		}

	}
	if (is_equal(dir_x, 0.0f) && is_equal(dir_z, 0.0f) && !is_equal(dir_y, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true) && Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{
			float t23 = (begin.get_v2() - origin_y) / dir_y;

			if (Greater(t23, 0.0f))
			{

				return true;
			}

			float t24 = (end.get_v2() - origin_y) / dir_y;

			if (Greater(t24, 0.0f))
			{

				return true;
			}
		}
	}

	return false;

}


/// Less(begin.get_v1(), X, true) && Less(X, end.get_v1(), true)
/// Less(begin.get_v2(), Y, true) && Less(Y, end.get_v2(), true)
/// Less(begin.get_v3(), Z, true) && Less(Z, end.get_v3(), true)
/// 
/// 
/// Less(begin.get_v1(),origin_x,true) && Less(origin_x, begin.get_v1(), true)
/// Less(begin.get_v2(),origin_y,true) && Less(origin_y, begin.get_v2(), true)
/// Less(begin.get_v3(),origin_z,true) && Less(origin_z, begin.get_v3(), true)

Vector_3_float Box::ret_point(const float origin_x, const float origin_y, const float origin_z, const float dir_x, const float dir_y, const float dir_z)
{

	vector<float> parameters;

	if (!is_equal(dir_x, 0.0) && !is_equal(dir_y, 0.0) && !is_equal(dir_z, 0.0))
	{
		float t1 = (begin.get_v1() - origin_x) / dir_x;
		float Y1 = origin_y + dir_y * t1;
		float Z1 = origin_z + dir_z * t1;

		if (Greater(t1, 0.0f) && Less(begin.get_v2(), Y1, true) && Less(Y1, end.get_v2(), true) && Less(begin.get_v3(), Z1, true) && Less(Z1, end.get_v3(), true))
		{

			parameters.push_back(t1);
		}

		float t2 = (begin.get_v2() - origin_y) / dir_y;
		float X2 = origin_x + dir_x * t2;
		float Z2 = origin_z + dir_z * t2;

		if (Greater(t2, 0.0f) && Less(begin.get_v1(), X2, true) && Less(X2, end.get_v1(), true) && Less(begin.get_v3(), Z2, true) && Less(Z2, end.get_v3(), true))
		{
			parameters.push_back(t2);
		}

		float t3 = (begin.get_v3() - origin_z) / dir_z;
		float X3 = origin_x + dir_x * t3;
		float Y3 = origin_y + dir_y * t3;

		if (Greater(t3, 0.0f) && Less(begin.get_v1(), X3, true) && Less(X3, end.get_v1(), true) && Less(begin.get_v2(), Y3, true) && Less(Y3, end.get_v2(), true))
		{

			parameters.push_back(t3);
		}

		float t4 = (end.get_v1() - origin_x) / dir_x;
		float Y4 = origin_y + dir_y * t4;
		float Z4 = origin_z + dir_z * t4;

		if (Greater(t4, 0.0f) && Less(begin.get_v2(), Y4, true) && Less(Y4, end.get_v2(), true) && Less(begin.get_v3(), Z4, true) && Less(Z4, end.get_v3(), true))
		{

			parameters.push_back(t4);
		}

		float t5 = (end.get_v2() - origin_y) / dir_y;
		float X5 = origin_x + dir_x * t5;
		float Z5 = origin_z + dir_z * t5;

		if (Greater(t5, 0.0f) && Less(begin.get_v1(), X5, true) && Less(X5, end.get_v1(), true) && Less(begin.get_v3(), Z5, true) && Less(Z5, end.get_v3(), true))
		{

			parameters.push_back(t5);
		}

		float t6 = (end.get_v3() - origin_z) / dir_z;
		float X6 = origin_x + dir_x * t6;
		float Y6 = origin_y + dir_y * t6;

		if (Greater(t6, 0.0f) && Less(begin.get_v1(), X6, true) && Less(X6, end.get_v1(), true) && Less(begin.get_v2(), Y6, true) && Less(Y6, end.get_v2(), true))
		{

			parameters.push_back(t6);
		}

	}
	if (is_equal(dir_x, 0.0f) && !is_equal(dir_y, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true))
		{


			float t7 = (begin.get_v2() - origin_y) / dir_y;
			float Z7 = origin_z + dir_z * t7;

			if (Greater(t7, 0.0f) && Less(begin.get_v3(), Z7, true) && Less(Z7, end.get_v3(), true))
			{

				parameters.push_back(t7);
			}

			float t8 = (end.get_v2() - origin_y) / dir_y;
			float Z8 = origin_z + dir_z * t8;

			if (Greater(t8, 0.0f) && Less(begin.get_v3(), Z8, true) && Less(Z8, end.get_v3(), true))
			{

				parameters.push_back(t8);
			}

			float t9 = (begin.get_v3() - origin_z) / dir_z;
			float Y9 = origin_y + dir_y * t9;

			if (Greater(t9, 0.0f) && Less(begin.get_v2(), Y9, true) && Less(Y9, end.get_v2(), true))
			{

				parameters.push_back(t9);

			}

			float t10 = (end.get_v3() - origin_z) / dir_z;
			float Y10 = origin_y + dir_y * t10;

			if (Greater(t10, 0.0f) && Less(begin.get_v2(), Y10, true) && Less(Y10, end.get_v2(), true))
			{

				parameters.push_back(t10);

			}

		}
	}
	if (is_equal(dir_y, 0.0f) && !is_equal(dir_x, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true))
		{

			float t11 = (begin.get_v1() - origin_x) / dir_x;
			float Z11 = origin_z + dir_z * t11;

			if (Greater(t11, 0.0f) && Less(begin.get_v3(), Z11, true) && Less(Z11, end.get_v3(), true))
			{

				parameters.push_back(t11);
			}


			float t12 = (end.get_v1() - origin_x) / dir_x;
			float Z12 = origin_z + dir_z * t12;

			if (Greater(t12, 0.0f) && Less(begin.get_v3(), Z12, true) && Less(Z12, end.get_v3(), true))
			{

				parameters.push_back(t12);
			}


			float t13 = (begin.get_v3() - origin_z) / dir_z;
			float X13 = origin_x + dir_x * t13;

			if (Greater(t13, 0.0f) && Less(begin.get_v1(), X13, true) && Less(X13, end.get_v1(), true))
			{

				parameters.push_back(t13);
			}


			float t14 = (end.get_v3() - origin_z) / dir_z;
			float X14 = origin_x + dir_x * t14;

			if (Greater(t14, 0.0f) && Less(begin.get_v1(), X14, true) && Less(X14, end.get_v1(), true))
			{

				parameters.push_back(t14);
			}
		}
	}
	if (is_equal(dir_z, 0.0f) && !is_equal(dir_x, 0.0f) && !is_equal(dir_y, 0.0f))
	{

		if (Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{

			float t15 = (begin.get_v1() - origin_x) / dir_x;
			float Y15 = origin_y + dir_y * t15;

			if (Greater(t15, 0.0f) && Less(begin.get_v2(), Y15, true) && Less(Y15, end.get_v2(), true))
			{
				parameters.push_back(t15);
			}


			float t16 = (end.get_v1() - origin_x) / dir_x;
			float Y16 = origin_y + dir_y * t16;

			if (Greater(t16, 0.0f) && Less(begin.get_v2(), Y16, true) && Less(Y16, end.get_v2(), true))
			{

				parameters.push_back(t16);
			}


			float t17 = (begin.get_v2() - origin_y) / dir_y;
			float X17 = origin_x + dir_x * t17;

			if (Greater(t17, 0.0f) && Less(begin.get_v1(), X17, true) && Less(X17, end.get_v1(), true))
			{

				parameters.push_back(t17);
			}

			float t18 = (end.get_v2() - origin_y) / dir_y;
			float X18 = origin_x + dir_x * t18;

			if (Greater(t18, 0.0f) && Less(begin.get_v1(), X18, true) && Less(X18, end.get_v1(), true))
			{

				parameters.push_back(t18);
			}

		}

	}
	if (is_equal(dir_x, 0.0f) && is_equal(dir_y, 0.0f) && !is_equal(dir_z, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true) && Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true))
		{

			float t19 = (begin.get_v3() - origin_z) / dir_z;

			if (Greater(t19, 0.0f))
			{

				parameters.push_back(t19);
			}

			float t20 = (end.get_v3() - origin_z) / dir_z;

			if (Greater(t20, 0.0f))
			{

				parameters.push_back(t20);
			}


		}
	}
	if (is_equal(dir_y, 0.0f) && is_equal(dir_z, 0.0f) && !is_equal(dir_x, 0.0f))
	{
		if (Less(begin.get_v2(), origin_y, true) && Less(origin_y, begin.get_v2(), true) && Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{
			float t21 = (begin.get_v1() - origin_x) / dir_x;

			if (Greater(t21, 0.0f))
			{

				parameters.push_back(t21);
			}

			float t22 = (end.get_v1() - origin_x) / dir_x;

			if (Greater(t22, 0.0f))
			{

				parameters.push_back(t22);
			}

		}

	}
	if (is_equal(dir_x, 0.0f) && is_equal(dir_z, 0.0f) && !is_equal(dir_y, 0.0f))
	{
		if (Less(begin.get_v1(), origin_x, true) && Less(origin_x, begin.get_v1(), true) && Less(begin.get_v3(), origin_z, true) && Less(origin_z, begin.get_v3(), true))
		{
			float t23 = (begin.get_v2() - origin_y) / dir_y;

			if (Greater(t23, 0.0f))
			{

				parameters.push_back(t23);
			}

			float t24 = (end.get_v2() - origin_y) / dir_y;

			if (Greater(t24, 0.0f))
			{

				parameters.push_back(t24);
			}
		}
	}

	float min;
	min = parameters[0];

	for (auto i : parameters)
	{
		if (Less(i, min))
		{
			min = i;
		}

	}

	Vector_3_float origin(origin_x, origin_y, origin_z);
	Vector_3_float direction(dir_x, dir_y, dir_z);
	Vector_3_float point = origin + direction * min;

	return point;

}

Vector_3_float Box::ret_normal(const float x, const float y, const float z) // Точка Уже на поверхности, но на какой грани7???????
{
	Vector_3_float n1(1.0, 0.0, 0.0);
	Vector_3_float n2(0.0, 1.0, 0.0);
	Vector_3_float n3(0.0, 0.0, 1.0);
	Vector_3_float n4(-1.0, 0.0, 0.0);
	Vector_3_float n5(0.0, -1.0, 0.0);
	Vector_3_float n6(0.0, 0.0, -1.0);

	Vector_3_float diagonal = end - begin;

	if (is_equal(x, begin.get_v1()))
	{
		return n4;
	}

	if (is_equal(x, end.get_v1()))
	{
		return n1;
	}


	if (is_equal(y, begin.get_v2()))
	{
		return n5;
	}

	if (is_equal(y, end.get_v2()))
	{
		return n2;
	}

	if (is_equal(z, begin.get_v3()))
	{
		return n6;
	}

	if (is_equal(z, end.get_v3()))
	{
		return n3;
	}

}

Vector_3_float Box::return_centroid()
{
	return (end - begin) / 2.0f;
}

void Box::set_color(int color_)
{
	color = color_;
}

int Box::get_color()
{
	return color;
}

Box::~Box()
{
}