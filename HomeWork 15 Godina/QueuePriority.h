#pragma once
#include <iostream>
using namespace std;

class QueuePriority
{
private:
	int* queue;
	int* priority;				
	int max_length;			
	int length;		

public:

	QueuePriority(int m);
	QueuePriority(const QueuePriority& other);
	QueuePriority(QueuePriority&& other)noexcept;
	QueuePriority& operator=(const QueuePriority& other);
	QueuePriority& operator=(QueuePriority&& other)noexcept;
	friend ostream& operator<<(ostream& out,const QueuePriority& obj);

	~QueuePriority();			
	void Add(int elem, int prty);		
	int Extract();			
	void Clear();			
	bool IsEmpty()const;			
	bool IsFull()const;			
	int GetCount()const;			
		
};
