#include <iostream>
#include "My_Array_Template.h"
#include "MyString.h"
#include "Coord.h"
#include "QueueTemplate.h"
using namespace std;


int main()
{
	system("chcp 1251>nul");

	MyString line1(100,'-');
	MyString line2(100, '=');
	
	cout << "\n\n\n\tУстановите ширину консольного окна 100\n";
	system("pause");
	system("cls");

	cout << "\nСтрока: "<< __LINE__ << "\nТестируeм Шаблон класса MyArray с типом INT\n" << line2;
	const int SIZE = 10;
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	
	MyArrayTemplate<int> a;
	MyArrayTemplate<int> b(8,999);
	MyArrayTemplate<int> c(SIZE,arr);

	cout << "\nКонструктор по умолчанию. Создает 5 дефолтных элементов типа INT\n";
	cout << "-> " << a << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,VALUE).\nMyArrayTemplate<int> b(8,999);\nСоздает массив SIZE элементов значения VALUE типа INT\n";
	cout << "-> " << b << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,ARR[]).\nСоздает массив SIZE элементов копируя значения из ARR[] типа INT\nint arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };\n";
	cout << "-> " << c << '\n' << line1;
	
	
	MyArrayTemplate<int> d(b);
	cout << "\nТестируeм конструктор копирования\n";
	cout << "-> " << d << '\n' << line1;
	MyArrayTemplate<int> e(move(c));
	cout << "\nТестируeм конструктор перемещающего копирования\n";
	cout << "-> " << e << '\n' << line1;
	
	a = e;
	b = move(d);
	cout << "\nТестируeм перегруженную операцию присваивания\n";
	cout << "-> " << a << '\n' << line1;
	cout << "\nТестируeм перегруженную операцию перемещающего присваивания\n";
	cout << "-> " << b << '\n' << line1;

	cout << "\nТестируeм перегруженную операцию + которая объединяет два массива типа INT\n";
	MyArrayTemplate<int> f;
	f = a + b;
	cout << "-> " << f << '\n' << line1;

	cout << "\nТестируeм перегруженную операцию += которая объединяет и присваивает два массива типа INT\n";
	a += f;
	cout << "-> " << a << '\n' << line1;
	cout << "\nТестируeм метод PushBack(Type&) который добавляет элемент в конец массива\n b.push_back(987);b.push_back(654); \n";
	b.push_back(987);
	b.push_back(654);
	cout << "-> " << b << '\n' << line1;

	cout << endl;
	system("pause");
	system("cls");

	/////////////////////////////////////

	const int SIZE1 = 5;
	Coord arr1[SIZE1] = { {1,2 },{ 3, 4},{ 5, 6}, {7, 8},{ 9, 10} };

	MyArrayTemplate<Coord> a1;
	MyArrayTemplate<Coord> b1(8, {7,7});
	MyArrayTemplate<Coord> c1(SIZE1, arr1);

	cout << "\nСтрока: " << __LINE__ << "\nТестируeм Шаблон класса MyArray с типом Coord\n" << line2;
	cout << "\nКонструктор по умолчанию. Создает 5 дефолтных элементов типа Coord\n";
	cout << "-> " << a1 << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,VALUE).\nMyArrayTemplate<Coord> b1(8, {7,7});\nСоздает массив SIZE элементов значения VALUE типа Coord\n";
	cout << "-> " << b1 << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,ARR[]).\nСоздает массив SIZE элементов копируя значения из ARR[] типа Coord\nCoord arr1[SIZE1] = { {1,2 },{ 3, 4},{ 5, 6}, {7, 8},{ 9, 10} };\n";
	cout << "-> " << c1 << '\n' << line1;

	MyArrayTemplate<Coord> d1(b1);
	cout << "\nТестируeм конструктор копирования\n";
	cout << "-> " << d1 << '\n' << line1;
	MyArrayTemplate<Coord> e1(move(c1));
	cout << "\nТестируeм конструктор перемещающего копирования\n";
	cout << "-> " << e1 << '\n' << line1;
	a1 = e1;
	b1 = move(d1);
	cout << "\nТестируeм перегруженную операцию присваивания\n";
	cout << "-> " << a1 << '\n' << line1;
	cout << "\nТестируeм перегруженную операцию перемещающего присваивания\n";
	cout << "-> " << b1 << '\n' << line1;


	cout << "\nТестируeм перегруженную операцию + которая объединяет два массива типа Coord\n";
	MyArrayTemplate<Coord> f1;
	f1 = a1 + b1;
	cout << "-> " << f1 << '\n' << line1;

	cout << "\nТестируeм перегруженную операцию += которая объединяет и присваивает два массива типа Coord\n";
	a1 += f1;
	cout << "-> " << a1 << '\n' << line1;
	cout << "\nТестируeм метод PushBack(Type&) который добавляет элемент в конец массива\nb.push_back({15, 30});b.push_back({45, 50}); \n";
	b1.push_back( {15, 30} );
	b1.push_back( {45, 50} );
	cout << "-> " << b1 << '\n' << line1;

	cout << endl;
	system("pause");
	system("cls");
    ///////////////////////////////////////////////

	const int SIZE2 = 5;
	MyString arr2[SIZE2] = { "Apple", "Cat", "Dog", "Hi", "C++" };
	
	MyArrayTemplate<MyString> a2;
	MyArrayTemplate<MyString> b2(5, "GoodLuck!");
	MyArrayTemplate<MyString> c2(SIZE2, arr2);

	cout << "\nСтрока: " << __LINE__ << "\nТестируeм Шаблон класса MyArray с типом MyString\n" << line2;
	cout << "\nКонструктор по умолчанию. Создает 5 дефолтных элементов типа MyString\n";
	cout << "-> " << a2 << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,VALUE).\nMyArrayTemplate<MyArray> b(5, \"GoodLuck!\"});\nСоздает массив SIZE элементов значения VALUE типа MyString\n";
	cout << "-> " << b2 << '\n' << line1;
	cout << "\nКонструктор с двумя параметрами(SIZE,ARR[]).\nСоздает массив SIZE элементов копируя значения из ARR[] типа MyString\nMyString arr2[SIZE2] = { \"Apple\", \"Cat\", \"Dog\", \"Hi\", \"C++\" };\n";
	cout << "-> " << c2 << '\n' << line1;


	MyArrayTemplate<MyString> d2(b2);
	cout << "\nТестируем конструктор копирования\n";
	cout << "-> " << d2 << '\n' << line1;
	MyArrayTemplate<MyString> e2(move(c2));
	cout << "\nТестируем конструктор перемещающего копирования\n";
	cout << "-> " << e2 << '\n' << line1;
	a2 = e2;
	b2 = move(d2);
	cout << "\nТестируем перегруженную операцию присваивания\n";
	cout << "-> " << a2 << '\n' << line1;
	cout << "\nТестируем перегруженную операцию перемещающего присваивания\n";
	cout << "-> " << b2 << '\n' << line1;

	cout << "\nТестируем перегруженную операцию + которая объединяет два массива типа MyString\n";
	MyArrayTemplate<MyString> f2;
	f2 = a2 + b2;
	cout << "-> " << f2 << '\n' << line1;

	cout << "\nТестируем перегруженную операцию += которая объединяет и присваивает два массива типа MyString\n";
	a2 += f2;
	cout << "-> " << a2 << '\n' << line1;
	cout << "\nТестируем метод PushBack(Type&) который добавляет элемент в конец массива\nb.push_back(\"StepIT\");b.push_back(\"Academy\"); \n";
	b2.push_back("StepIT");
	b2.push_back("Academy");
	cout << "-> " << b2 << '\n' << line1;
	cout << endl;
	system("pause");
	system("cls");
	//////////////////////////////////////////////////////////////////////////////////////////
	QueueTemplate<int> a3, c3,e3;
	cout << "\nСтрока: " << __LINE__ << "\nТестируeм Шаблон класса Queue с типом INT\n" << line2;
	a3.Add(55);
	a3.Add(89);
	a3.Add(67);
	cout << "\nДобавляем 3 элемента типа Int Add(55), Add(89), Add(67) и выводим\n";
	cout << a3 << '\n' << line2;
	QueueTemplate<int> b3(a3);
	c3 = b3;
	cout << "\nТестируем конструктор копии и операцию копирующего присваивания\n";
	cout << b3 << '\n' << line2;
	cout << c3 << '\n' << line2;
	QueueTemplate<int> d3(move(b3));
	e3 = c3;
	cout << "\nТестируем конструктор перемещения и операцию перемещающего присваивания\n";
	cout << d3 << '\n' << line2;
	cout << e3 << '\n' << line2;

	a3.Extract();
	a3.Extract();
	
	cout << "\n Удаляем 2 эелемента из очереди Extract()\n";
	cout << a3 << '\n' << line2;
	
	cout << "\n Тестируем остальные методы Queue\n";
	cout << "GetCount(); -> " << a3.GetCount() << endl;
	a3.Clear();
	cout << "Clear(); -> "  << a3;

	cout << endl;
	system("pause");
	system("cls");
	/////////////////////////////////////////////////////////////////////

	QueueTemplate<Coord> a4, c4, e4;
	cout << "\nСтрока: " << __LINE__ << "\nТестируeм Шаблон класса Queue с типом Coord\n" << line2;
	a4.Add({5,6});
	a4.Add({3,2});
	a4.Add({0,2});
	cout << "\nДобавляем 3 элемента типа Coord Add(55), Add(89), Add(67) и выводим\n";
	cout << a4 << '\n' << line2;
	QueueTemplate<Coord> b4(a4);
	c4 = b4;
	cout << "\nТестируем конструктор копии и операцию копирующего присваивания\n";
	cout << b4 << '\n' << line2;
	cout << c4 << '\n' << line2;
	QueueTemplate<Coord> d4(move(b4));
	e4 = c4;
	cout << "\nТестируем конструктор перемещения и операцию перемещающего присваивания\n";
	cout << d4 << '\n' << line2;
	cout << e4 << '\n' << line2;

	a4.Extract();
	a4.Extract();

	cout << "\n Удаляем 2 эелемента из очереди Extract()\n";
	cout << a4 << '\n' << line2;

	cout << "\n Тестируем остальные методы Queue\n";
	cout << "GetCount(); -> " << a4.GetCount() << endl;
	a4.Clear();
	cout << "Clear(); -> " << a4;

	cout << endl;
	system("pause");
	system("cls");
	/////////////////////////////////////////////////////////////////////

	QueueTemplate<MyString> a5, c5, e5;
	cout << "\nСтрока: " << __LINE__ << "\nТестируeм Шаблон класса Queue с типом MyString\n" << line2;
	a5.Add("Barsik"); 
	a5.Add("Murzik");
	a5.Add("Rijik");
	cout << "\nДобавляем 3 кота в очередь за едой и выводим =)\n";
	cout << a5 << '\n' << line2;
	QueueTemplate<MyString> b5(a5);
	c5 = b5;
	cout << "\nТестируем конструктор копии и операцию копирующего присваивания\n";
	cout << b5 << '\n' << line2;
	cout << c5 << '\n' << line2;
	QueueTemplate<MyString> d5(move(b5));
	e5 = c5;
	cout << "\nТестируем конструктор перемещения и операцию перемещающего присваивания\n";
	cout << d5 << '\n' << line2;
	cout << e5 << '\n' << line2;

	a5.Extract();
	a5.Extract();

	cout << "\n Выводим котов из очереди Extract()\n";
	cout << a5 << '\n' << line2;

	cout << "\n Тестируем остальные методы Queue\n";
	cout << "GetCount(); -> " << a5.GetCount() << endl;
	a5.Clear();
	cout << "Clear(); -> " << a5;

	cout << endl;
	system("pause");
	system("cls");


	
	

	
}

