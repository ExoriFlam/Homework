#pragma once
#include "User.h"
#include "ListTwoTemplate.h"

class AccountManager
{
private:

	ListTwoTemplate<User> users;
	User current_user;

public: 

	ListTwoTemplate<User>& get_users() { return users; };
	bool add_user(const User& user);
	bool find_user(const User& user);
	void add_user_msg(MyString email,MyString msg);
	bool find_login(const MyString& login, const MyString& pass)const;
	bool find_email(const MyString& email)const;
	bool set_current_user(const MyString& login);
	User& get_current_user() { return current_user; }
	void set_defoult_user(const User& defoult) { current_user = defoult; }
	MyString get_current_user_login_name()const { return current_user.get_login(); }
	void show_all_emails()const;



};

