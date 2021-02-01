#pragma once

#include <memory>

#include "Curve.h"
#include "Ellipse.h"
#include "Export.h"

namespace curves
{
	namespace figures
	{
		class CURVESLIBRARY_API Circle : public Ellipse
		{
		public:
			Circle(double x, double y, double z, double radius) :
				Ellipse(x, y, z, radius, radius)
			{
			}

			~Circle() = default;

			double getRadius() const { return Ellipse::getXRadius(); }
		};
	}
}