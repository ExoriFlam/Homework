#pragma once
class RootsOfEquation
{
protected:

	double a;
	double b;

public:
	RootsOfEquation();
	RootsOfEquation(double a, double b);

	virtual void show_root()const = 0;
	

	virtual ~RootsOfEquation() {}
};

