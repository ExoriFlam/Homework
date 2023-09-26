#include "Square.h"
#include <iostream>


Square::Square() : iShape(), lenght_of_side{ 0 } {}

Square::Square(int x, int y, int lenght_of_side) : iShape(x, y), lenght_of_side{ lenght_of_side } {}

void Square::Show()const
{
	cout << "\nКвадрат: ";
	cout << "\nКоордината x:  " << x << "\nКоордината y:  " << y;
	cout << "\nДлина стороны: " << lenght_of_side;
}

void Square::Save(ofstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out.write((char*)&x, sizeof(x));
	f_out.write((char*)&y, sizeof(y));
	f_out.write((char*)&lenght_of_side, sizeof(lenght_of_side));
}


void Square::Load(ifstream& f_in)
{
	if (!f_in.is_open()) return;
	f_in.read((char*)&x, sizeof(x));
	f_in.read((char*)&y, sizeof(y));
	f_in.read((char*)&lenght_of_side, sizeof(lenght_of_side));

}

