#pragma once
#include "RootsOfEquation.h"
class LinearEquation : public RootsOfEquation
{
public:

	LinearEquation(double a, double b);

	void show_root()const override;
	
	~LinearEquation()override;
};

