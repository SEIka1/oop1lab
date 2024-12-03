#include <iostream>
#include <fstream>
#include <iomanip> 
#include "Triangle.h"


int main(int argc, char* argv[])
{

	double ap_x, bp_x, cp_x, ap_y, bp_y, cp_y;

    try{
	    std::cin >> ap_x >> ap_y >> bp_x >> bp_y >> cp_x >> cp_y;
    }
    catch(std::runtime_error& e){
        std::cout << "error: " << e.what();
        return 0;
    }

	Point ap2{ ap_x, ap_y };
	Point bp2{ bp_x, bp_y };
	Point cp2{ cp_x, cp_y };

	Triangle triangleR(ap2, bp2, cp2);

	if (!triangleR.isTriangle()) 
	{
		std::cout << "ERROR: it is impossible to construct a triangle from given points\n";
	}
	else
	{
		std::cout << std::setprecision(3) << "perimeterR = " << triangleR.getPerimeter() << std::endl;

		std::cout << "\narea of R : " << triangleR.getSquare() << std::endl;

		std::cin >> ap_x >> ap_y >> bp_x >> bp_y >> cp_x >> cp_y;

		Point ap3{ ap_x, ap_y };
		Point bp3{ bp_x, bp_y };
		Point cp3{ cp_x, cp_y };

		Triangle triangleP(ap3, bp3, cp3);

		if (!triangleP.isTriangle())
		{
			std::cout << "”ERROR: it is impossible to construct a triangle from given points\n";
		}
		else
		{
			std::cout << '\n' << triangleP.getSquare() << " is P, and is R: " << triangleR.getSquare() << std::endl;

			std::cout << std::setprecision(3) << "perimeterP = " << triangleP.getSquare();

			if (triangleP.isEqual(triangleR))
			{
				std::cout << "The triangles are equal\n";
			}
			else { std::cout << "The triangles are not equal\n"; }
			
			if (triangleP.isEqualSquare(triangleR))
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

