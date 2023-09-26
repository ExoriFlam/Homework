#include <iostream>
#include <iomanip>
#include "RootsOfEquation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"

using namespace std;

int main()
{

    system("chcp 1251>nul");
    
    RootsOfEquation** roots_of_eq = new RootsOfEquation * [6] {nullptr};

    roots_of_eq[0] = new LinearEquation(0, 0);
    roots_of_eq[1] = new LinearEquation(0, 4);
    roots_of_eq[2] = new LinearEquation(3, 5);

    roots_of_eq[3] = new QuadraticEquation(2, 5, -3);
    roots_of_eq[4] = new QuadraticEquation(1, -4, 4);
    roots_of_eq[5] = new QuadraticEquation(3, 2, 7);

    for (int i = 0; i < 6;i++)
    {
        roots_of_eq[i]->show_root();
        cout << "\n=============================\n";
    }



    for (int i = 0; i < 6; i++)
    {
        delete roots_of_eq[i];
    }
    delete[]roots_of_eq;

    system("pause");
   
}