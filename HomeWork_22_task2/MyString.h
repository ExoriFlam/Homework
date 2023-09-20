#pragma once
#include <iostream>

class MyString
{
	char* str;
	int length;


	void dyn_str_copy(char*& destination, const char* source);

public:

	MyString();
	MyString(const char* str);
	MyString(int len, char symbol);
	MyString(const MyString& obj);
	MyString(MyString&& obj)noexcept;

	void init(const char* str); // set
	int get_length()const;


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
	void save_to_bin_file(FILE* file)const;
	void read_from_bin_file(FILE* file);
	char* get_str()const { return this->str; }

	operator char* ()const;

	void save_to_txt(std::fstream& f_out)const;

	friend std::ostream& operator<<(std::ostream& f_out, const MyString& str);
	friend std::istream& operator>>(std::istream& f_in, MyString& str);

	friend std::ofstream& operator<<(std::ofstream& f_out, const MyString& obj);
	friend std::ifstream& operator>>(std::ifstream& f_in, MyString& obj);
	~MyString();
};