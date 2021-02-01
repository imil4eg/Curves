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

		Ellipse::Ellipse(double x, double y, double z, double xRadius, double yRadius) :
			Curve(x, y, z),
			pImpl(std::make_unique<Impl>(xRadius, yRadius))
		{
		}

		Ellipse::~Ellipse() = default;

		Point Ellipse::getPoint(double t) const
		{
			const Point& location{ Curve::getLocation() };

			double x{ location.x + (pImpl->m_xRadius * cos(t)) };
			double y{ location.y + (pImpl->m_yRadius * sin(t)) };

			return Point{ x, y, location.z };
		}

		Point Ellipse::getDerivative(double t) const
		{
			return Point{
				pImpl->m_xRadius * -sin(t),
				pImpl->m_yRadius * cos(t),
				0.0
			};
		}

		double Ellipse::getXRadius() const { return pImpl->m_xRadius; }
		double Ellipse::getYRadius() const { return pImpl->m_yRadius; }
	}
}