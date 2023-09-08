//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <assert.h>
#include "MyString.h"
#include <cstring>
using namespace std;



void MyString::dyn_str_copy(char*& destination, const char* source)
{
	if (source)
	{
		if (!destination || strlen(destination) != strlen(source))
		{
			delete[] destination;
			destination = new char[strlen(source) + 1];
		}

		if (destination)
		{
			strcpy_s(destination, strlen(source) + 1, source);
		}
		else
		{
			cout << "\nПамять не выделена.";
		}
	}

}

MyString::MyString() : str{ nullptr }
{
	length = strlen("Hello");
	dyn_str_copy(this->str, "Hello");

}

MyString::MyString(const char* string) : str{ nullptr }
{

	length = strlen(string);
	dyn_str_copy(this->str, string);

	
}

MyString::MyString(int len, char symbol) : length{ len }

{
	str = new char[length + 1];
	if (str)
	{
		for (int i = 0; i < length; i++)
		{
			str[i] = symbol;
		}
		str[length] = '\0';
		
	}
	else
	{
		cout << "Память не выделена";
		length = 0;
	}

}


MyString::MyString(const MyString& obj) : str{ nullptr }
{

	dyn_str_copy(this->str, obj.str);
	length = obj.length;
	
}

MyString::MyString(MyString&& obj)noexcept
{
	this->length = obj.length;
	this->str = obj.str;
	obj.str = nullptr;
	obj.length = 0;

	
}


void MyString::init(const char* str)
{
	dyn_str_copy(this->str, str);
	this->length = strlen(str);
}



int MyString::get_length()const
{
	return length;
}




MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	dyn_str_copy(this->str, obj.str);
	this->length = obj.length;

	return *this;
}

MyString& MyString::operator=(MyString&& obj)noexcept
{
	if (this == &obj)
	{
		return *this;
	}
	if (this->str) delete[]str;
	this->length = obj.length;
	this->str = obj.str;
	obj.length = 0;
	obj.str = nullptr;

	return *this;
}

const char MyString::operator[](const int index) const
{

	if (index < 0 || index > this->length)
	{
		cout << "\n Неверный индекс";
		return '\0';
	}

	return this->str[index];
}

char& MyString::operator[](const int index)
{
	return this->str[index];

}

bool MyString::operator==(const MyString& other)const
{
	return _strcmpi(this->str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other)const
{
	return !(*this == other);
}

bool MyString::operator>(const MyString& other)const
{
	return _strcmpi(this->str, other.str) > 0;
}

bool MyString::operator<(const MyString& other)const
{
	return _strcmpi(this->str, other.str) < 0;
}

bool MyString::operator>=(const MyString& other)const
{
	return (*this > other || *this == other);
}

bool MyString::operator<=(const MyString& other)const
{
	return (*this < other || *this == other);
}

MyString MyString::operator+(const MyString& other) const
{
	int max_size = this->length + other.length;
	MyString temp(max_size, ' ');

	strcpy_s(temp.str, max_size + 1, this->str);
	strcat_s(temp.str, max_size + 1, other.str);

	return temp;
}

MyString& MyString::operator+=(const MyString& other)
{
	MyString temp = *this + other;
	*this = temp;
	return *this;
}

void MyString::operator()(const char* str)
{
	dyn_str_copy(this->str, str);
	this->length = strlen(str);
}

void MyString::save_to_bin_file(FILE* file)const
{
	//запись длины строки
	fwrite(&this->length, sizeof(this->length), 1, file);
	//запись содержимого строки
	//fwrite(this->str, this->length + 1, 1, file);
	if (this->length)
	{
		fwrite(str, sizeof(str[0]), this->length + 1, file);
	}
	
}

void MyString::read_from_bin_file(FILE* file)
{
	delete[]this->str;
	//считываем длину строки
	fread(&this->length, sizeof(this->length), 1, file);
	//выделяем новую память
	this->str = new char[this->length + 1] {'\0'};
	if (str)
	{
		fread_s(str, length + 1, sizeof(char), this->length + 1, file);
	}
	
}

MyString::operator char* ()const
{

	return this->str;

}


MyString::~MyString()
{
	
	delete[]str;
	str = nullptr;
}

ostream& operator<<(ostream& out, const MyString& obj)
{
	out << obj.str;
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	char buf[256];

	cin.getline(buf, sizeof(buf));
	obj.dyn_str_copy(obj.str, buf);
	obj.length = strlen(buf);

	return in;
}

