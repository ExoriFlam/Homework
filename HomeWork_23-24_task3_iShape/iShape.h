#pragma once
#include <fstream>
using namespace std;
class iShape
{
protected:

	int x;
	int y;

public:

	iShape();
	iShape(int x, int y);

	virtual void Show()const = 0;
	virtual void Save(ofstream& f_out)const = 0;
	virtual void Load(ifstream& f_in) = 0;

	virtual ~iShape() {}
};

