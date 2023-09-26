#include "Passport.h"

Passport::Passport() :
	surname{ "<blank>" }, name{ "<blank>" }, sex{ 's'}, citizenship{"<blank>"} {}

Passport::Passport(const MyString surname, const MyString name, char sex, const MyString citizen,
	   const MyString date_of_birth, const MyString date_of_issue, const MyString date_of_expiry):
	surname{ surname }, name{ name }, sex{ sex }, citizenship{ citizen }
{
	of_birth.set_date(date_of_birth);
	of_issue.set_date(date_of_issue);
	of_expiry.set_date(date_of_expiry);
}

void Passport::show() const
{
	cout << "\nФамилия......: " << this->surname;
	cout << "\nИмя..........: " << this->name;
	cout << "\nПол..........: " << this->sex;
	cout << "\nГражданство..: " << this->citizenship;
	cout << "\nДата рождения: " << this->of_birth;
	cout << "\nДата выдачи..: " << this->of_issue;
	cout << "\nГоден до.....: " << this->of_expiry;
}
