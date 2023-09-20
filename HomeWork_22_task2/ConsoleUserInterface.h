#pragma once
#include <Windows.h>
#include "MyString.h"
#include "User.h"

class ConsoleUserInterface
{
private:

	
	HANDLE hConsole;
	MyString menu[7];
	User temp_user;
	MyString current_user_login;
	MyString input_login, input_password, input_message,buffer, buffer_msg;
	int state_menu;
	int param;
	bool chose;
	

	void set_color(int ForgC);
	void set_color(int text, int fon);
	void setcur(int x = 0, int y = 0);
	void console_cursor_visible(bool show = false, short size = 100);



public:


	ConsoleUserInterface();

	void init();
	void draw_menu();
	void input();

	void set_state_menu(int state);
	int get_state_menu()const { return this->state_menu; }
	bool get_chose()const;
	void set_param(int param) { this->param = param; }
	int get_param()const { return param; }
	void set_chose(bool chose);
	void set_current_user_login(const MyString user_login_name) { this->current_user_login = user_login_name; }
	MyString get_current_user_login()const { return this->current_user_login; }
	void choice(int state = 0);
	MyString get_input_login() { return input_login; }
	MyString get_input_password() { return input_password; }
	User& get_entered_user() { return temp_user; }
	MyString get_buffer()const { return this->buffer; }
	MyString get_buffer_msg()const { return this->buffer_msg; }
};

