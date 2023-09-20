#pragma once
#include "ConsoleUserInterface.h"
#include "AccountManager.h"
#include "FileManager.h"
#include "User.h"

class UserApp
{
private:

	ConsoleUserInterface console;
	AccountManager acc_manager;
	FileManager file_manager;

public:

	UserApp() = default;

	void run();
};

