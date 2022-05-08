#pragma once

#include "Header.h"
#include "Vector3d.h"

class Light
{
private:

	Vector3d position;

public:
	
	void set_position(const double, const double, const double);

	Vector3d get_position(void);

};