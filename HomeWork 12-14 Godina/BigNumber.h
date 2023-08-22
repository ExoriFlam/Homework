#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class BigNumber
{
private:

	enum{SIZE = 80};
	int arr[SIZE];
	
public:
	
	BigNumber();
	explicit BigNumber(const int value);
	explicit BigNumber(const char* str);
	BigNumber(int* other_arr, int other_size);
	BigNumber(const BigNumber& other);
	BigNumber& operator=(const BigNumber& other);
	BigNumber operator+(const BigNumber& other);
	friend ostream& operator<<(ostream& out, const BigNumber& obj);

};
