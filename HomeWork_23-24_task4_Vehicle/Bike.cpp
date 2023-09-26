#include "Bike.h"
#include <iostream>



Bike::Bike() : Vehicle(1, 1, 15) {} 


int Bike::get_profit(int hours) const
{
	return Vehicle::get_profit(hours);
}

void Bike::show() const
{
	std::cout << "\nВелосипед: ";
	Vehicle::show();
}


Bike::~Bike()
{
}
