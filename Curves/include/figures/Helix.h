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
		private:
			struct Impl;
			std::unique_ptr<Impl> pImpl;

		public:
			Helix(double radius, double step);
			~Helix();

			Point getPoint(double t) const override;
			double getDerivative(double t) const override;
		};
	}
}