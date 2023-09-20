#include <iostream>
#include "StudentAgr.h"
#include "ListTwoTemplate.h"



//Задание 1. Для уже существующих классов(MyArray, ListOneType, StudentAgr) добавьте
//           реализацию функционала для работы с файлами на языке С++:
//         − перегрузку потока для записи объекта класса в бинарный файл;
//         − перегрузку потока для чтения объекта класса из бинарного файла с
//           инициализацией этого объекта;
//         − метод для записи объекта класса в текстовый файл.

int main()
{
	system("chcp 1251>nul");

    ListTwoTemplate<MyString>sub1;
    sub1.push_back("python");
    sub1.push_back("C++");
    sub1.push_back("C");
    sub1.push_back("ASM");

    StudentAgr s2("Astafieva", "Tatiana", 20, "Step", MyArray(5, 6, 12), sub1);
    StudentAgr s3("Borisov", "Vasilii", 25, "UTM", MyArray(5, 7, 11), sub1);
    StudentAgr s4("Ciobanu", "Serghei", 30, "ASEM", MyArray(5, 8, 10), sub1);

    StudentAgr tmp;

    ofstream file_write("test_bin123.txt", ios::binary);
    cout << "\nЗапись из объекта StudentAgr в бинарный файл.\nПроверка открытия файла выполняется в перегрузке операции <<";

    cout << s2;
    file_write << s2;

    file_write.close();
    ifstream file_read("test_bin123.txt", ios::binary);
    cout << "\n";
    system("pause");
    system("cls");
    cout << "\nЧтение из бинарного файла в объект StudentAgr.";

    file_read >> tmp;
    file_read.close();
    cout << tmp;
    cout << "\n";
    system("pause");
    system("cls");
    fstream file_write_txt("test_txt123.txt", ios::out);
    cout << "\nЗапись объекта StudentAgr в файл .TXT";
    cout << "\n";
    system("pause");
    system("cls");
    tmp.save_to_txt(file_write_txt);
    file_write_txt.close();
    system("start test_txt123.txt");


    cout << "\n";
	system("pause");
    system("cls");
}

