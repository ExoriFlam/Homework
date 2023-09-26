#include <iostream>
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Cart.h"
using namespace std;

int main()
{
    system("chcp 1251>nul");


    char vehicle_buf[sizeof(Vehicle)]; // Создаем буфер блок памяти на стеке

    Vehicle* veh_ptr;
    int input;
    cout << "\nВведите количество часов, чтобы узнать заработок разных транспортных средств:\n->";
    cin >> input;

    veh_ptr = new(vehicle_buf) Bike; // создаем объек по адресу блока памяти
    veh_ptr->show();
    cout << "\n Доход за " << input << " часов составил: " << veh_ptr->get_profit(input) << " лей";
    //veh_ptr->~Vehicle();     явный вызов деструктора не требуется, мы каждый раз переписываем буфер

    veh_ptr = new(vehicle_buf) Car;
    veh_ptr->show();
    cout << "\n Доход за " << input << " часов составил: " << veh_ptr->get_profit(input) << " лей";
    

    veh_ptr = new(vehicle_buf) Cart;
    veh_ptr->show();
    cout << "\n Доход за " << input << " часов составил: " << veh_ptr->get_profit(input) << " лей";

    veh_ptr->~Vehicle();
    veh_ptr = nullptr;

    cout << endl;
    system("pause");
}