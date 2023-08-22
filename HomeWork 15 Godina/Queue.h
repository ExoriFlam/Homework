#pragma once
#include <iostream>
using namespace std;

class Queue
{
	int* buffer;             
	int max_length;         
	int length;           
public:
	explicit Queue(int max_size = 10);   
	Queue(const Queue& other);
	Queue(Queue&& other)noexcept;
	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other)noexcept;
	friend ostream& operator<<(ostream& out, const Queue& obj);
	~Queue();                   
	void Add(int elem);            
	int Extract();             
	void Clear();               
	bool IsEmpty()const;            
	bool IsFull()const;             
	int GetCount()const;             
	             
};
