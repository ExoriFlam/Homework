#include "My_Array.h"
#include <iostream>
#include <ctime>
using namespace std;




MyArray::MyArray() : size{ 5u }, arr{ new int[size] {} }, to_str_type{ nullptr } {}


MyArray::MyArray(int size, int init_val) : size{ static_cast<unsigned int>(size) }, arr{ new int[this->size]}, to_str_type{ nullptr }
{
	for (unsigned int i = 0; i < this->size; i++)
		arr[i] = init_val;
}

MyArray::MyArray(int other_size, int* other_arr) : size{ static_cast<unsigned int>(other_size) }, arr{ new int[other_size]}, to_str_type{ nullptr }
{
	if (arr)
	{
		for (int i = 0; i < other_size; i++)
		{
			arr[i] = other_arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0u;
	}
	
}

MyArray::MyArray(const MyArray& other) : size{ other.size }, arr{ new int[other.size] }
{
	if (arr)
	{
		for (unsigned int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0U;
	}

	if (other.to_str_type)
	{
		to_str_type = new char[strlen(other.to_str_type) + 1];

		if (to_str_type)
		{
			strcpy_s(to_str_type, strlen(other.to_str_type) + 1, other.to_str_type);
		}
		else
		{
			cout << "\nПамять не выделена";
		}
		
	}
	else
	{
		to_str_type = nullptr;
	}
	
  

}

MyArray::MyArray(MyArray&& other)noexcept : size{ other.size }, arr{ other.arr }, to_str_type{ other.to_str_type }
{
	other.size - 0u;
	other.arr = nullptr;
	other.to_str_type = nullptr;
}

MyArray::MyArray(int other_size, int range_begin, int range_end) : size{ static_cast<unsigned int>(other_size) }, arr{ new int[other_size] }, to_str_type{ nullptr }
{
	srand(time(nullptr));

	if (arr)
	{
		for (int i = 0; i < other_size; i++)
		{
	
			arr[i] = (rand() % (range_end - range_begin + 1)) + range_begin;
					 
		}

	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0u;
	}


}

MyArray& MyArray::operator=(const MyArray& other)
{
	if (this == &other) return *this;
	if (this->size != other.size)
	{
		delete[]this->arr;
		this->arr = new int[other.size];
		this->size = other.size;
	}
	if (arr)
	{
		for (unsigned int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	else
	{
		cout << "\nПамять не выделена";
		arr = nullptr;
		size = 0U;
	}
	if (other.to_str_type)
	{
		if (strlen(this->to_str_type) != strlen(other.to_str_type))
		{

			delete[]this->to_str_type;
			to_str_type = new char[strlen(other.to_str_type) + 1];

		}
		if (to_str_type)
		{
			strcpy_s(to_str_type, strlen(other.to_str_type) + 1, other.to_str_type);
		}
		else
		{
			cout << "\nПамять не выделена";
		}
	}
	else
	{
		this->to_str_type = nullptr;
	}


}

MyArray& MyArray::operator=(MyArray&& other)noexcept
{
	if (this == &other)
	{
		return *this;
	}
	if (this->arr) delete[]this->arr;
	this->size = other.size;
	this->arr = other.arr;
	other.size = 0;
	other.arr = nullptr;

	if (this->to_str_type) delete[]this->to_str_type;
	this->to_str_type = other.to_str_type;
	other.to_str_type = nullptr;

	return *this;
}

int& MyArray::operator[](const int index)
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

const int MyArray::operator[](const int index) const
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

MyArray MyArray::operator+(const MyArray& other)const
{
	 
	unsigned int total_size{ this->size + other.size };
	MyArray temp(total_size, 0);
	
	for (unsigned int i = 0; i < temp.size; i++)
	{
		if (i < this->size)
		{
			temp[i] = this->arr[i];
		}
		else
		{
			temp[i] = other.arr[i - this->size];
		}
	}

	return temp;
}

MyArray MyArray::operator+(const int val) const
{
	MyArray temp(this->size + val, 0);
	for (unsigned int i = 0; i < this->size; i++)
	{
		temp.arr[i] = this->arr[i];
	}

	return temp;
}

MyArray& MyArray::operator+=(int val)
{
	int* source_ptr = this->arr;
	this->arr = new int[this->size + static_cast<unsigned int>(val)] {};
	if (arr)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			arr[i] = source_ptr[i];
		}
		this->size += val;
		
		
	}
	else
	{
		cout << "\nПамять не выделена.";
		size = 0u;
	}

	delete[]source_ptr;
	source_ptr = nullptr;
	
	
	return *this;
}

MyArray& MyArray::operator+=(MyArray& other)
{
	MyArray temp(this->size + other.size,0);
	for (unsigned int i = 0; i < temp.size; i++)
	{
		if (i < this->size)
		{
			temp.arr[i] = this->arr[i];
		}
		else
		{
			temp.arr[i] = other.arr[i - this->size];
		}
	}
	*this = temp;
	return *this;
}

MyArray operator+(int val, const MyArray& other)
{
	if (val < 0) val *= -1;
	MyArray temp(other.size + val, 0);
	for (unsigned int i = static_cast<unsigned int>(val); i < temp.size; i++)
	{
		temp.arr[i] = other.arr[i - static_cast<unsigned int>(val)];
	}

	return temp;
}

ostream& operator<<(ostream& out, const MyArray& obj)
{
	for (unsigned int i = 0; i < obj.get_size(); i++)
	{
		out << obj[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, MyArray& obj)
{
	

	cout << "\n Введите длину массива : ";
	
	obj.size = obj.check_input<unsigned int>();
	obj.size >= 0 ? obj.size : 0u;
	if (obj.arr)
	{
		delete[]obj.arr;
	}

	obj.arr = new int[obj.size] {};

	if (obj.arr)
	{
		cout << "\nВведите значения : ";
		for (unsigned int i = 0; i < obj.size; i++)
		{
			obj.arr[i] = obj.check_input<int>();
		}

	}
	else
	{
		"\nПамять не выделена";
		obj.arr = nullptr;
		obj.size = 0u;
	}
	

	return in;
}




MyArray::operator int()
{
	int sum = 0;
	int* start = this->arr;
	int* end = this->arr + this->size;

	while (start < end)
	{
		sum += *(start++);
	}
	
	return sum;
}

MyArray::operator double()
{
	if (this->size == 0) return 0.0;
	double sum = 0;
	int* start = this->arr;
	int* end = this->arr + this->size;

	while (start < end)
	{
		sum += *(start++);
	}
	if (sum == 0) return 0.0;
	return sum / this->size;
}

MyArray::operator char* ()
{
	int num;
	int i = 0;
	int total_size = 0;
	//Считаем количество цифр в цикле
	while (i < size)
	{
		num = arr[i];
		if (num < 0) total_size++;
		do
		{
			num /= 10;
			total_size++;
			
		} while (num != 0);

		i++;
		
	}
	//Выделяем память размером total_size, учитывая количество цифр и пробелов.
	total_size += size;
	if (to_str_type)
	{
		delete[]to_str_type;
	}
	to_str_type = new char[total_size] {'\0'};

	if (to_str_type)
	{
		int j = 0,k = 0;                                   // Внешний цикл while итерирует массив целых чисел arr[i]. 
		i = 0;											   // Затем следующий цикл do while разбивает число на отдельные цифры, 
		int size_of_nbr = 0;                               // конвертирует их в char и добавляет в строку динамического массива arr[j].
		int indxsum = 0;                                   // Однако числа записываются в обратном порядке, поэтому мы считаем 
		bool negative_nbr = false;                         // количество цифр в числе, чтобы их перевернуть.
		while (i < size)                                   // В этом случае цикл do while выбран, чтобы обработать случай, когда число равно 0.
		{                                                  // Условие num != 0 не позволит попасть в цикл, если число равно 0.
			num = arr[i];                                  // 
			if (num < 0)								   //
			{											   //
				negative_nbr = true;                       //
				num *= -1;								   //
				 							               //
			}                                              //
			do                                             // В цикле for используется стандартный алгоритм реверса, где внутри цикла мы перемещаемся 
			{											   // до середины массива (n/2) и меняем местами первый элемент с последним, второй с предпоследним и так далее. 
				to_str_type[j++] = (char)((num % 10) + 48);// Переменная indexsum используется для сдвига к следующему числу, которое нужно поменять местами.
				num /= 10;                                 //
				size_of_nbr++;                             //
				if (j == total_size - 1) break;            //
				    
				                                          
			} while (num != 0);

			if (negative_nbr)
			{
				size_of_nbr++;
				to_str_type[j++] = '-';
				
				negative_nbr = false;
			}

			for (k = 0; k  < (size_of_nbr / 2); k++)
			{
				swap(to_str_type[indxsum + k], to_str_type[indxsum + size_of_nbr - k - 1]);
				
			}

			if (j != total_size) to_str_type[j] = ' ';

			indxsum += size_of_nbr + 1;

			size_of_nbr = 0;

			j++;
			i++;

			
		}

		to_str_type[total_size - 1] = '\0';                       // ставим ноль на место последнего пробела 
	}
	
	
	return to_str_type;
	
}

unsigned int MyArray::get_size()const
{
	return size;
}

int MyArray::get_avg()const
{
	int sum = 0;
	unsigned int temp_size = size;
	for (unsigned int i = 0; i < this->size; i++)
	{
		sum += arr[i];
	}
	temp_size = temp_size == 0 ? 1 : temp_size;
	return sum / static_cast<int>(temp_size);
}

void MyArray::push_back(int val)
{
	unsigned int new_size = this->size + 1u;
	int* temp_arr = new int[this->size];
	if (temp_arr)
	{
		for (unsigned int i = 0; i < this->size; i++)
		{
			temp_arr[i] = arr[i];
		}
		
		

		if (arr) delete[]arr;

		arr = new int[new_size];

		if (arr)
		{
			this->size = new_size;

			for (unsigned int i = 0; i < this->size; i++)
			{
				arr[i] = temp_arr[i];
			}
			arr[this->size - 1] = val;
		}
		else
		{
			cout << "\nПамять не выделена";
			arr = nullptr;
			size = 0u;
		}
		
	}
	else
	{
		cout << "\nПамять не выделена";
		temp_arr = nullptr;
		
	}

	if (temp_arr)
	{
		delete[]temp_arr;
		temp_arr = nullptr;
	}

}

MyArray::~MyArray()
{
	if (arr)
	{
		delete[]arr;
		arr = nullptr;
	}
	if (to_str_type)
	{
		delete[]to_str_type;
		to_str_type = nullptr;
	}
	
}


