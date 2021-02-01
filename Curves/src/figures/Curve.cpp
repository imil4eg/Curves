#include "figures/Curve.h"

namespace curves
{
	namespace figures
	{
		struct Curve::Impl
		{
			Point point;

			Impl(double x, double y, double z) :
				point{x, y, z}
			{
			}
		};

		Curve::Curve(double x, double y, double z) : 
			pImpl(std::make_unique<Impl>(x, y, z))
		{
		}

		Curve::~Curve() = default;

		const Point& Curve::getLocation() const
		{
			return pImpl->point;
		}
	}
}