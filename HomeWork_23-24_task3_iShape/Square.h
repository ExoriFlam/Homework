#pragma once
#include "iShape.h"
class Square : public iShape
{
private:

	int lenght_of_side;

public:
	Square();
	Square(int x, int y, int lenght_of_side);

	void Show()const override;
	void Save(ofstream& f_out)const override;
	void Load(ifstream& f_in)override;
	
	~Square()override {};
};

