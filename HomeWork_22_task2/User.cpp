#include "User.h"

#include <fstream>
User::User() :
	login{ "does not exist" }, password{ "does not exist" }, email{ "does not exist" },
	name{ "not authorized" }, surename{ "does not exist" }, birthday{ "12.12.1912" }, inbox{"Список сообщений: "} {}


void User::set_login(const MyString& login)
{
	this->login = login;
}
void User::set_password(const MyString& password)
{
	this->password = password;
}
void User::set_email(const MyString& email)
{
	this->email = email;
}
void User::set_name(const MyString& name)
{
	this->name = name;
}
void User::set_surename(const MyString& surename)
{
	this->surename = surename;
}
void User::set_birthday(const MyString& birthday)
{
	this->birthday.set_date(birthday);
}
void User::add_message(const MyString& msg)
{
	
	inbox += " \n";
	inbox += msg;
}
void User::show_all_msg() const
{
	cout << inbox;
}
void User::show() const
{
	cout << "\nЛогин........:" << login;
	cout << "\nПароль.......:" << password;
	cout << "\nEmail........:" << email;
	cout << "\nИмя..........:" << name;
	cout << "\nФамилия......:" << surename;
	cout << "\nДата рождения:" << birthday << "\n";
}
MyString User::get_login() const
{
	return this->login;
}
bool User::operator==(const User& other) const
{
	return this->login == other.login;
}
bool User::check_email() const
{
	bool success_check = false;

	for (int i = 0; i < email.get_length(); i++)
	{
		if (email[i] == '@')
		{
			success_check = true;
		}
	}

	return success_check;
}
bool User::check_user_input_lengths() const
{
	if (login.get_length() < 4) return false;
	if (password.get_length() < 4) return false;
	if (email.get_length() < 8) return false;
	if (name.get_length() < 3) return false;
	if (surename.get_length() < 3) return false;

	return true;
}
void User::save_to_txt(std::fstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out << "Login:     ";login.save_to_txt(f_out);
	f_out << "Password:  "; password.save_to_txt(f_out);
	f_out << "Email:     "; email.save_to_txt(f_out);
	f_out << "Name:      "; name.save_to_txt(f_out);
	f_out << "Surname:   "; surename.save_to_txt(f_out);
	f_out << "Date of birthday: "; birthday.save_to_txt(f_out);
	f_out << "\n"; inbox.save_to_txt(f_out);
	f_out << "======================================\n";
	
}

std::ofstream& operator<<(std::ofstream& f_out, const User& obj)
{
	if (!f_out.is_open()) return f_out;

	f_out << obj.login << obj.password << obj.email << obj.name <<
			 obj.surename << obj.birthday << obj.inbox;

	return f_out;
}

std::ifstream& operator>>(std::ifstream& f_in, User& obj)
{
	if (!f_in.is_open()) return f_in;
	
	f_in >> obj.login >> obj.password >> obj.email >> obj.name >>
		obj.surename >> obj.birthday >> obj.inbox;

	return f_in;
}
