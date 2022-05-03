#pragma once

#include "Header.h"

class Light
{
private:

	float x_;
	float y_;
	float z_;

public:
	Light();
	~Light();

	void set_x(const float);
	void set_y(const float);
	void set_z(const float);

	float get_x();
	float get_y();
	float get_z();

};