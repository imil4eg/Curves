#include <math.h>

#include "figures/Ellipse.h"

namespace curves
{
	namespace figures
	{
		struct Ellipse::Impl
		{
			double m_xRadius;
			double m_yRadius;

			Impl(double xRadius, double yRadius) : 
				m_xRadius{xRadius},
				m_yRadius{yRadius}
			{
			}

			~Impl() = default;
		};

		Ellipse::Ellipse(double xRadius, double yRadius) :
			pImpl(std::make_unique<Impl>(xRadius, yRadius))
		{
		}

		Ellipse::~Ellipse() = default;

		Point Ellipse::getPoint(double t) const
		{
			double x{ pImpl->m_xRadius * cos(t) };
			double y{ pImpl->m_yRadius * sin(t) };

			return Point{ x, y, 0.0 };
		}

		double Ellipse::getDerivative(double t) const
		{
			return (sin(t) + (pImpl->m_yRadius * cos(t))) / (cos(t) - (pImpl->m_xRadius * sin(t)));
		}
	}
}