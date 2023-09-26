#include "Cart.h"
#include <iostream>

Cart::Cart() : Vehicle(3, 3, 25) {}

int Cart::get_profit(int hours) const
{
	return Vehicle::get_profit(hours);
}

void Cart::show() const
{
	std::cout << "\nТелега: ";
	Vehicle::show();
}

Cart::~Cart()
{
}
