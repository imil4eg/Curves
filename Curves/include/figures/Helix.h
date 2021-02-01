#pragma once

#include <memory>

#include "Curve.h"
#include "Export.h"

namespace curves
{
	namespace figures
	{
		class CURVESLIBRARY_API Helix : public Curve
		{
		public:
			Helix(double x, double y, double z, double radius, double step);
			~Helix();

			Point getPoint(double t) const override;
			Point getDerivative(double t) const override;

		private:
			struct Impl;
			std::unique_ptr<Impl> pImpl;
		};
	}
}