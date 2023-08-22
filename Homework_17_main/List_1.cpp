#include <iostream>
#include "List_1.h"
using namespace std;



List_1::List_1()
{
	this->head = nullptr;
	count = 0;
}

List_1::List_1(const List_1& other)
{
	this->head = nullptr;
	Element* current = other.head;
	while (current != nullptr)
	{
		this->push_back(current->data);
	    current = current->next;
	}
	
}

List_1::List_1(List_1&& other)noexcept
{
	this->count = other.count;
	this->head = other.head;
	other.head = nullptr;
}

List_1& List_1::operator=(const List_1& other)
{
	if (this == &other) return *this;

	Element* other_current = other.head;
	
	
	if (count != other.count)
	{
		this->clear();
		
		while (other_current)
		{
			this->push_back(other_current->data);
			other_current = other_current->next;
			
		}
	}
	else
	{
		Element* this_current = this->head;

		while (other_current)
		{
			this_current->data = other_current->data;
			this_current = this_current->next;
			other_current = other_current->next;
		}
	}

	return *this;
}

List_1& List_1::operator=(List_1&& other)noexcept
{
	if (this == &other) return *this;

	this->clear();
	this->count = other.count;
	this->head = other.head;
	other.head = nullptr;
	other.count = 0;


	return *this;
}



void List_1::push_back(const char& data)
{

		Element* add = new Element;
		add->data = data;
		add->next = nullptr;

		Element* current = head;

		if (head)
		{

			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = add;
		}
		else
		{
			head = add;
		}
		count++;
	
}

void List_1::push_front(const char& data)
{
	//Element* temp = this->head;
	
	Element* add = new Element;
	add->data = data;
	add->next = nullptr;
	
	if (this->head)
	{
		add->next = this->head;
		this->head = add;
		
	}
	else
	{
		this->head = add;
		
	}
	count++;
}


void List_1::pop_back()
{
	if (head)
	{
		if (head->next != nullptr)
		{
			Element* current = head;

			while (current->next && current->next->next)
			{
				current = current->next;
			}

			delete current->next;
			current->next = nullptr;
			
		}
		else
		{
			delete head;
			head = nullptr;
		}

		count--;	
	}

}

