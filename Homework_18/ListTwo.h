#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node()
	{
		data = 0;
		this-> next = prev = nullptr;

	}

	Node(const int& data)
	{
		
		this -> data = data;
		this-> next = prev = nullptr;
		
	}

};


class ListTwo
{
	Node* head;
	Node* tail;
	int count;

public:

	ListTwo();
	ListTwo(const ListTwo& other);
	ListTwo(ListTwo&& other)noexcept;

	ListTwo& operator=(const ListTwo& other);
	ListTwo& operator=(ListTwo&& other)noexcept;
	ListTwo operator+(const ListTwo& other);
	void push_back(const int& add);
	void show(bool dir = false)const;
	
	void push_front(const int& add);

	void insert_before_found_data(const int& data_for_srch, const int& ins_data);
	void insert_after_found_data(const int& data_for_srch, const int& ins_data);

	void pop_front();
	void pop_back();
	void clear();

	int get_count()const { return this->count; }

	void erase_by_data(const int& data_for_srch);
	void erase_by_index(const int& indx);
	void insert_before_index(const int& indx);


	friend ostream& operator<< (ostream& out, const ListTwo& obj);
	friend istream& operator>> (istream& in, ListTwo& obj);

	~ListTwo();
};