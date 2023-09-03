#include <iostream>
#include "Coord.h"
#include "ListTwo.h"
#include "ListTwoTemplate.h"
using namespace std;
//Встреча № 18
//Задание 2. В уже существующий класс Двунаправленного списка(ListTwo) добавьте реализацию
//           следующих методов :
//          − добавление элемента в начало списка;
//          − добавление элемента(значение передается вторым параметром) после элемента списка
//            со значением первого параметра;
//          − удаление первого элемента списка;
//          − удаление последнего элемента списка;
//          − удаление всех элементов списка;
//          − конструктор копирования;
//          − конструктор с перемещением;
//          − перегрузку оператора присваивания(= );
//          − перегрузку оператора присваивания(= ) с перемещением;
//          − перегрузку операторов << , >> ;
//          − перегрузку оператора + для двух списков(конкатенация);
//
//Задание 3. Реализуйте шаблон класса Двунаправленного списка.Продемонстрируйте работу
//           шаблона на стандартных и пользовательских типах(например, класс Координата).
//Дополнительно:
//Задание 4. В уже существующий класс Двунаправленного списка(ListTwo) добавьте реализацию следующих методов :
//           − добавление элемента(значение передается вторым параметром) до элемента списка со значением первого параметра;
//           − удаление элемента списка по значению;
//           − удаление элемента списка по позиции(порядковому номеру).В методе, осуществить проверку на существование переданной позиции в списке.
//           − добавление элемента списка по позиции(порядковому номеру).В методе, осуществить проверку на существование переданной позиции в списке.
//            При этом элемент списка, занимавший эту позицию, становится следующим.



void show(const ListTwo& int_list,const ListTwoTemplate<Coord>& coord_list)
{
    string line(60, '-');
    line += '\n';

    cout << '\n' << int_list;
    int_list.show();
    cout << "\nКолличество элементов в списке int_list: " << int_list.get_count() << '\n';
    

    cout << '\n' << coord_list;
    coord_list.show();
    cout << "\nКолличество элементов в списке coord_list: " << coord_list.get_count() << '\n';
    
    cout << line;
}

