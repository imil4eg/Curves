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

		Helix::Helix(double radius, double step) : 
			pImpl(std::make_unique<Impl>(radius, step))
		{
		}

		Helix::~Helix() = default;

		Point Helix::getPoint(double t) const
		{
			double x{ pImpl->m_radius * cos(t) };
			double y{ pImpl->m_radius * sin(t) };
			double z{ pImpl->m_step * t };

			return Point{ x,y,z };
		}

		double Helix::getDerivative(double t) const
		{
			return (sin(t) + (pImpl->m_radius * cos(t))) / (cos(t) - (pImpl->m_radius * sin(t)));
		}
	}
}