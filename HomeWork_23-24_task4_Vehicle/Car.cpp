#include "Car.h"
#include <iostream>
Car::Car() : Vehicle(3, 2, 50) {}


int Car::get_profit(int hours) const
{
    return Vehicle::get_profit(hours);
}

void Car::show() const
{
    std::cout << "\nАвтомобиль: ";
    Vehicle::show();
}

Car::~Car()
{
}
