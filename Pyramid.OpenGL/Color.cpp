#include <stdexcept>
#include "Color.h"

Color::Color(std::vector<std::string> values): red(0), green(0), blue(0), alpha(0)
{
	if (values.size() > 0)
	{
		if (values.size() > 4)
		{
			throw std::runtime_error("The colors values cannot be more than 4 (red, green, blue and alpha)");
		}

		this->red = stof(values[0]);
		this->green = stof(values[1]);
		this->blue = stof(values[2]);

		if (values.size() == 4)
		{
			this->alpha = stof(values[3]);
		}
	}
}

Color::Color(float red, float green, float blue) : alpha(0)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::Color(float red, float green, float blue, float transparency) : Color(red, green, blue)
{
	this->alpha = transparency;
}
