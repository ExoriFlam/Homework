#pragma once
#include <iostream>
using namespace std;

class StackD
{
private:
	static const int MAX{ 10 };
	static int count;
	int size;    
	int* items;  
	int top;     
public:
	StackD(int s = MAX);
	StackD(const StackD& other);
	StackD(StackD&& other)noexcept;
	StackD& operator=(const StackD& other);
	friend ostream& operator<<(ostream& out, StackD& obj);
	StackD& operator=(StackD&& other)noexcept;

	bool is_empty() const { return top == 0; }
	bool is_full() const  { return top == size; }
	bool push(const int & item);		
	bool pop(int & item);				
	int get_сount() const{ return top; } 
	static int get_сount_all() {  return count; }
	~StackD() { count--; delete[] items; } 
};