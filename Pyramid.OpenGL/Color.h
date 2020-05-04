#ifndef COLOR_H
#define COLOR_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <vector>
#include <string>

struct Color
{
	float red, green, blue, alpha;

	Color() : red(0), green(0), blue(0), alpha(0) {};
	Color(std::vector<std::string> values);
	Color(float red, float green, float blue);
	Color(float red, float green, float blue, float transparency);
};

#endif // !COLOR_H