int main()
{
    system("chcp 1251>nul");
    string line(60, '-');
    line += '\n';
    cout << __LINE__ << "-ая строка\nТема: Двунаправленного списка (ListTwo) по умолчанию тип int.\nТестируем сразу шаблон ListTwoTemplate\n"<<line;

    ListTwo int_list, int_list1;
    ListTwoTemplate<Coord> coord_list, coord_list1;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода push_back().\nint_list.push_back(1);...\ncoord_list.push_back({ 1,1 });....\n" << line;

    int_list.push_back(1); int_list.push_back(2); int_list.push_back(3); int_list.push_back(4); int_list.push_back(5);
    coord_list.push_back({ 1,1 }); coord_list.push_back({ 2,2 });
    coord_list.push_back({ 3,3 }); coord_list.push_back({ 4,4 }); coord_list.push_back({ 5,5 });

  
    show(int_list, coord_list);

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода push_front().\n->int_list.push_front(0);...\n->coord_list.push_front({ 0,0 });..\n" << line;

    int_list.push_front(0); int_list.push_front(-1); int_list.push_front(-2);
    coord_list.push_front({ 0,0 }); coord_list.push_front({ -1,-1 }); coord_list.push_front({ -2,-2 });

    
    show(int_list, coord_list);

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода insert_before_found_data().\n->int_list.insert_before_found_data(4, 7);\n->coord_list.insert_before_found_data({ 4,4 }, { 7,7 });\n" << line;
    int_list.insert_before_found_data(4, 7);
    coord_list.insert_before_found_data({ 4,4 }, { 7,7 });
    show(int_list, coord_list);
    
    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест методов pop_back pop_front.\n->int_list.pop_back(); int_list.pop_front();\n->coord_list.pop_back(); coord_list.pop_front();\n" << line;
    
    show(int_list, coord_list);

    int_list.pop_back(); int_list.pop_front();
    coord_list.pop_back(); coord_list.pop_front();

    show(int_list, coord_list);

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода clear().\n-> int_list.clear(); int_list.pop_front();\n->coord_list.clear();\n" << line;

    
    int_list.clear();
    coord_list.clear(); 

    show(int_list, coord_list);


    int_list.push_back(1); int_list.push_back(2); int_list.push_back(3); int_list.push_back(4); int_list.push_back(5);
    coord_list.push_back({ 1,1 }); coord_list.push_back({ 2,2 });
    coord_list.push_back({ 3,3 }); coord_list.push_back({ 4,4 }); coord_list.push_back({ 5,5 });

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест конструкторов копирования перемещения. " << line;

    ListTwo int_cpy_list = int_list;
    ListTwoTemplate<Coord> coord_cpy_list(coord_list);
    cout << "\nВывод копии.\nListTwo int_cpy_list = int_list;\nListTwoTemplate<Coord> coord_cpy_list(coord_list);\n";
    show(int_cpy_list, coord_cpy_list);

    ////////
    ListTwo int_move_list = move(int_cpy_list);
    ListTwoTemplate<Coord> coord_move_list(move(coord_cpy_list));
    cout << "\nВывод копии c перемещением.\nListTwo int_move_list = move(int_cpy_list);\nListTwoTemplate<Coord> coord_move_list(move(coord_cpy_list));\n";
    show(int_move_list, coord_move_list);
    ///////
    int_list1 = int_list;
    coord_list1 = coord_list;
    cout << "\nВывод присваивания.\nint_list1 = int_list;\ncoord_list1 = coord_list;\n";
    show(int_list1, coord_list1);
    ///////
    int_list = move(int_list1);
    coord_list = move(coord_list1);
    cout << "\nВывод присваивания c перемещением.\nint_list = move(int_list1);\ncoord_list = move(coord_list1);\n";
    show(int_list, coord_list);

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода cin>> для int_list.\n" << line;

 
    cin >> int_list; 
  

    show(int_list, coord_list);
    
    system("pause");
    system("cls");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест operator+ конкатинация.\n->int_list = int_list + int_move_list;\n-> coord_list = coord_list + coord_move_list;\n" << line;

    int_list = int_list + int_move_list;
    coord_list = coord_list + coord_move_list;

    show(int_list, coord_list);

    system("pause");
    system("cls");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода insert_before_found_data.\n->int_list.insert_before_found_data(4, 333);\n->coord_list.insert_before_found_data({ 4, 4 }, { 333,333 });\n" << line;

    int_list.insert_before_found_data(4, 333);
    coord_list.insert_before_found_data({ 4, 4 }, { 333,333 });
   
    show(int_list, coord_list);

    system("pause");
    system("cls");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << __LINE__ << "-ая строка\nТест метода int_list.erase_by_data();.\n->int_list.erase_by_data(333);\n->coord_list.erase_by_data({ 333,333 });\n" << line;

    show(int_list, coord_list);

    int_list.erase_by_data(333);
    coord_list.erase_by_data({ 333,333 });

    show(int_list, coord_list);

    system("pause");
    system("cls");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << __LINE__ << "-ая строка\nТест метода int_list.erase_by_index();.\n->int_list.erase_by_index(8);\n->coord_list.erase_by_index(8);\n" << line;

    show(int_list, coord_list);

    int_list.erase_by_index(8);
    coord_list.erase_by_index(8);

    show(int_list, coord_list);

    system("pause");
    system("cls");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода insert_before_index.\n->int_list.insert_before_index(8);\n->coord_list.insert_before_index(8);\n" << line;

    show(int_list, coord_list);

    int_list.insert_before_index(8);
    coord_list.insert_before_index(8);
    

    show(int_list, coord_list);

    system("pause");
    system("cls");

    return 0;
   
}