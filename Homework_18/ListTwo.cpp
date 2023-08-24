#include "ListTwo.h"
using namespace std;


ListTwo::ListTwo()
{
	this->head = this->tail = nullptr;
	count = 0;
}

ListTwo::ListTwo(const ListTwo& other)
{
	Node* other_current = other.head;
	while (other_current)
	{
		this->push_back(other_current->data);
		other_current = other_current->next;
	}
}

ListTwo::ListTwo(ListTwo&& other) noexcept
{
	this->count = other.count;
	this->head = other.head;
	this->tail = other.tail;
	other.head = other.tail = nullptr;
	other.count = 0;

}

ListTwo& ListTwo::operator=(const ListTwo& other)
{
	if (this == &other)return *this;

	this->clear();
	Node* current_other = other.head;

	while (current_other)
	{
		this->push_back(current_other->data);
		current_other = current_other->next;
	}

	return *this;
}

ListTwo& ListTwo::operator=(ListTwo&& other) noexcept
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

ListTwo ListTwo::operator+(const ListTwo& other)
{
	ListTwo temp = *this;

	Node* other_current = other.head;

	while (other_current)
	{
		temp.push_back(other_current->data);
		other_current = other_current->next;
	}

	return temp;
}

void ListTwo::push_back(const int& add)
{
	Node* temp = new Node(add);

	if (tail)
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

void ListTwo::show(bool dir) const
{
	if (this->head == nullptr)
	{
		cout << "\nСписок пуст";
		return;
	}
	if (dir)
	{
		Node* current = this->head;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	else
	{
		Node* current = this->tail;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
	


}

void ListTwo::push_front(const int& add)
{
	Node* temp = new Node(add);

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

void ListTwo::insert_before_found_data(const int& data_for_srch, const int& ins_data)
{
	
	if (head)
	{
		Node* current = head;
		Node* to_add = new Node(ins_data);
		while (current)
		{
			if (current->data == data_for_srch) break;
			current = current->next;
		}
	
		if (!current) //<- без этой проверки компилятор ругается на карент
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

void ListTwo::insert_after_found_data(const int& data_for_srch, const int& ins_data)
{
	
	
	if (head)
	{
		Node* current = head;
		Node* to_add = new Node(ins_data);
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

void ListTwo::pop_front()
{
	if (head)
	{
		Node* to_del = head;
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

void ListTwo::pop_back()
{

	if (tail)
	{
		Node* to_del = tail;
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

void ListTwo::clear()
{
	while (head)
	{
		Node* to_del = head;
		head = head->next;
		delete to_del;
	}

	tail = nullptr;
	count = 0;

}

void ListTwo::erase_by_data(const int& data_for_srch)
{
	if (head)
	{
		Node* current = head;
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

void ListTwo::erase_by_index(const int& indx)
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
		Node* to_del = nullptr;
		Node* current_head = head;
		Node* current_tail = tail;

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
			cnt = count - 1;

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

void ListTwo::insert_before_index(const int& indx)
{
	if (indx < 0 || indx > count - 1) return;

	if (indx == 0)
	{
		push_front(int());
		return;
	}
	else if (indx == count - 1)
	{
		push_back(int());
		
		int tmp = tail->data;
		tail->data = tail->prev->data;
		tail->prev->data = tmp;
		return;
	}

	
	int cnt = 0;
	Node* current_head = head;
	Node* current_tail = tail;
	Node* current_add = nullptr;

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
		Node* to_add = new Node(int());

		to_add->next = current_add;
		to_add->prev = current_add->prev; 
		current_add->prev->next = to_add;
		current_add->prev = to_add;

		count++;
	}
	

}

ListTwo::~ListTwo()
{

	Node* current = this->head;
	Node* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = tail = nullptr;
}

ostream& operator<<(ostream& out, const ListTwo& obj)
{
	if (obj.head)
	{
		Node* current = obj.head;
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

istream& operator>>(istream& in, ListTwo& obj)
{
	int input;
	cout << "\n Введите новый элемент списка  тип Int:\n->";
	in >> input;

	while (in.fail())
	{
		cout << "\n Ошибка ввода!\nВведите цифру:\n->";
		in.clear();
		in.ignore(256, '\n');
		in >> input;
	}

	obj.push_back(input);

	return in;
}
