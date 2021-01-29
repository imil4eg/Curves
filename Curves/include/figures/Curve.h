#pragma once

#include <memory>

#include "Export.h"
#include "Point.h"

namespace curves
{
	namespace figures
	{
		class CURVESLIBRARY_API Curve
		{
		public:
			virtual ~Curve() = default;
			virtual Point getPoint(double t) const = 0;
			virtual double getDerivative(double t) const = 0;
		};
	}
}