#include <iostream>
#include <Windows.h> 
#include <MMSystem.h>
#include "Cat.h"
#include "Dog.h"
#include "Hamster.h"
#include "Parrot.h"
#include "iPet.h"
#include "MyString.h"

using std::cout;
using std::cin;
using std::endl;

//Задание 2. Создайте абстрактный базовый класс «Домашнее животное» и производные классы
//           «Собака», «Кошка», «Попугай», «Хомяк».С помощью конструктора установите имя каждого
//           животного и его характеристики.Реализуйте для каждого из классов функции :
//           Sound – издает звук животного(пишем текстом в консоль);
//           Show – отображает имя животного;
//           Type – отображает название его подвида.
//           Продемонстрируйте на примере инструмент динамического полиморфизма.
//           Как добавить звуковой файл : https://www.youtube.com/watch?v=2Fqh-8XqK0M
//           Примечание: В случае добавления звука задание отправить архивом проекта.


int main()
{
   /* В этой работе я решил попробовать сэкономить в запросах на выделение памяти следующим образом :
    я выделил фиксированный буфер размером iPet(размер всех классов одинаковый).
    При создании нового объекта в указателе iPet* ptr_pet, я размещаю его по адресу,
    ранее выделенному буферу : ptr_pet = new(pet_buf) Cat(name, color);
    В конце цикла необходим явный вызов деструктора   ptr_pet->~iPet(); 
    По завершении цикла очищаю буфер  delete[] pet_buf;
    */

    system("chcp 1251>nul");

    enum pets { CAT = 1, DOG, HAMSTER, PARROT };

    char* pet_buf = new char[sizeof(iPet)]; // Фиксированный буфер

    int chose = 0;

    MyString color;
    MyString name;
    iPet* ptr_pet = nullptr;
    while (GetKeyState(VK_ESCAPE) >= 0)
    {
        

        cout << "\nВыберите животное: ";
        cout << "\n1- Кошка \n2- Собака \n3- Хомяк \n4- Попугай\n->";

        do
        {
            cout << "\nВыберите животное (1-4): ";
            cin >> chose;

            while (cin.fail())
            {
                cout << "\nВведите цифру (1-4)";
                cin.clear();
                cin.ignore(255, '\n');
                cin >> chose;
            }

        } while (chose < 1 || chose > 4 );
       

        cout << "\nВведите кличку питомца :";
        cin.get();
        cin >> name;
        cout << "\nВведите цвет питомца :";
        cin >> color;
       
            

        switch (chose)
        {
        case CAT:
        {
            ptr_pet = new(pet_buf) Cat(name, color); // Создаем объект по адрессу pet_buf
                   
        }
            break;

        case DOG:
        {
            ptr_pet = new(pet_buf) Dog(name, color);
        }
            break;

        case HAMSTER:
        {
            ptr_pet = new(pet_buf) Hamster(name, color);
        }

            break;

        case PARROT:
        {
            ptr_pet = new(pet_buf) Parrot(name, color);
        }
            break;
        default:
            break;
        }
            
        if (ptr_pet)
        {
            ptr_pet->Show();
            ptr_pet->Type();
            ptr_pet->Sound();
           
        }

        ptr_pet->~iPet(); //явный вызов деструктора
        ptr_pet = nullptr;
        cout << endl;
        cout << "\nНажмите Esc для выхода.\n";
        system("pause");
        system("cls");

    }

    delete[] pet_buf;//Освобождаем память буфера
    
    
    
    return 0;
}

