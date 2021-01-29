#pragma once

#include <memory>

#include "Curve.h"
#include "Export.h"

namespace curves
{
	namespace figures
	{
		class CURVESLIBRARY_API Circle : public Curve
		{
		private:
			struct Impl;
			std::unique_ptr<Impl> pImpl;

		public:
			Circle(double radius);
			~Circle();

			Point getPoint(double t) const override;
			double getDerivative(double t) const override;
			double getRadius() const;
		};
	}
}