#define _USE_MATH_DEFINES

#include <math.h>

#include "figures/Helix.h"

namespace curves
{
	namespace figures
	{
		struct Helix::Impl
		{
			double m_radius;
			double m_step;

			Impl(double radius, double step) : 
				m_radius{ radius },
				m_step{ step }
			{
			}

			~Impl() = default;
		};

		Helix::Helix(double x, double y, double z, double radius, double step) : 
			Curve(x, y, z),
			pImpl(std::make_unique<Impl>(radius, step))
		{
		}

		Helix::~Helix() = default;

		Point Helix::getPoint(double t) const
		{
			const Point& location{ Curve::getLocation() };
			double x{ location.x + (pImpl->m_radius * cos(t)) };
			double y{ location.y + (pImpl->m_radius * sin(t)) };
			double z{ location.z + ((pImpl->m_step * t) / (M_PI * 2)) };

			return Point{ x,y,z };
		}

		Point Helix::getDerivative(double t) const
		{
			return Point{
				pImpl->m_radius * -sin(t),
				pImpl->m_radius * cos(t),
				pImpl->m_step / (2 * M_PI)
			};
		}
	}
}