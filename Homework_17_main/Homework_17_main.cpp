#include <iostream>
#include "List_1.h"
using namespace std;

//Встреча  17
//Тема: Динамические структуры данных.Односвязный список.

int main()
{
  
    system("chcp 1251>nul");
    List_1 list,list1,list2;
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');
    list.push_back('f');
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << "\nВ нашем листе 6 элементов a, b, c, d, e, f\n";
    cout << __LINE__ << "-ая строка\nТест метода pop_back в паре с push_back. Удалим два элемента и добавим '1' \n";
    list.pop_back();
    list.pop_back();
    list.push_back('1');
    cout << '\n' << list << '\n';
    cout << "\nКолличество элементов в списке list: " << list.get_count() << '\n';
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода clear(). Удалим все элементы выведим и добавим 1,2,3,4,5 \n";
    list.clear(); 
    cout << '\n' << list << '\n';
    list.push_back('1');
    list.push_back('2');
    list.push_back('3');
    list.push_back('4');
    list.push_back('5');
    cout << '\n' << list << '\n';
    cout << "\nКолличество элементов в списке list : " << list.get_count() << '\n';
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////

    cout << __LINE__ << "-ая строка\nТест метода  get_index_by_data('3'). Должен вернуть индекс 2 \n";
    cout << "\n->" << list.get_index_by_data('3')<<'\n';

    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода  get_data_by_index('0'). Должен вернуть индекс 1 \n";
    cout << "\n->" << list.get_data_by_index(0) << '\n';

    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест операции присваивания. list1 = list, list1 pop и pushback \n";
    list1 = list;
    list1.pop_back();
    list1.push_back('a');
    cout << list1;
    cout << __LINE__ << "-ая строка\nКолличество элементов в списке list1 : " << list1.get_count() << '\n';

    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout <<__LINE__ <<"-ая строка\nТест операций ==, !=, >=, <=. list = 1,2,3,4,5 list1 = 1,2,3,4,5 \n";
    list1.pop_back();
    list1.push_back('5');
    cout << list;
    if (list <= list1) // == != >= <= < >
    {
        cout << "\nTrue\n";
    }
    else
    {
        cout << "\nFalse\n";
    }
    
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест операции +. list2 = list + list1, list2 pop и pushback \n";
    list2 = list + list1;
    cout << '\n' << list2 << '\n';
    list2.pop_back();
    list2.push_back('a');
    cout << list2;
    cout << "\nКолличество элементов в списке list2 : " << list2.get_count() << '\n';

    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест операции унарный -. list2 = -list2. list2 pop и pushback \n";
    list2 = -list2;
    list2.pop_back();
    list2.push_back('a');
    cout << list2;
    cout << "\nКолличество элементов в списке list2 : " << list2.get_count() << '\n';
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест операции унарный * . list2 = list * list1 \n";
  
    list.clear();
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');
    list.push_back('f');
    list1.clear();
    list1.push_back('a');
    list1.push_back('1');
    list1.push_back('c');
    list1.push_back('2');
    list1.push_back('e');
    list1.push_back('3');
    cout << "\nList->" << list << '\n';
    cout << "\nList1->" << list1 << '\n';
    list2 = list * list1;
    cout << "\nList2->" << list2 << '\n';
    cout << "\nКолличество элементов в списке list2 : " << list2.get_count() << '\n';
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода insert_elem_by_index(1) . Добавит пустой элемент по индексу \n";
    list2.insert_elem_by_index(1);
    cout << "\nList2->" << list2 << '\n';
    cout << "\nКолличество элементов в списке list2 : " << list2.get_count() << '\n';
    system("pause");
    system("cls");
    ///////////////////////////////////////////////////////////////////////////////////////////////
    cout << __LINE__ << "-ая строка\nТест метода erase_by_index(2)  \n";
    list2.erase_by_index(2);
    cout << "\nList2->" << list2 << '\n';
    cout << "\nКолличество элементов в списке list2 : " << list2.get_count() << '\n';
    system("pause");
    system("cls");

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /*Встреча № 18
      Задание 1.
          В уже существующий класс Односвязного списка(List_1) добавьте реализацию
          следующих методов :
        − добавление элемента(значение передается вторым параметром) до элемента списка со
          значением первого параметра;
        − добавление элемента по позиции(порядковому номеру), при этом элемент списка,
          занимавший эту позицию, становится следующим;
        − удаление значения по позиции(порядковому номеру);
        − перегрузку оператора >> для ввода данных одного элемента;
        − конструктор с перемещением;
        − перегрузку оператора присваивания(= ) с перемещением;*/
    cout << __LINE__ << "-ая строка\nЧасть заданий связанная с List_1  с 18-ой встречи \n";
    system("pause");
    system("cls");

    cout << __LINE__ << "-ая строка\nТест метода insert_data_before_index(2,'9')  \n";
    list2.insert_data_before_index(2, '9');
    cout << "\nList2->" << list2 << '\n';
    system("pause");
    system("cls");

    cout << __LINE__ << "-ая строка\nТест метода insert_elem_by_index(2)  \n";
    list2.insert_elem_by_index(2);
    cout << "\nList2->" << list2 << '\n';
    system("pause");
    system("cls");

    cout << __LINE__ << "-ая строка\nТест метода erase_by_index(0) \n";
    list2.erase_by_index(0);
    cout << "\nList2->" << list2 << '\n';
    system("pause");
    system("cls");

    cout << __LINE__ << "-ая строка\nТест перегрузки cin>>list2 \n";
    cin >> list2;
    cout << "\nList2->" << list2 << '\n';
    system("pause");
    system("cls");

    cout << __LINE__ << "-ая строка\nТест конструктора и оператора перемещения \n";
    List_1 list3 = move(list2), list4;
    cout << "\n List_1 list3 = move(list2), list4;->" << list3 << '\n';
    list4 = move(list3);
    cout << "\n list4 = move(list3);->" << list4 << '\n';

    system("pause");
    system("cls");


}

