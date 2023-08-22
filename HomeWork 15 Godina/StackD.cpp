
#include <iostream>

using namespace std;
#include "StackD.h"




int StackD::count = 0; // инициализация статической переменной класса

StackD::StackD(int size) :
	size{ size }, top{ 0 }
{
	items = new int[this->size];
	count++;
}

StackD::StackD(const StackD& other) :
	size {other.size}, top{other.top}
{
	items = new int[this->size] {0};
	const int* source = other.items;
	const int* end = other.items + size;
	int* dest = this->items;
	
	if (items)
	{
		while (source < end)
		{
			*(dest++) = *(source++);
		}
	}

	source = nullptr;
	end = nullptr;
	dest = nullptr;
	count++;
}

StackD::StackD(StackD&& other)noexcept :
	size{ other.size }, top{ other.top }
{
	items = other.items;
	other.items = nullptr;

	other.size = other.top = 0;

}

StackD& StackD::operator=(const StackD& other)
{
	if (this == &other) return *this;

	if (this->size != other.size)
	{
		delete[]items;
		items = new int[other.size] {0};
		
	}

	this->size = other.size;
	this->top = other.top;

	const int* source = other.items;
	const int* end = other.items + size;
	int* dest = this->items;

	if (items)
	{
		while (source < end)
		{
			*(dest++) = *(source++);
		}
	}

	source = nullptr;
	end = nullptr;
	dest = nullptr;

	return *this;
}

StackD& StackD::operator=(StackD&& other)noexcept
{
	if (this == &other) return *this;

	delete[]items;
	items = other.items;
	size = other.size;
	top = other.top;
	other.size = other.top = 0;
	other.items = nullptr;
	
	return *this;
}


bool StackD::push(const int & item)
{
	if (top < size)
	{
		items[top++] = item;
		return 1;
	}
	return 0;
}

bool StackD::pop(int & item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1;
	}
	return 0;
}

ostream& operator<<(ostream& out, StackD& obj)
{
	if (obj.top == 0)
	{
		out << "\nstack is empty\n";
		return out;
	}
	int i;
	for (i = 0; i < obj.top - 1; i++)
	{
		out << obj.items[i] << ", ";
	}
		
	out << obj.items[i] << "!";

	out << endl;

	return out;
}
