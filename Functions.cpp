#include "Header.h"
#include "Functions.h"

bool is_equal(float left, float right) // if(left == right)
{
	return fabs(left - right) < epsi;
}

bool Less(float left, float right, bool orequal) // Новое меньше if(left < right) ************ -> Добавить true в параметры: if(left<=right)
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left < right);

}

bool Greater(float left, float right, bool orequal) // if(left > right) ****************** -> Добавить true в параметры: if(left>=right)
{

	if (fabs(left - right) < epsi)
	{
		return (orequal);
	}

	return (left > right);

}