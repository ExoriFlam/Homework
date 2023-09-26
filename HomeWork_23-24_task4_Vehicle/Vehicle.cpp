#include <iostream>
#include "Vehicle.h"

using std::cout;

Vehicle::Vehicle()
{
	this->passage_cap = 0;
	this->cargo_cap = 0;

}

Vehicle::Vehicle(int pass_cap, int cargo_cap, int speed)
{
	this->passage_cap = pass_cap;
	this->cargo_cap = cargo_cap;
	this->speed = speed;
}

int Vehicle::get_profit(int hours)const
{
	int profit = 0;
	int cost_per_km = 3; // км 3 ле¤ 
	int dist = hours * this->speed;
	profit = ((this->passage_cap + this->cargo_cap) * cost_per_km) * dist;

	return profit;
}

void Vehicle::show() const
{
	cout << "\n Вместимость пассажиров  : " << this->passage_cap;
	cout << "\n Вместимость груза в шт. : " << this->cargo_cap;
	cout << "\n Средняя скорость в км/ч : " << this->speed;
}

Vehicle::~Vehicle()
{
}
