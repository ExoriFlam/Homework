#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Date
{

private:

	int day;
	int month;
	int year;

	void correct();
	void reset();
	template<typename T>
	T check_input();

public:
	Date();
	Date(int day, int month, int year);
	Date(const char* date_in_str);

	int operator-(const Date& other)const;
	Date& operator++();
	const Date operator++(int);
	Date& operator--();
	const Date operator--(int);
	explicit operator int()const;
	Date& operator+=(int _days);
	bool operator>(const Date& other)const;
	bool operator<(const Date& other)const;
	bool operator==(const Date& other)const;
	bool operator!=(const Date& other)const;
	
	friend ostream& operator<<(ostream& out,const Date& obj);
	friend istream& operator>>(istream& in, Date& obj);
	
	void save_to_txt(std::fstream& f_out)const;
	friend std::ofstream& operator<<(std::ofstream& f_out, const Date& obj);
	friend std::ifstream& operator>>(std::ifstream& f_in, Date& obj);

	int get_day()const;

	
	int get_month()const;

	void set_date(const char* date_in_str);

	const char* get_month_in_str()const;

	
	int get_year()const;

	


};

template<typename T>
T Date::check_input()
{
	T temp;

	cin >> temp;
	while (cin.fail())
	{
		cout << "\nרטבךא גגמהא.";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp;
	}

	return temp;
}
