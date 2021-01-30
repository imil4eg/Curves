#pragma once

#include <iostream>

#include "Export.h"

namespace curves
{
	struct CURVESLIBRARY_API Point
	{
		double x;
		double y;
		double z;
	};

	CURVESLIBRARY_API std::ostream& operator<<(std::ostream& out, const Point& point);
}