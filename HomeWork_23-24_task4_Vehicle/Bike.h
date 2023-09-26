#pragma once
#include "Vehicle.h"

class Bike : public Vehicle
{
public:
	Bike();

	int get_profit(int hours)const override;
	void show()const override;

	~Bike()override;
};

