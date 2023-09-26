#pragma once
#include "Passport.h"
#include "MyString.h"
#include "ListTwoTemplate.h"
#include "Visa.h"
class ForeignPassport : public Passport
{
private:

	MyString passport_nbr;
	ListTwoTemplate<visa> visas;

public:

	ForeignPassport();
	ForeignPassport(const MyString surname, const MyString name, char sex, const MyString citizen,
		const MyString date_of_birth, const MyString date_of_issue, const MyString date_of_expiry, const MyString passport_nbr);

	void add_visa(visa& visa);
	void show()const;
};

