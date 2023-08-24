#pragma once
#include <iostream>
using namespace std;


template<class Type>
struct NodeT
{
	Type data;
	NodeT* next;
	NodeT* prev;

	NodeT()
	{
		data = Type();
		this->next = prev = nullptr;

	}

	NodeT(const Type& data)
	{

		this->data = data;
		this->next = prev = nullptr;

	}

};

template<class Type>
class ListTwoTemplate
{
	NodeT<Type>* head;
	NodeT<Type>* tail;
	int count;

public:

	ListTwoTemplate();
	ListTwoTemplate(const ListTwoTemplate& other);
	ListTwoTemplate(ListTwoTemplate&& other)noexcept;

	ListTwoTemplate& operator=(const ListTwoTemplate& other);
	ListTwoTemplate& operator=(ListTwoTemplate&& other)noexcept;
	ListTwoTemplate operator+(const ListTwoTemplate& other);
	void push_back(const Type& add);
	void show(bool dir = false)const;

	void push_front(const Type& add);

	void insert_before_found_data(const Type& data_for_srch, const Type& ins_data);
	void insert_after_found_data(const Type& data_for_srch, const Type& ins_data);

	void pop_front();
	void pop_back();
	void clear();

	int get_count()const { return this->count; }

	void erase_by_data(const Type& data_for_srch);
	void erase_by_index(const int& indx);
	void insert_before_index(const int& indx);

	template<class Type>
	friend ostream& operator<< (ostream& out, const ListTwoTemplate<Type>& obj);
	

	~ListTwoTemplate();
};




template<class Type>
ListTwoTemplate<Type>::ListTwoTemplate()
{
	this->head = this->tail = nullptr;
	count = 0;
}

template<class Type>
ListTwoTemplate<Type>::ListTwoTemplate(const ListTwoTemplate& other)
{
	NodeT<Type>* other_current = other.head;
	while (other_current)
	{
		this->push_back(other_current->data);
		other_current = other_current->next;
	}
}

template<class Type>
ListTwoTemplate<Type>::ListTwoTemplate(ListTwoTemplate&& other) noexcept
{
	this->count = other.count;
	this->head = other.head;
	this->tail = other.tail;
	other.head = other.tail = nullptr;
	other.count = 0;

}

template<class Type>
ListTwoTemplate<Type>& ListTwoTemplate<Type>::operator=(const ListTwoTemplate& other)
{
	if (this == &other)return *this;

	this->clear();
	NodeT<Type>* current_other = other.head;

	while (current_other)
	{
		this->push_back(current_other->data);
		current_other = current_other->next;
	}

	return *this;
}

template<class Type>
ListTwoTemplate<Type>& ListTwoTemplate<Type>::operator=(ListTwoTemplate&& other) noexcept
{
	if (this == &other)return *this;
	this->clear();

	this->count = other.count;
	this->head = other.head;
	this->tail = other.tail;
	other.head = other.tail = nullptr;
	other.count = 0;

	return *this;
}

template<class Type>
ListTwoTemplate<Type> ListTwoTemplate<Type>::operator+(const ListTwoTemplate& other)
{
	ListTwoTemplate temp = *this;

	NodeT<Type>* other_current = other.head;

	while (other_current)
	{
		temp.push_back(other_current->data);
		other_current = other_current->next;
	}

	return temp;
}

template<class Type>
void ListTwoTemplate<Type>::push_back(const Type& add)
{
	NodeT<Type>* temp = new NodeT<Type>(add);

	if (head)
	{
		this->tail->next = temp;
		temp->prev = tail;
		this->tail = temp;
	}
	else
	{
		this->head = this->tail = temp;
	}
	count++;
}

