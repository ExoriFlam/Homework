#pragma once
#include "MyString.h"
#include "Date.h"

class Passport
{
private:

	MyString surname;
	MyString name;
	char sex;
	MyString citizenship;
	Date of_birth;
	Date of_issue;
	Date of_expiry;


public:
	Passport();
	Passport(const MyString surname, const MyString name, char sex, const MyString citizen,
		const MyString date_of_birth, const MyString date_of_issue, const MyString date_of_expiry);
	void show()const;
};

