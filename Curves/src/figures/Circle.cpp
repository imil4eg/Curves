#include "figures/Circle.h"

namespace curves
{
	namespace figures
	{
		struct Circle::Impl
		{
			double m_radius;

			Impl(double radius) :
				m_radius{ radius }
			{
			}

			~Impl() = default;
		};

		Circle::Circle(double radius) :
			pImpl(std::make_unique<Impl>(radius))
		{
		}

		Circle::~Circle() = default;

		Point Circle::getPoint(double t) const 
		{
			double x{ (1.0 - (t * t)) / (1.0 + (t * t)) };
			double y{ (2.0 * t) / (1.0 + (t * t)) };

			return Point{ x, y, 0.0 };
		}

		double Circle::getDerivative(double t) const
		{
			return ((-2 * (t * t)) + 2) / (-4 * t);
		}

		double Circle::getRadius() const { return pImpl->m_radius; }
	}
}