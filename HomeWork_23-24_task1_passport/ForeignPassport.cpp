#include "ForeignPassport.h"

ForeignPassport::ForeignPassport() : Passport(), passport_nbr {"<blank>"} {}

ForeignPassport::ForeignPassport(const MyString surname, const MyString name, char sex, const MyString citizen,
	const MyString date_of_birth, const MyString date_of_issue, const MyString date_of_expiry, const MyString passport_nbr) :
	Passport(surname, name, sex, citizen, date_of_birth, date_of_issue, date_of_expiry), passport_nbr{ passport_nbr } {}



void ForeignPassport::add_visa(visa& visa)
{
	visas.push_back(visa);

}

void ForeignPassport::show() const
{
	Passport::show();
	cout << "\nСписок виз...: \n";
	for (int i = 0; i < visas.get_count(); i++)
	{
		cout << visas[i];
	}
}
