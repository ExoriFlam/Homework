#pragma once
#include <iostream>
using namespace std;


class Coord
{
private:

	static int count; 
	enum { MIN = -500, MAX = 500 }; 

	int x;
	int y;
	
	void correct();
	template<typename T>
	T check_input();

public:

	Coord();
	Coord(const int x,const int y);
	explicit Coord(const int value); 
	explicit Coord(const char* str); 
	Coord(const Coord& obj);

	void set_x(int val);
	void set_y(int val);

	int get_x()const;
	int get_y()const;

	static int get_count() {
		return count;
	}

	void reset_x_y(int x = 0, int y = 0);


	Coord operator+(const Coord& obj)const;
	Coord operator+(const int val);
	Coord& operator+=(const Coord& obj);
	bool operator==(const Coord& obj) const;
	bool operator!=(const Coord& obj) const;
	bool operator>(const Coord& obj) const;
	Coord& operator++();
	const Coord operator++(int);
	Coord operator-()const;
	void operator()(const int a, const int b);
	operator int();
	operator double();

	friend ostream& operator<<(ostream& out, const Coord& right);
	friend istream& operator>>(istream& in, Coord& right);
	friend Coord operator+(const int left, const Coord& right);

	~Coord();
};

template<typename T>
inline T Coord::check_input()
{
	T temp;
	cin >> temp;
	while (cin.fail())
	{
		cout << "\nרטבךא גגמהא!";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp;
	}
	return temp;
}
