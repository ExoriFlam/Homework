#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int length;
	static int count;

	void dyn_str_copy(char*& destination, const char* source);

public:

	MyString();
	MyString(const char* str);
	MyString(int len, char symbol);
	MyString(const MyString& obj);
	MyString(MyString&& obj)noexcept;

	void init(const char* str); // set
	int get_length()const;
	
	static int getCount();
	MyString& operator=(const MyString& obj);
	MyString& operator=(MyString&& obj)noexcept;
	const char operator[](const int index)const;
	char& operator[](const int index);
	bool operator ==(const MyString& other)const;
	bool operator !=(const MyString& other)const;
	bool operator >(const MyString& other)const;
	bool operator <(const MyString& other)const;
	bool operator >=(const MyString& other)const;
	bool operator <=(const MyString& other)const;
	MyString operator+(const MyString& other)const;
	MyString& operator+=(const MyString& other);
	void operator()(const char* str);
	operator char* ();


	friend ostream& operator<<(ostream& out, const MyString& str);
	friend istream& operator>>(istream& in, MyString& str);

	~MyString();
};

