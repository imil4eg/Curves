#define _USE_MATH_DEFINES

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <math.h>
#include <memory>
#include <iostream>

#include "figures/Figures.h"

void printCoordiantesAt(const std::vector<std::unique_ptr<curves::figures::Curve>>& curves, double t)
{
	for (auto it = curves.cbegin(); it != curves.cend(); ++it)
	{
		std::cout << "Point coordinates: " << it->get()->getPoint(t) << " and derivative: " 
				  << it->get()->getDerivative(t) << '\n';
	}
}

std::vector<curves::figures::Circle*> getCircles(const std::vector<std::unique_ptr<curves::figures::Curve>>& curves)
{
	std::vector<curves::figures::Circle*> circles;
	for (auto it = curves.begin(); it != curves.end(); ++it)
	{
		auto circle{ dynamic_cast<curves::figures::Circle*>(it->get()) };

		if (circle != nullptr)
		{
			circles.push_back(circle);
		}
	}

	return circles;
}

void displayCircles(const std::vector<curves::figures::Circle*>& circles)
{
	for (auto it = circles.begin(); it != circles.end(); ++it)
	{
		std::cout << (*it)->getRadius() << ' ';
	}
}

double parallelAccumulate(const std::vector<curves::figures::Circle*>& circles)
{
	double sum{};

#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < circles.size(); ++i)
	{
		sum += circles[i]->getRadius();
	}

	return sum;
}

int main()
{
	std::vector<std::unique_ptr<curves::figures::Curve>> curves;
	curves.reserve(6);
	curves.push_back(std::make_unique<curves::figures::Circle>(5));
	curves.push_back(std::make_unique<curves::figures::Ellipse>(3, 7));
	curves.push_back(std::make_unique<curves::figures::Helix>(10, 1));
	curves.push_back(std::make_unique<curves::figures::Ellipse>(6, 2));
	curves.push_back(std::make_unique<curves::figures::Circle>(8));
	curves.push_back(std::make_unique<curves::figures::Circle>(3));

	printCoordiantesAt(curves, M_PI / 4);

	std::vector<curves::figures::Circle*> circles{ getCircles(curves) };

	std::cout << "Circles radiuses before sort: ";

	displayCircles(circles);

	std::cout << '\n';

	std::sort(circles.begin(), circles.end(), 
		[](const curves::figures::Circle* left, const curves::figures::Circle* right)
		{
			return left->getRadius() < right->getRadius();
		});

	std::cout << "Circles radiuses after sort: ";

	displayCircles(circles);

	std::cout << '\n';

	double circlesRadSum = parallelAccumulate(circles);

	std::cout << "Circles radius sum: " << circlesRadSum;
}
	