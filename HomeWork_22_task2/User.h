#pragma once
#include <iostream>
#include "MyString.h"

#include "Date.h"

class User
{
private:

	
	MyString login;
	MyString password;
	MyString email;
	MyString name;
	MyString surename;
	Date birthday;
	MyString inbox;

public:

	User();

	void set_login(const MyString& login);
	void set_password(const MyString& password);
	void set_email(const MyString& email);
	void set_name(const MyString& name);
	void set_surename(const MyString& surename);
	void set_birthday(const MyString& birthday);
	
	MyString get_login()const;
	MyString get_email()const { return email; }
	MyString get_password()const { return this->password; }
	void add_message(const MyString& msg);
	void show_all_msg()const;

	void show()const;
	
	

	bool operator==(const User& other)const;

	bool check_email()const;
	bool check_user_input_lengths()const;

	void save_to_txt(std::fstream& f_out)const;
	friend std::ofstream& operator<<(std::ofstream& f_out, const User& obj);
	friend std::ifstream& operator>>(std::ifstream& f_in, User& obj);

};

