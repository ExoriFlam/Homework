#pragma once
#include "My_Array.h"
#include <iostream>




class Student
{
private:

	char* last_name;
	char* first_name;
	int birthday;
	char phone_nbr[32];
	char* institution;
	int group_id;
	MyArray marks;
	void copy_str(char*& destitnation, const char* source);
	template<typename T>
	T check_input();
	


public:
	/*Задание 3. В уже существующий класс Студент добавьте конструктор, который в дополнение к
	основным данным принимает произвольное количество оценок в качестве параметров.*/
	Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id,int _size, ...);
	Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id, int* marks, int _size);
	Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id, MyArray _marks);
	Student();
	Student(const Student& other);

	Student& operator=(const Student& other);
	friend ostream& operator<<(ostream& out, const Student& obj);
	friend istream& operator>>(istream& in, Student& obj);

	void set_last_name(const char* str);	
	void set_first_name(const char* str);
	void set_birthday(const int val);
	void set_phone_nbr(const char* str);
	void set_institution(const char* str);
	void set_group_id(const int val);
	void set_marks_by_list(const int* arr,int _size);
	void set_mark(const int val);
	const char* get_last_name()const;
	const char* get_first_name()const;
	int get_birthday()const;
	const char* get_phone()const;
	const char* get_institution()const;
	int get_group_id()const;
	MyArray get_marks()const;
	
	double get_avg_marks()const;
	int get_count_of_marks()const;

	

	~Student();
};

template<typename T>
inline T Student::check_input()
{
	T temp;
	std::cin >> temp;
	while (std::cin.fail())
	{
		std::cout << "\nОшибка ввода!";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> temp;
	}
	return temp;
}
