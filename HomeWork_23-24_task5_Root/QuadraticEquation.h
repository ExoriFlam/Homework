#pragma once
#include "RootsOfEquation.h"
class QuadraticEquation : public RootsOfEquation
{
private:

	double c;

public:

	QuadraticEquation(double a, double b, double c);

	void show_root()const override;

	~QuadraticEquation()override;
};

