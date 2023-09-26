#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : iShape(), base{ 0 }, height{ 0 } {}


Rectangle::Rectangle(int x, int y, int base, int height) : iShape(x, y), base{ base }, height{ height } {}


void Rectangle::Show() const
{
	cout << "\nПрямоугольник: ";
	cout << "\nКоордината x:  " << x << "\nКоордината y:  " << y;
	cout << "\nОснование:     " << base;
	cout << "\nВысота:        " << height;
}

void Rectangle::Save(ofstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out.write((char*)&x, sizeof(x));
	f_out.write((char*)&y, sizeof(y));
	f_out.write((char*)&base, sizeof(base));
	f_out.write((char*)&height, sizeof(height));
}

void Rectangle::Load(ifstream& f_in)
{
	if (!f_in.is_open()) return;
	f_in.read((char*)&x, sizeof(x));
	f_in.read((char*)&y, sizeof(y));
	f_in.read((char*)&base, sizeof(base));
	f_in.read((char*)&height, sizeof(height));
}

