#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:

	Car();

	int get_profit(int hours)const override;
	void show()const override;

	~Car()override;
};

