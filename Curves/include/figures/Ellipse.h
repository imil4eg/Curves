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
		public:
			Ellipse(double x, double y, double z, double xRadius, double yRadius);
			virtual ~Ellipse();

			Point getPoint(double t) const override;
			Point getDerivative(double t) const override;

			double getXRadius() const;
			double getYRadius() const;
		
		private:
			struct CURVESLIBRARY_API Impl;
			std::unique_ptr<Impl> pImpl;
		};
	}
}