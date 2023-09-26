#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle() : iShape(), radius{ 1 } {}

Circle::Circle(int x, int y, int radius) : iShape(x, y), radius{ radius } {}


void Circle::Show() const
{
	cout << "\nКруг: ";
	cout << "\nКоордината x:  " << x << "\nКоордината y:  " << y;
	cout << "\nРадиус:        " << radius;
}

void Circle::Save(ofstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out.write((char*)&x, sizeof(x));
	f_out.write((char*)&y, sizeof(y));
	f_out.write((char*)&radius, sizeof(radius));
}

void Circle::Load(ifstream& f_in)
{
	if (!f_in.is_open()) return;
	f_in.read((char*)&x, sizeof(x));
	f_in.read((char*)&y, sizeof(y));
	f_in.read((char*)&radius, sizeof(radius));
}