template<class Type>
void ListTwoTemplate<Type>::show(bool dir) const
{
	if (this->head == nullptr)
	{
		cout << "\nСписок пуст";
		return;
	}
	if (dir)
	{
		NodeT<Type>* current = this->head;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	else
	{
		NodeT<Type>* current = this->tail;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

}

template<class Type>
void ListTwoTemplate<Type>::push_front(const Type& add)
{
	NodeT<Type>* temp = new NodeT<Type>(add);

	if (head)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;

	}
	else
	{
		this->head = this->tail = temp;
	}
	count++;

}

template<class Type>
void ListTwoTemplate<Type>::insert_before_found_data(const Type& data_for_srch, const Type& ins_data)
{

	if (head)
	{
		NodeT<Type>* current = head;
		NodeT<Type>* to_add = new NodeT<Type>(ins_data);
		while (current)
		{
			if (current->data == data_for_srch) break;
			current = current->next;
		}

		if (!current) 
		{
			delete to_add;
			return;
		}

		if (current->prev)
		{
			to_add->next = current;
			current = current->prev;
			to_add->prev = current;
			current->next = to_add;
		}
		else
		{
			head = to_add;
			head->next = current;
			current->prev = head;
		}
		count++;
	}


}

template<class Type>
void ListTwoTemplate<Type>::insert_after_found_data(const Type& data_for_srch, const Type& ins_data)
{


	if (head)
	{
		NodeT<Type>* current = head;
		NodeT<Type>* to_add = new NodeT<Type>(ins_data);
		while (current)
		{
			if (current->data == data_for_srch) break;
			current = current->next;
		}

		if (!current)
		{
			delete to_add;
			return;
		}

		if (current->next)
		{
			to_add->next = current->next;
			to_add->prev = current;
			current->next->prev = to_add;
			current->next = to_add;

		}
		else
		{
			tail = to_add;
		}
		count++;
	}

}

template<class Type>
void ListTwoTemplate<Type>::pop_front()
{
	if (head)
	{
		NodeT<Type>* to_del = head;
		if (head->next)
		{
			head = head->next;
			head->prev = nullptr;
		}
		else
		{
			head = nullptr;
		}

		delete to_del;
		count--;
	}
}

template<class Type>
void ListTwoTemplate<Type>::pop_back()
{

	if (tail)
	{
		NodeT<Type>* to_del = tail;
		if (tail->prev)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		else
		{
			head = tail = nullptr;
		}

		delete to_del;
		count--;
	}

}

template<class Type>
void ListTwoTemplate<Type>::clear()
{
	while (head)
	{
		NodeT<Type>* to_del = head;
		head = head->next;
		delete to_del;
	}

	tail = nullptr;
	count = 0;

}

template<class Type>
void ListTwoTemplate<Type>::erase_by_data(const Type& data_for_srch)
{
	if (head)
	{
		NodeT<Type>* current = head;
		while (current)
		{
			if (current->data == data_for_srch) break;
			current = current->next;
		}

		if (!current) return; // элемент не найден

		if (current->prev)
		{
			current->prev->next = current->next;

		}
		else //если это первый эелемент
		{
			head = current->next;
		}

		if (current->next)
		{
			current->next->prev = current->prev;

		}
		else //если это последний эелемент
		{
			tail = current->prev;
		}

		delete current;

		count--;

	}
}

template<class Type>
void ListTwoTemplate<Type>::erase_by_index(const int& indx)
{
	if (indx < 0 || indx > count - 1) return;

	if (head)
	{

		if (indx == 0)
		{
			pop_front();
			return;

		}
		else if (indx == count - 1)
		{
			pop_back();
			return;
		}

		int cnt = 0;
		NodeT<Type>* to_del = nullptr;
		NodeT<Type>* current_head = head;
		NodeT<Type>* current_tail = tail;

		if (indx <= count / 2) // если индекс ближе к началу то начинаем с начала иначе с конца.
		{

			while (current_head)
			{
				if (indx == cnt)
				{
					to_del = current_head;
					break;
				}
				cnt++;
				current_head = current_head->next;
			}
		}
		else
		{
			cnt = count;
			while (current_tail)
			{
				if (indx == cnt)
				{
					to_del = current_tail;
					break;
				}
				cnt--;
				current_tail = current_tail->prev;
			}

		}

		if (to_del)
		{
			if (to_del->next)
			{
				to_del->next->prev = to_del->prev;
			}
			else
			{
				tail = to_del->prev;
			}

			if (to_del->prev)
			{
				to_del->prev->next = to_del->next;
			}
			else
			{
				head = to_del->next;
			}

			delete to_del;
			count--;
		}

	}
}
template<class Type>
void ListTwoTemplate<Type>::insert_before_index(const int& indx)
{
	if (indx < 0 || indx > count - 1) return;

	if (indx == 0)
	{
		push_front(Type());
		return;
	}
	else if (indx == count - 1)
	{
		push_back(Type());
		Type tmp = tail->data;
		tail->data = tail->prev->data;
		tail->prev->data = tmp;
		
		return;
	}


	int cnt = 0;
	NodeT<Type>* current_head = head;
	NodeT<Type>* current_tail = tail;
	NodeT<Type>* current_add = nullptr;

	if (indx <= count / 2)
	{
		while (current_head)
		{
			if (indx == cnt)
			{
				current_add = current_head;
				break;
			}
			current_head = current_head->next;
			cnt++;

		}

	}
	else
	{
		cnt = count;
		while (current_tail)
		{
			if (indx == cnt)
			{
				current_add = current_tail;
				break;
			}
			current_tail = current_tail->prev;
			cnt--;
		}

	}
	if (current_add)
	{
		NodeT<Type>* to_add = new NodeT<Type>;

		to_add->next = current_add;
		to_add->prev = current_add->prev;
		current_add->prev->next = to_add;
		current_add->prev = to_add;

		count++;
	}


}
template<class Type>
ListTwoTemplate<Type>::~ListTwoTemplate()
{

	NodeT<Type>* current = this->head;
	NodeT<Type>* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = tail = nullptr;
}

template<class Type>
ostream& operator<<(ostream& out, const ListTwoTemplate<Type>& obj)
{
	if (obj.head)
	{
		NodeT<Type>* current = obj.head;
		while (current)
		{
			out << current->data << " ";
			current = current->next;
		}
		out << endl;
	}
	else
	{
		out << "\nСписок пуст";
	}
	return out;
}
