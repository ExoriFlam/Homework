#pragma once
#include <Windows.h>
#include "MyString.h"
class DictionaryConsole
{
private:

	enum { UP = 72, DOWN = 80, ENTER = 13 };
	HANDLE hConsole;
	MyString menu[7];
	int param;
	bool chose;
	MyString eng,ru;

	void set_color(int ForgC);
	void set_color(int text, int fon);
	void setcur(int x = 0, int y = 0);
	void console_cursor_visible(bool show = false, short size = 100);

	

public:


	DictionaryConsole();
	
	void init();
	void draw_menu();
	void input();

	bool get_chose()const;
	int get_param()const { return param; }
	void set_chose(bool chose);
	void choice(bool prm = true);
	MyString get_from_buff_eng()const { return eng; }
	MyString get_from_buff_ru()const {return ru;}
	void set_buff_eng(const MyString& str);
	void set_buff_ru(const MyString& str);
};

