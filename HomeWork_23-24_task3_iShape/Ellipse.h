#pragma once
#include "iShape.h"
class Ellipse : public iShape
{
private:

	int width;
	int height;

public:
	Ellipse();
	Ellipse(int x, int y, int width, int height);

	void Show()const override;
	void Save(ofstream& f_out)const override;
	void Load(ifstream& f_in)override;
	
	~Ellipse()override {};
};

