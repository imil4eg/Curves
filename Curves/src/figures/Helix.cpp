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
			double z{ location.z + (pImpl->m_step * t) };

			return Point{ x,y,z };
		}

		Point Helix::getDerivative(double t) const
		{
			return Point{
				cos(t) - (pImpl->m_radius * sin(t)),
				sin(t) + (pImpl->m_radius * cos(t)),
				pImpl->m_radius * pImpl->m_step
			};
		}
	}
}