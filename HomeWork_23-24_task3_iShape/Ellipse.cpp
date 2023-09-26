#include "Ellipse.h"
#include <iostream>
using namespace std;

Ellipse::Ellipse() : iShape(), width{ 0 }, height{ 0 } {}


Ellipse::Ellipse(int x, int y, int width, int height) : iShape(x, y), width{ width }, height{ height } {}

void Ellipse::Show() const
{
	cout << "\nЭллипс:";
	cout << "\nКоордината x:  " << x << "\nКоордината y:  " << y;
	cout << "\nВысота:        " << height;
	cout << "\nШирина:        " << width;
}

void Ellipse::Save(ofstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out.write((char*)&x, sizeof(x));
	f_out.write((char*)&y, sizeof(y));
	f_out.write((char*)&height, sizeof(height));
	f_out.write((char*)&width, sizeof(width));
}

void Ellipse::Load(ifstream& f_in)
{
	if (!f_in.is_open()) return;
	f_in.read((char*)&x, sizeof(x));
	f_in.read((char*)&y, sizeof(y));
	f_in.read((char*)&height, sizeof(height));
	f_in.read((char*)&width, sizeof(width));
}


