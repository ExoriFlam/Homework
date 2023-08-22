#include "Student.h"
#include <iostream>
#include <cstring>
#include "My_Array.h"
#include <cmath>
#include <stdarg.h>



void Student::copy_str(char*& destination, const char* source)
{
	if (source)
	{
		if (destination)
		{
			if (strlen(destination) != strlen(source))
			{
				delete[]destination;
				destination = new char[strlen(source) + 1];
			}
			if (destination)
			{
				strcpy_s(destination, strlen(source) + 1, source);
			}
			else
			{
				cout << "\n Память не выделена";
			}

		}
		else
		{
			destination = new char[strlen(source) + 1];

			if (destination)
			{
				strcpy_s(destination, strlen(source) + 1, source);
			}
			else
			{
				cout << "\n Память не выделена";
			}
		}

	}

}

/*Задание 3. В уже существующий класс Студент добавьте конструктор, который в дополнение к
	основным данным принимает произвольное количество оценок в качестве параметров.*/

Student::Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id, int _size, ...) :
	birthday{ birthday }, group_id{ group_id }
{
	copy_str(last_name, l_name);
	copy_str(first_name, f_name);

	if ((strlen(phone)) <= 32)
	{
		strcpy_s(phone_nbr, phone);
	}
	else
	{
		strcpy_s(phone_nbr, "+000 000 000 000");
		std::cout << "Ошибка! Максиальное кол-во символов 32!";
	}
	copy_str(this->institution, institution);
	
	va_list arg_ptr;
	va_start(arg_ptr, _size);

	int i = 0;
	while (_size--)
	{
		if (marks[i] != 0)
		{
			marks.push_back(va_arg(arg_ptr, int));

		}
		else
		{
			marks[i] = va_arg(arg_ptr, int);
		}

		i++;
		
	}
	va_end(arg_ptr);
}

Student::Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id, int* _marks, int _size) :
	birthday{ birthday }, group_id{ group_id }
{
	copy_str(last_name, l_name);
	copy_str(first_name, f_name);

	if ((strlen(phone)) <= 32)
	{
		strcpy_s(phone_nbr, phone);
	}
	else
	{
		strcpy_s(phone_nbr, "+000 000 000 000");
		std::cout << "Ошибка! Максиальное кол-во символов 32!";
	}
	copy_str(this->institution, institution);

	for (int i = 0; i < _size; i++)
	{
		this->marks[i] = _marks[i];
	}

}

Student::Student(const char* l_name, const char* f_name, int birthday, const char* phone, const char* institution, int group_id, MyArray _marks) :
	birthday{ birthday }, group_id{ group_id }, marks(_marks)
{
	copy_str(last_name, l_name);
	copy_str(first_name, f_name);

	if ((strlen(phone)) <= 32)
	{
		strcpy_s(phone_nbr, phone);
	}
	else
	{
		strcpy_s(phone_nbr, "+000 000 000 000");
		std::cout << "Ошибка! Максиальное кол-во символов 32!";
	}
	copy_str(this->institution, institution);

}

Student::Student() : Student("empty", "empty", 0, "empty", "empty", 0, MyArray()) {}

Student::Student(const Student& other) :
	birthday{ other.birthday }, group_id{ other.group_id }, marks{ other.marks }
{
	copy_str(last_name, other.last_name);
	copy_str(first_name, other.first_name);
	strcpy_s(this->phone_nbr, other.phone_nbr);
	copy_str(this->institution, other.institution);
}

void Student::set_last_name(const char* str)
{
	copy_str(last_name, str);
}

Student& Student::operator=(const Student& other)
{
	if (this == &other) return *this;

	this->birthday = other.birthday;
	this->group_id = other.group_id;
	this->marks = other.marks;
	strcpy_s(this->phone_nbr, other.phone_nbr);
	copy_str(this->last_name, other.last_name);
	copy_str(this->first_name, other.first_name);
	copy_str(this->institution, other.institution);

	return *this;
}

void Student::set_first_name(const char* str)
{
	copy_str(first_name, str);
}

void Student::set_birthday(const int val)
{
	this->birthday = val > 1923 && val < 2030 ? val : 0;
}

void Student::set_phone_nbr(const char* str)
{
	if (strlen(str) <= 32)
	{
		strcpy_s(phone_nbr, str);
	}
	else
	{
		strcpy_s(phone_nbr, "+000 000 000 000");
		std::cout << "Ошибка! Максиальное кол-во символов 32!";
	}
}

void Student::set_institution(const char* str)
{
	copy_str(institution, str);
}

void Student::set_group_id(const int val)
{
	this->group_id = val >= 0 ? val : 0;
}

void Student::set_marks_by_list(const int* arr, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		if (marks[i] != 0)
		{
			marks.push_back(arr[i]);

		}
		else
		{
			marks[i] = arr[i];
		}

	}

}

void Student::set_mark(const int val)
{
	if (val < 1 || val > 11) return;
	marks.push_back(val);
}



const char* Student::get_last_name() const
{
	return last_name;
}

const char* Student::get_first_name() const
{
	return first_name;
}

int Student::get_birthday() const
{
	return birthday;
}

const char* Student::get_phone() const
{
	return phone_nbr;
}

const char* Student::get_institution() const
{
	return institution;
}

int Student::get_group_id() const
{
	return group_id;
}

MyArray Student::get_marks()const
{

	return marks;
}

double Student::get_avg_marks()const
{
	return marks.get_avg();
}

int Student::get_count_of_marks() const
{
	return marks.get_size();
}


Student::~Student()
{
	if (last_name)
	{
		delete[]last_name;
		last_name = nullptr;
	}
	if (first_name)
	{
		delete[]first_name;
		first_name = nullptr;
	}
	if (institution)
	{
		delete[]institution;
		institution = nullptr;
	}



}

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
	out << "\nФамилия            :" << obj.last_name;
	out << "\nИмя                :" << obj.first_name;
	out << "\nГод рождения       :" << obj.birthday;
	out << "\nНомер телефона     :" << obj.phone_nbr;
	out << "\nУчебного заведение :" << obj.institution;
	out << "\nНомер группы       :" << obj.group_id;
	out << "\nОценки             :";
	out << "\n" << obj.marks;
	out << "\nСредний балл       :" << obj.get_avg_marks();

	return out;
}

std::istream& operator>>(std::istream& in, Student& obj)
{
	char bufer[64];
	int temp = 0;
	std::cout << "\nВведите год рождения                : ";
	
	obj.birthday = obj.check_input<int>();

	in.get();

	std::cout << "\nВведите Фамилию                     : ";

	in.getline(bufer, sizeof(bufer));
	obj.copy_str(obj.last_name, bufer);


	std::cout << "\nВведите Имя                         : ";
	in.getline(bufer, sizeof(bufer));
	obj.copy_str(obj.first_name, bufer);

	std::cout << "\nВведите номер телефона              : ";
	in.getline(bufer, sizeof(bufer));

	if (strlen(bufer) <= 32)
	{
		strcpy_s(obj.phone_nbr, bufer);
	}
	else
	{
		strcpy_s(obj.phone_nbr, "+000 000 000 000");
		std::cout << "Ошибка! Максиальное кол-во символов 32!";
	}

	std::cout << "\nВведите название учебного заведения : ";
	in.getline(bufer, sizeof(bufer));
	obj.copy_str(obj.institution, bufer);

	std::cout << "\nВведите номер группы                : ";

	obj.group_id = obj.check_input<int>();

	std::cout << "\nВвод оценок                         : ";
	in >> obj.marks;


	return in;
}
