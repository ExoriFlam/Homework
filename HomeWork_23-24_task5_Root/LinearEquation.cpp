#include "LinearEquation.h"
#include <iostream>
#include <iomanip>

using std::cout;

LinearEquation::LinearEquation(double a, double b) : RootsOfEquation(a, b) {}


void LinearEquation::show_root()const
{
	cout << "\nЛинейное уравнение : " << a << "x + " << b << " = 0";
	if (a)
	{
		cout << "\nКорень линейного уравнения: x = " << std::setprecision(2) << - b / a;
	}
	else
	{
		if (!b)
		{
			cout << "\nУ данного линейного уравнения есть неограниченное число решений";
		}
		else
		{
			cout << "\nУ данного линейного уравнения нет корней";
		}
	}
}


LinearEquation::~LinearEquation()
{

}
