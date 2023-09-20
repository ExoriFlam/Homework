#pragma once
#include "MyString.h"
#include <fstream>
#include "ListTwoTemplate.h"
#include "User.h"

class FileManager
{
private:

	fstream to_txt;
	ofstream to_bin;
	ifstream from_bin;

public:
	FileManager();

	bool save_to_txt(const ListTwoTemplate<User>& src);
	bool save_to_bin(const ListTwoTemplate<User>& src);
	bool read_from_bin_to(ListTwoTemplate<User>& user_list);

	~FileManager();

};