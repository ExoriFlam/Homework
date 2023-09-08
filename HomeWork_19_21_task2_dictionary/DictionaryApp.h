#pragma once
#include "EngRusTree.h"
#include "DictionaryConsole.h"
#include "DictionaryFileManager.h"

class DictionaryApp
{
private:
	
	EngRusTree tree_dictionary;
	DictionaryConsole console;
	DictionaryFileManager file_manager;

public:
	
	DictionaryApp() = default;
	
	void run();

};