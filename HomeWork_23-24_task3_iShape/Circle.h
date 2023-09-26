#pragma once
#include "iShape.h"
class Circle : public iShape
{
private:

	int radius;

public:

	Circle();
	Circle(int x,int y, int radius);

	void Show()const override;
	void Save(ofstream& f_out)const override;
	void Load(ifstream& f_in)override;
	
	~Circle()override {}
};

