#include <iostream>
#include "StackD.h"
#include "Queue.h"
#include "QueuePriority.h"
using namespace std;

int main()
{
    system("chcp 1251>nul");

    /*Задание 2. В уже существующие классы Очередь(Queue) и Стек(StackD) добавьте реализацию
                 конструктора копирования и перегрузку оператора присваивания.*/
    StackD stack_a, stack_b;
    stack_a.push(5);
    stack_a.push(4);
    stack_a.push(3);
    cout << "\nStackD cоздаем два пустых стэка, в один из них добавляем элементы,\nзатем присваиваем в другой.operator=\n";
    cout << stack_a << endl;
    stack_b = stack_a;
    cout << stack_b << endl;
    cout << "\nСоздаем StackD, инициалируем копированием.\n";
    StackD stack_c(stack_b);
    cout << stack_c << endl;

    cout << endl;
    system("pause");
    system("cls");
    /////////////////////////////////////////////////////
    Queue queue_a, queue_b;
    queue_a.Add(5);
    queue_a.Add(4);
    queue_a.Add(3);
    cout << "\nQueue cоздаем двe пустых очереди, в одину из них добавляем элементы,\nзатем присваиваем в другой.operator=\n";
    cout << queue_a << endl;
    queue_b = queue_a;
    cout << queue_b << endl;
    Queue queue_c(queue_b);
    cout << "\nСоздаем Queue, инициалируем копированием.\n";
    cout << queue_c << endl;
    
    cout << endl;
    system("pause");
    system("cls");
    /////////////////////////////////////////////////////
   /* Задание 3. Реализуйте класс Очередь с приоритетным включением — на основе
               динамического массива целых значений.Каждый элемент при попадании в очередь сразу
               же располагается согласно своему приоритету.А в момент исключения - извлекается элемент из
               начала очереди.Реализуйте в классе конструктор копирования и перегрузку оператора
               присваивания.Продемонстрируйте работу класса на примерах.*/
    QueuePriority queue_pr_a(10), queue_pr_b(5);

    queue_pr_a.Add(10, 4);
    queue_pr_a.Add(5, 3);
    queue_pr_a.Add(5, 5);
    queue_pr_a.Add(8, 2);
    queue_pr_a.Add(1, 1);

    cout << "QueuePriority Создаем и добавляем элементы в очередь.\nqueue_pr_a.Add(10, 4);\nqueue_pr_a.Add(5, 3);\nqueue_pr_a.Add(5, 5);\nqueue_pr_a.Add(8, 2);\nqueue_pr_a.Add(1, 1);\n";
    cout << queue_pr_a << endl;
    queue_pr_a.Extract();
    queue_pr_a.Extract();
    queue_pr_a.Extract();
    cout << "\nУдаляем три элемента из очереди";
    cout << queue_pr_a << endl;
    cout << "\nДемонстрация копирования и присваивания\n queue_pr_b = queue_pr_a;\nQueuePriority queue_pr_c(queue_pr_b);";
    queue_pr_b = queue_pr_a;
    cout << queue_pr_b << endl;
    QueuePriority queue_pr_c(queue_pr_b);
    cout << queue_pr_c << endl;
    cout << endl;
    system("pause");
    system("cls");

    return 0;
}