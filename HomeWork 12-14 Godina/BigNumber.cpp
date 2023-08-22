#include "BigNumber.h"
#include <iostream>
#include <math.h>
using namespace std;



//конструктор по умолчанию (нулевые значения)
BigNumber::BigNumber() : arr{ 0 } {}

//конструктор преобразования(принимает целое число и записывает его цифры в конец
//массива, остальные значения до начала - нулевые)
BigNumber::BigNumber(const int value) : arr{ 0 }
{
	int num = value;
	num != 0 ? num : 1;
	int count_digits = static_cast<int>(floor(log10(abs(num)))) + 1;
	 
	for (int i = SIZE - 1; i >= (SIZE - count_digits); i--)
	{
		arr[i] = num % 10;
		num /= 10;
	}
	
}

//конструктор преобразования(принимает строку из цифр, преобразует каждый символ в
//цифру и записывает в конец массива, остальные значения до начала - нулевые)
BigNumber::BigNumber(const char* str_to_digits) : arr{ 0 }
{

	bool only_digits = true;

	for (int i = 0; i < strlen(str_to_digits); i++) 
	{
		if (!(isdigit(str_to_digits[i])))
		{
			only_digits = false;
			break;
		}
	}
	
	if (only_digits)
	{
		char* str = new char[strlen(str_to_digits) + 1] {'\0'};

		if (str)
		{
			strcpy_s(str, strlen(str_to_digits) + 1, str_to_digits);
			int j = 0;

			for (int i = SIZE - 1; i >= SIZE - strlen(str); i--)
			{
				arr[i] = static_cast<char>(str[strlen(str) - 1 - j++] - 48);
			}

			delete[]str;
			str = nullptr;
		}
		else
		{
			cout << "\n Память не выделена.";
		}
	}
}


//конструктор с параметрами(принимает одномерный массив цифр и его размер)
BigNumber::BigNumber(int* other_arr, int other_size) : arr{ 0 }
{
	int j = 0;
	for (int i = SIZE - 1; i >= SIZE - other_size; i--)
	{
		arr[i] = other_arr[other_size - 1 - j++];
	}

}
BigNumber::BigNumber(const BigNumber& other)
{
	for (int i = 0; i < SIZE; i++)
	{
		this->arr[i] = other.arr[i];
	}
	
}
BigNumber& BigNumber::operator=(const BigNumber& other)
{
	if (this == &other) return *this;

	for (int i = 0; i < SIZE; i++)
	{
		this->arr[i] = other.arr[i];
	}

	return *this;
}

//оператор сложения двух объектов класса.
BigNumber BigNumber::operator+(const BigNumber& other)
{
	
	int result[SIZE]{0};
	int sum;

	for (int i = SIZE - 1; i >= 0; i-- )
	{
		sum = this->arr[i] + other.arr[i];
		result[i] += (sum % 10);
		if(i > 0) result[i - 1] += sum / 10;
		
		
	}
	
	return BigNumber(result, SIZE);
}



//оператор вывода объекта на экран с выравниванием по правому краю(максимальная
//длина 80, незначащие нули не выводятся)
ostream& operator<<(ostream& out, const BigNumber& obj)
{
	char str[81]{ '\0' };
	int i = 0;
	while (obj.arr[i] == 0)
	{
		str[i] = ' ';
		i++;
	}
	
	for (; i < obj.SIZE; i++)
	{
		str[i] = static_cast<char>(obj.arr[i] + 48);
	}
	
	out << str; 
				
	return out;
}
