#include <iostream>
#include "Visa.h"
#include "ForeignPassport.h"
//Задание 1. Создайте базовый класс Passport(паспорт), который будет содержать паспортную
//           информацию о гражданине Молдовы.С помощью механизма наследования, реализуйте класс
//           ForeignPassport(заграничный паспорт), производный от Passport.Напомним, что заграничный
//           паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного
//           паспорта.Реализовать метод для добавления визы.Примечание: для полей строкового типа
//           используйте класс MyString.Данные о визах необходимо хранить в списке(класс ListT).
int main()
{
    system("chcp 1251>nul");
    visa visa_md;
    
    visa_md.entry.customs_name = "Aeroport Chishinau";
    visa_md.entry.date_entrance = "22.09.2023";
    visa_md.entry.transport_type = "Airplain";
    
    visa_md.exit.customs_name = "Palanka";
    visa_md.exit.date_exit = "24.09.2023";
    visa_md.exit.transport_type = "autobus";

    ForeignPassport passport_1("Miller", "Hans", 'm',"German","12.01.1985","15.01.2001","15.01.2021","AB0094234");
    passport_1.add_visa(visa_md);
    ListTwoTemplate<ForeignPassport> at;
    at.push_back(passport_1);
    cout << at;

    system("pause");
}

