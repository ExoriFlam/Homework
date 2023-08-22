#include <iostream>

using namespace std;
#include "Queue.h"

Queue::Queue(int max_size) :
	max_length{ max_size }, length{ 0 }, buffer{ new int[max_size] {0} } {}


Queue::Queue(const Queue& other) :
	max_length{ other.max_length }, length{ other.length }, buffer{ new int[other.max_length] {0} } 
{
	for (int i = 0; i < max_length; i++)
	{
		buffer[i] = other.buffer[i];
	}
}

Queue::Queue(Queue&& other) noexcept :
	max_length{ other.max_length }, length{ other.length }
{
	delete[]buffer;
	buffer = other.buffer;
	other.buffer = nullptr;
	other.length = other.max_length = 0;
	
}

Queue& Queue::operator=(const Queue& other)
{
	if (this == &other) return *this;

	if (max_length != other.max_length)
	{
		delete[]buffer;
		buffer = new int[other.max_length] {};
	}
	max_length = other.max_length;
	length = other.length;

	for (int i = 0; i < max_length; i++)
	{
		buffer[i] = other.buffer[i];
	}


	return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept
{
	if (this == &other) return *this;

	length = other.length;
	max_length = other.max_length;

	buffer = other.buffer;
	other.buffer = nullptr;

	other.length = other.max_length = 0;

	return *this;
}


Queue::~Queue()						 
{
	delete[]buffer;  
}



void Queue::Clear()
{
	length = 0;			
}

bool Queue::IsEmpty()const
{
	return (length == 0);
}


bool Queue::IsFull()const
{
	return (length == max_length);
}


int Queue::GetCount()const		
{	
	return length;
}

void Queue::Add(int elem)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и добавляем новый элемент
	if (!IsFull())
	{
		buffer[length++] = elem;
	}
		
}


int Queue::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty())
	{
		int pop_elem = buffer[0];                 
		for (int i = 1; i < length; i++)
		{										  
			buffer[i - 1] = buffer[i];
		}
		length--;						          
		return pop_elem;					      
	}
	else return -1;						           
}

ostream& operator<<(ostream& out,const Queue& obj)
{
	if (!obj.IsEmpty())
	{
		out << "\n-----------------------------------\n";
		
		for (int i = 0; i < obj.length; i++) {
			out << obj.buffer[i] << " ";
		}
		out << "\n-----------------------------------\n";
	}
	else
	{
		out << "\nОчередь пуста\n";
	}


	return out;
}
