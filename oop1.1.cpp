#include <iostream>
#include <fstream>
#include <iomanip> 
#include "Point.h"

int main(int argc, char* argv[])
{
	Point ap{ 0.0, 0.0 };
	Point bp{ 0.0, 1.0 };
	Point cp{ 1.0, 0.0 };

	Triangle new_triangle(ap, bp, cp, "unstopable triangle");

	std::cout << "was created the triangle with name: " << new_triangle.nameoft << std::endl;

	double ap_x, bp_x, cp_x, ap_y, bp_y, cp_y;

	std::cin >> ap_x >> ap_y >> bp_x >> bp_y >> cp_x >> cp_y;

	Point ap2{ ap_x, ap_y };
	Point bp2{ bp_x, bp_y };
	Point cp2{ cp_x, cp_y };

	Triangle triangleR(ap2, bp2, cp2, "bory triangle");

	if (!triangleR.isFigure()) 
	{
		std::cout << "ERROR: it is impossible to construct a triangle from given points\n";
	}
	else
	{
		std::cout << std::setprecision(3) << "perimeterR = " << triangleR.perimeter_triangle << std::endl;

		std::cout << "\narea of R : " << triangleR.squareoft << std::endl;

		std::cin >> ap_x >> ap_y >> bp_x >> bp_y >> cp_x >> cp_y;

		Point ap3{ ap_x, ap_y };
		Point bp3{ bp_x, bp_y };
		Point cp3{ cp_x, cp_y };

		Triangle triangleP(ap3, bp3, cp3, "bory triangle\n");

		if (!triangleP.isFigure())
		{
			std::cout << "”ERROR: it is impossible to construct a triangle from given points\n";
		}
		else
		{
			std::cout << '\n' << triangleP.squareoft << " is P, and is R: " << triangleR.squareoft << std::endl;

			std::cout << std::setprecision(3) << "perimeterP = " << triangleP.squareoft;

			if (isEqual::is_equal(triangleR, triangleP))
			{
				std::cout << "The triangles are equal\n";
			}
			else { std::cout << "The triangles are not equal\n"; }
			
			if (isEqualSquare::is_equal_square(triangleR, triangleP))
			{
				std::cout << "The areas are equal\n";
			}
			else { std::cout << "The areas are not equal\n"; }

			triangleP.getA();
			triangleP.getB();
			triangleP.getC();

			triangleP.move(5.0);

			//std::cout << std::setprecision(3) << "TriangleP moved, new vertices = " << triangleP.A << triangleP.B << triangleP.C << std::endl;
			triangleP.getA();
			triangleP.getB();
			triangleP.getC();

		}
	}
	return 0;
}
