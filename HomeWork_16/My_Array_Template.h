#pragma once
#include <iostream>
using namespace std;



template <class Type>
class MyArrayTemplate
{
private:

	unsigned int size;
	Type* arr;
	
	

public:

	MyArrayTemplate() : size{ 5u }, arr{ new Type[size] {} } {};
	MyArrayTemplate(int size, Type init_val);
	MyArrayTemplate(int size, Type* other_arr);
	MyArrayTemplate(const MyArrayTemplate& other);
	MyArrayTemplate(MyArrayTemplate&& other)noexcept;
	


	MyArrayTemplate& operator=(const MyArrayTemplate& other);
	MyArrayTemplate& operator=(MyArrayTemplate&& other)noexcept;
	Type& operator[](const int index);
	const Type operator[](const int index)const;
	MyArrayTemplate operator+(const MyArrayTemplate& other)const;
	MyArrayTemplate& operator+=(MyArrayTemplate& other);


	template <class Type>
	friend ostream& operator<< (ostream& out, const MyArrayTemplate<Type>& obj);
	
	

	unsigned int get_size()const;
	void push_back(const Type& val);

	
	~MyArrayTemplate();
};





template <class Type>
MyArrayTemplate<Type>::MyArrayTemplate(int size, Type init_val) :
	size{ static_cast<unsigned int>(size) }, arr{ new Type[this->size] }
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		arr[i] = init_val;
	}
		
}

template <class Type>
MyArrayTemplate<Type>::MyArrayTemplate(int other_size, Type* other_arr) :
	size{ static_cast<unsigned int>(other_size) }, arr{ new Type[other_size] }
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

template <class Type>
MyArrayTemplate<Type>::MyArrayTemplate(const MyArrayTemplate<Type>& other) :
	size{ other.size }, arr{ new Type[other.size] }
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
}

template <class Type>
MyArrayTemplate<Type>::MyArrayTemplate(MyArrayTemplate<Type>&& other)noexcept : 
	size{ other.size }, arr{ other.arr }
{
	other.size = 0u;
	other.arr = nullptr;
	
}


template <class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator=(const MyArrayTemplate<Type>& other)
{
	if (this == &other) return *this;
	if (this->size != other.size)
	{
		delete[]this->arr;
		this->arr = new Type[other.size];
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
}

template <class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator=(MyArrayTemplate<Type>&& other)noexcept
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

	return *this;
}

template <class Type>
Type& MyArrayTemplate<Type>::operator[](const int index)
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

template <class Type>
const Type MyArrayTemplate<Type>::operator[](const int index) const
{
	if (index < 0 || index > size) exit(1);
	return arr[index];
}

template <class Type>
MyArrayTemplate<Type> MyArrayTemplate<Type>::operator+(const MyArrayTemplate& other)const
{

	unsigned int total_size{ this->size + other.size };
	MyArrayTemplate temp(total_size, Type{});

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

template <class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator+=(MyArrayTemplate<Type>& other)
{
	MyArrayTemplate temp(this->size + other.size, Type{});
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





template <class Type>
ostream& operator<< (ostream& out, const MyArrayTemplate<Type>& obj)
{
	for (unsigned int i = 0; i < obj.size; i++)
	{
		out << obj[i] << " ";
	}
	return out;
}


template <class Type>
unsigned int MyArrayTemplate<Type>::get_size()const
{
	return size;
}


template <class Type>
void MyArrayTemplate<Type>::push_back(const Type& val)
{
	unsigned int new_size = this->size + 1u;
	Type* temp_arr = this->arr;
	this->arr = new Type[new_size]{};
	if (arr)
	{
		this->size = new_size;

		for (unsigned int i = 0; i < this->size - 1; i++)
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
	if (temp_arr)
	{
		delete[]temp_arr;
		temp_arr = nullptr;
	}
	
}


template <class Type>
MyArrayTemplate<Type>::~MyArrayTemplate()
{
	
	delete[]arr;
	arr = nullptr;

}


