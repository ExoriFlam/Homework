#pragma once
#include <iostream>
using namespace std;

template<class Type>
class QueueTemplate
{
	Type* buffer;
	int max_length;
	int length;

public:

	explicit QueueTemplate(int max_size = 10);
	QueueTemplate(const QueueTemplate& other);
	QueueTemplate(QueueTemplate&& other)noexcept;
	QueueTemplate& operator=(const QueueTemplate& other);
	QueueTemplate& operator=(QueueTemplate&& other)noexcept;

	template<class Type>
	friend ostream& operator<<(ostream& out, const QueueTemplate<Type>& obj);

	~QueueTemplate();

	void Add(const Type& elem);
	Type Extract();
	void Clear();
	bool IsEmpty()const;
	bool IsFull()const;
	int GetCount()const;

};

template<class Type>
QueueTemplate<Type>::QueueTemplate(int max_size) :
	max_length{ max_size }, length{ 0 }, buffer{ new Type[max_size]{} } {}

template<class Type>
QueueTemplate<Type>::QueueTemplate(const QueueTemplate& other) :
	max_length{ other.max_length }, length{ other.length }, buffer{ new Type[other.max_length] {} }
{
	for (int i = 0; i < max_length; i++)
	{
		buffer[i] = other.buffer[i];
	}
}

template<class Type>
QueueTemplate<Type>::QueueTemplate(QueueTemplate&& other) noexcept :
	buffer{ other.buffer }, max_length {other.max_length}, length{ other.length }
{
	
	other.buffer = nullptr;
	other.length = other.max_length = other.max_length = 0;

}

template<class Type>
QueueTemplate<Type>& QueueTemplate<Type>::operator=(const QueueTemplate& other)
{
	if (this == &other) return *this;

	if (max_length != other.max_length)
	{
		delete[]buffer;
		buffer = new Type[other.max_length] {};
	}
	max_length = other.max_length;
	length = other.length;

	for (int i = 0; i < max_length; i++)
	{
		buffer[i] = other.buffer[i];
	}


	return *this;
}

template<class Type>
QueueTemplate<Type>& QueueTemplate<Type>::operator=(QueueTemplate&& other) noexcept
{
	if (this == &other) return *this;

	length = other.length;
	max_length = other.max_length;

	buffer = other.buffer;
	other.buffer = nullptr;

	other.length = other.max_length = 0;

	return *this;
}

template<class Type>
QueueTemplate<Type>::~QueueTemplate()
{
	delete[]buffer;
}


template<class Type>
void QueueTemplate<Type>::Clear()
{
	length = 0;
}
template<class Type>
bool QueueTemplate<Type>::IsEmpty()const
{
	return (length == 0);
}

template<class Type>
bool QueueTemplate<Type>::IsFull()const
{
	return (length == max_length);
}

template<class Type>
int QueueTemplate<Type>::GetCount()const
{
	return length;
}

template<class Type>
void QueueTemplate<Type>::Add(const Type& elem)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и добавляем новый элемент
	if (!IsFull())
	{
		buffer[length++] = elem;
	}

}

template<class Type>
Type QueueTemplate<Type>::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty())
	{
		Type pop_elem = buffer[0];
		for (int i = 1; i < length; i++)
		{
			buffer[i - 1] = buffer[i];
		}
		length--;
		return pop_elem;
	}
	
}

template<class Type>
ostream& operator<<(ostream& out, const QueueTemplate<Type>& obj)
{
	if (!obj.IsEmpty())
	{
		out << "\n-------------------------------------------------------------------------\n";

		for (int i = 0; i < obj.length; i++)
		{
			out << obj.buffer[i] << " ";
		}
		out << "\n-------------------------------------------------------------------------\n";
	}
	else
	{
		out << "\nОчередь пуста\n";
	}


	return out;
}
