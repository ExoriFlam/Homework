#include "QuadraticEquation.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::setprecision;
QuadraticEquation::QuadraticEquation(double a, double b, double c) : RootsOfEquation(a, b), c{ c } {}

void QuadraticEquation::show_root() const
{
	
	int discriminant = b * b - 4 * a * c;
	cout << "\n Квадратное уравнение : " << a << "x^2 + " << b << "x + " << c << " = 0";
	if (discriminant > 0)
	{
		cout << "\nДискриминант : " << discriminant << " . Уравнение имеет два корня!";
		cout << setprecision(2) << "\nКорень квадратного уравнения x1 = " << (-b + sqrt(discriminant)) / (2 * a);
		cout << setprecision(2) << "\nКорень квадратного уравнения x2 = " << (-b - sqrt(discriminant)) / (2 * a);
	}
	else if (discriminant == 0)
	{
		cout << setprecision(2) << "\nКорень квадратного уравнения х = " << -b / (2 * a);
	}
	else
	{
		cout << "\nКореней квадратного уравнения нет.";
	}

}

QuadraticEquation::~QuadraticEquation() {}

