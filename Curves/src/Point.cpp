#include "Point.h"

namespace curves
{
	std::ostream& operator<<(std::ostream& out, const Point& point)
	{
		out << "X: " << point.x << " Y: " << point.y << " Z: " << point.z;

		return out;
	}
}