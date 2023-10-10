#pragma once
#include<iostream>
#include<fstream>

class MyArray
{
private:

	unsigned int size;
	int* arr;
	char* to_str_type;
	template<typename T>
	T check_input();

public:
	MyArray();
	MyArray(int size, int init_val = 0);
	MyArray(int size, int* other_arr);
	MyArray(const MyArray& other);
	MyArray(MyArray&& other)noexcept;
	MyArray(int size, int range_begin, int range_end);


	MyArray& operator=(const MyArray& other);
	MyArray& operator=(MyArray&& other)noexcept;
	int& operator[](const int& index);
	const int operator[](const int& index)const;
	MyArray operator+(const MyArray& other)const;
	MyArray operator+(const int)const;
	MyArray& operator+=(int val);
	MyArray& operator+=(MyArray& other);
	friend MyArray operator+(int val, const MyArray& other);
	friend std::ostream& operator<<(std::ostream& out, const MyArray& obj);
	friend std::istream& operator>>(std::istream& in, MyArray& obj);
	friend std::ofstream& operator<<(std::ofstream& f_out,const MyArray& obj);
	friend std::ifstream& operator>>(std::ifstream& f_in, MyArray& obj);
	
	void save_to_txt(std::fstream& f_out)const;

	void save_to_bin_file(FILE* file)const;
	void read_from_bin_file(FILE* file);
	operator int();
	operator double();
	operator char* ();

	unsigned int get_size()const;

	int get_avg()const;


	void push_back(int val);


	~MyArray();
};


template <typename T>
T MyArray::check_input()
{
	T temp;
	std::cin >> temp;
	while (std::cin.fail())
	{
		std::cout << "\n Ошибка ввода!";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> temp;
	}
	return temp;
}