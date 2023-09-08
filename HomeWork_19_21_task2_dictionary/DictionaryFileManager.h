#pragma once
#include "MyString.h"
#include "EngRusTree.h"


class DictionaryFileManager
{
private:

	FILE* txt;
	FILE* bin;
	
	MyString dictionary_t, dictionary_b;

public:
	DictionaryFileManager();

	void set_txt_fname(const char* new_name);
	void set_bin_fname(const char* new_name);

	bool save_to_txt(EngRusTree& src);
	bool save_to_bin(EngRusTree& src);
	bool read_from_bin_to(EngRusTree& destination);
	
	~DictionaryFileManager();

};