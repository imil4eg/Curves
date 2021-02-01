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
			Curve(double x, double y, double z);
			virtual ~Curve();
			virtual Point getPoint(double t) const = 0;
			virtual Point getDerivative(double t) const = 0;

			const Point& getLocation() const;

		private:
			struct Impl;
			std::unique_ptr<Impl> pImpl;
		};
	}
}