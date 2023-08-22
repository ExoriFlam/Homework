#pragma once
#include <iostream>
using namespace std;


struct Element
{
	char data;       // данные
	Element* next;   // адрес следующего элемента

};

class List_1
{
private:
	Element* head;
	int count;

public:
	List_1();
	List_1(const List_1& other);
	//6. перегрузку оператора присваивани¤;
	List_1& operator=(const List_1& other);

	void push_back(const char& data);
	void push_front(const char& data);
	//1. метод удалени¤ последнего элемента списка;
	void pop_back();
	void pop_front();

	void insert_after_data(const char& after, const char& src);
	//2. метод удалени¤ всех элементов списка;
	void clear();
	void show()const;

	//3. метод, возвращающий пор¤дковый номер элемента по переданному
	//   значению(первое вхождение);
	int get_index_by_data(const char& data);
	//4. метод, возвращающий значение элемента списка по позиции;
	char get_data_by_index(const int& index)const;
	//12. метод, добавл¤ющий элемент в список по переданной позиции;
	void insert_elem_by_index(const int& index);
	//13. метод, удал¤ющий элемент списка по переданной позиции.
	void erase_by_index(const int& index);

	int get_count()const { return count; }

	bool containe(const char& data)const;
	/*7-8 перегрузку операторов сравнени¤ == , != , >= , <= .—равнение списков осуществл¤етс¤ по
		  количеству элементов и по содержимому;
		  ѕерегрузку операторов сравнени¤ >, <. —равнение списков осуществл¤етс¤ по количеству
		  элементов;*/
	bool operator<(const List_1& other)const;
	bool operator>(const List_1& other)const;

	bool operator==(const List_1& other)const;
	bool operator!=(const List_1& other)const;
	bool operator>=(const List_1& other)const;
	bool operator<=(const List_1& other)const;
	//9. перегрузку оператора + , который конкатенирует два списка и возвращает новый список;
	List_1 operator+(const List_1& other)const;
	/*10. перегрузку оператора Ц(унарный минус).ћетод возвращает новый список, который
		  будет содержать элементы списка, вызвавшего метод, но расположенные в обратном
		  пор¤дке;*/
	List_1 operator-()const;
	/*11. перегрузку оператора* .ќператор возвращает новый список, содержащий только общие
		  элементы обоих списков, дл¤ которых вызывалс¤ оператор;*/
	List_1 operator*(const List_1& other)const;
	//5. перегрузку оператора << ;
	friend ostream& operator <<(ostream& out, const List_1& obj);

	~List_1();
};