#include "QueuePriority.h"
#include <iostream>

using namespace std;



QueuePriority::QueuePriority(int max_size) :
	max_length{ max_size }, length{ 0 }
{
	       
	queue = new int[max_length];
	priority = new int[max_length];
	
}

QueuePriority::QueuePriority(const QueuePriority& other) :
	max_length{ other.max_length }, length{ other.length }
{
	queue = new int[max_length] {};
	priority = new int[max_length] {};

	for (int i = 0; i < max_length; i++)
	{
		queue[i] = other.queue[i];
		priority[i] = other.priority[i];
	}

}

QueuePriority::QueuePriority(QueuePriority&& other)noexcept :
	max_length{ other.max_length }, length{ other.length }
{
	queue = other.queue;
	priority = other.priority;
	other.queue = nullptr;
	other.priority = nullptr;
	other.length = 0;
	other.max_length = 0;
}

QueuePriority& QueuePriority::operator=(const QueuePriority& other)
{
	if (this == &other) return *this;
	if (max_length != other.max_length)
	{
		delete[]queue;
		delete[]priority;
		queue = new int[other.max_length] {};
		priority = new int[other.max_length] {};
	}
	if (queue && priority)
	{
		length = other.length;
		max_length = other.max_length;

		for (int i = 0; i < max_length; i++)
		{
			queue[i] = other.queue[i];
			priority[i] = other.priority[i];
		}
	}


	return *this;
}

QueuePriority& QueuePriority::operator=(QueuePriority&& other)noexcept
{
	if (this == &other) return *this;

	delete[]queue;
	delete[]priority;

	queue = other.queue;
	priority = other.priority;
	length = other.length;
	max_length = other.max_length;

	other.queue = other.priority = nullptr;
	
	other.length = other.max_length = 0;
	

	return *this;
}


QueuePriority::~QueuePriority()
{
	delete[]queue;			
	delete[]priority;
}


void QueuePriority::Clear()
{
	length = 0;	
}



bool QueuePriority::IsEmpty()const
{
	return (length == 0);
}


bool QueuePriority::IsFull()const
{
	return (length == max_length);
}


int QueuePriority::GetCount()const
{
	return length;
}




void QueuePriority::Add(int elem, int prty)
{
	//Если в очереди есть свободное место,
	/*Каждый элемент при попадании в очередь сразу
		же располагается согласно своему приоритету.*/
	if (!IsFull())
	{
		queue[length] = elem;
		priority[length] = prty;
		length++;

		for (int i = 0; i < length - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < length - i - 1; j++)
			{
				if (priority[j] < priority[j + 1])
				{
					swap(priority[j], priority[j + 1]);
					swap(queue[j], queue[j + 1]);
					swapped = true;
				}
			}

			if (!swapped)
			{
				break;
			}
		}
	}
}


int QueuePriority::Extract()
{

	/*момент исключения - извлекается элемент из
		  начала очереди.*/
	if (!IsEmpty())
	{
		int elem = queue[length];
		length--;
		return elem;
	}
	else return -1;
}

ostream& operator<<(ostream& out,const QueuePriority& obj)
{
	if (!obj.IsEmpty())
	{
		out << "\n-----------------------------------\n";

		for (int i = 0; i < obj.length; i++)
		{
			out << obj.queue[i] << " - " << obj.priority[i] << "\n\n";
		}
		out << "\n-----------------------------------\n";
	}
	else
	{
		out << "\nОчередь пуста\n";
	}
	return out;
}
