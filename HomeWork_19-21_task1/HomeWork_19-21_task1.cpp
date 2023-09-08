#include <iostream>
#include "MyBinTree.h"
using namespace std;
//  Тема: Бинарное дерево поиска.Работа с файлами, Си.
//  Задание 1. Для уже существующего класса Бинарного дерева поиска(MyTree) реализуйте
//             методы для :
//             -записи данных дерева в текстовый файл;
//             -записи данных дерева в бинарный файл;
//             -чтения данных из бинарного файла с инициализацией другого дерева.
//  Продемонстрируйте работу методов на примерах.



int main()
{
    system("chcp 1251>nul");
    MyBinTree a, b;
    a.add(25);
    a.add(16);
    a.add(35);
    a.add(18);
    a.add(20);
    
    cout << "\nОбъект для записи в тхт\n";
    a.show();
    cout << endl;
    FILE* f, * f2;
    errno_t err, err1, err2;
    err = fopen_s(&f, "BinTreeinTxt.txt", "w");

    if (!err)
    {
        a.save_to_txt(f);
        fclose(f);

    }
    else
    {
        cout << "\nОшибка записи файла";
    }

    system("pause");
    system("start BinTreeinTxt.txt");
    system("pause");
    system("cls");
    ////////////////////////////////////////////////////
    cout << "\nЗапись-чтенье в бинарном формате\n";
    err1 = fopen_s(&f, "BinTreeinbin.txt", "wb");
    if (!err1)
    {
        a.save_to_bin(f);
        fclose(f);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }
    err2 = fopen_s(&f2, "BinTreeinbin.txt", "rb");
    if (!err2)
    {

        b.read_from_bin(f2);
        fclose(f2);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }
    cout << "\nОбъект прочитанный из бинарного файла:\n";
    b.show();
    cout << endl;
    system("pause");
    system("start BinTreeinbin.txt");
    system("pause");
    system("cls");
}