void List_1::pop_front()
{
	if (this->head)
	{
		Element* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
}

void List_1::insert_after_data(const char& after, const char& src)
{
	if (this->containe(after))
	{
		Element* current = head;

		while (current->data != after)
		{
			current = current->next;
		}
		
		Element* add = new Element;
		add->data = src;
		add->next = nullptr;

		add->next = current->next;
		current->next = add;
		count++;
	}
	

}

void List_1::clear()
{
	if (head)
	{
		Element* current = head;
		Element* prev = head;

		while (current)
		{
			current = current->next;
			delete prev;
			prev = current;
			
		}
		count = 0;
		head = nullptr;

	}
	
}

void List_1::show() const
{
	if (this->head == nullptr)
	{
		cout << "\nСписок пуст";
		return;
	}
	Element* current = this->head;

	/*for (int i = 0; i < count; i++)
	{
		
		cout << current->data << " ";
		current = current->next;
	}*/
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;

}


int List_1::get_index_by_data(const char& data)
{
	int index = 0;
	bool found = false;

	Element* current = head;

	while (current)
	{

		if (current->data == data)
		{
			found = true;
			break;
		}

		index++;
		current = current->next;
	}

	if (!found) index = -1; // если данных нет то вернем -1

	return index;

}

char List_1::get_data_by_index(const int& index)const
{
	if (index < 0 || index >= count) return '\0'; 

	int cnt = 0;

	if (head)
	{
		Element* current = head;
		
		while (cnt < index && current)
		{
			//if (cnt == index) return current->data;
			cnt++;
			current = current->next;

		}
		if (current)
		{
			return current->data; 
		}
		
	}

	return '\0';

}

void List_1::insert_elem_by_index(const int& index)
{
	if (index < 0 || index >= count) return; 

	Element* current = this->head;
	int cnt = 0;

	while (current)
	{
		if (cnt == index - 1) break;
		cnt++;
		current = current->next;
	}

	if (current && current->next)  
	{
		Element* add = new Element;
		add->data = char();
		add->next = current->next;
		current->next = add;
		count++;
	}
}

void List_1::erase_by_index(const int& index)
{
	if (index < 0 || index >= count) return; 
		
	if (index) 
	{

		Element* prev = head;
		int cnt = 0;

		while (cnt < index - 1 && prev)
		{
			prev = prev->next;
			cnt++;
		}

		if (prev && prev->next)
		{
			Element* to_delete = prev->next;
			prev->next = to_delete->next;
			delete to_delete;
			
		}
	}
	else
	{
		Element* to_delete = head;
		head = head->next;
		delete to_delete;
		
	}
	count--;
}

void List_1::insert_data_before_index(const int& index, const char& data)
{
	if (index < 0 || index >= count) return;

	if (index == 1)
	{
		this->push_front(data);
		return;
	}


	Element* current = this->head;
	int cnt = 0;

	while (current)
	{
		if (cnt == index - 2) break;
		cnt++;
		current = current->next;
	}

	if (current && current->next)
	{
		Element* add = new Element;
		add->data = data;
		add->next = current->next;
		current->next = add;
		count++;
	}

}


bool List_1::containe(const char& data) const
{
	if (!this->head)
		return false;
	Element* current = this->head;

	while (current != nullptr)
	{

		if (current->data == data)
		{
			return true;

		}

		current = current->next;

	}
	

	return false;
}

bool List_1::operator<(const List_1& other) const
{
	return this->count < other.count;
}

bool List_1::operator>(const List_1& other) const
{
	return this->count > other.count;
}

bool List_1::operator==(const List_1& other) const
{
	bool equal = true;

	if (this->count == other.count)
	{
		Element* current_this = this->head;
		Element* current_other = other.head;

		while (current_this)
		{
			if (current_this->data != current_other->data)
			{
				equal = false;
				break;
			}

			current_this = current_this->next;
			current_other = current_other->next;
		}

	}
	else
	{
		equal = false;
	}

	return equal;
}

bool List_1::operator!=(const List_1& other) const
{
	return !(*this == other);
}

bool List_1::operator>=(const List_1& other) const
{
	return ((*this > other) || (*this == other));
}

bool List_1::operator<=(const List_1& other) const
{
	return ((*this < other) || (*this == other));
}

List_1 List_1::operator+(const List_1& other) const
{
	List_1 temp = *this;
	
	Element* other_current = other.head;

	while (other_current)
	{
		temp.push_back(other_current->data);
		other_current = other_current->next;
	}
	
	return temp;
}

List_1 List_1::operator-() const
{
	List_1 temp;
	Element* current = this->head;
	while (current)
	{
		temp.push_front(current->data);
		current = current->next;
	}
	temp.count = this->count;
	return temp;
}

List_1 List_1::operator*(const List_1& other) const
{
	if (this == &other) return *this;
	
	List_1 temp;

	Element* this_current = this->head;
	Element* other_current = other.head;

	while (this_current)
	{
		while (other_current)
		{
			if (this_current->data == other_current->data)
			{
				temp.push_back(other_current->data);
			}

			other_current = other_current->next;
		}
		other_current = other.head;
		this_current = this_current->next;
	}
	

	return temp;
}



List_1::~List_1()
{
	Element* current = this->head;
	Element* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = nullptr;
}

ostream& operator<<(ostream& out, const List_1& obj)
{
	

	if (obj.head)
	{
		Element* current = obj.head;

		while (current)
		{
			out << current->data << " ";
			current = current->next;
		}
	}
	else
	{
		out << "\nСписок пуст.";
	}


	return out;
}

istream& operator>>(istream& in, List_1& obj)
{
	char input;
	cout << "\nДобавление в начало списка. Введите символ :";
	in >> input;
	obj.push_front(input);
	return in;
}
