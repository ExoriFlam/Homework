#pragma once
#include "iShape.h"

class Rectangle : public iShape
{
private:

	int base;
	int height;

public:

	Rectangle();
	Rectangle(int x, int y, int base, int height);

	void Show()const override;
	void Save(ofstream& f_out)const override;
	void Load(ifstream& f_in)override;
	
	~Rectangle()override {}
};

