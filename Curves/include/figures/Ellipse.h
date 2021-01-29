#pragma once

#include <memory>

#include "Curve.h"
#include "Export.h"

namespace curves
{
	namespace figures
	{ 
		class CURVESLIBRARY_API Ellipse : public Curve
		{
		private:
			struct CURVESLIBRARY_API Impl;
			std::unique_ptr<Impl> pImpl;

		public:
			Ellipse(double xRadius, double yRadius);
			~Ellipse();

			Point getPoint(double t) const override;
			double getDerivative(double t) const override;
		};
	}
}