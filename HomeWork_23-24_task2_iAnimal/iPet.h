#pragma once
#include "MyString.h"

class iPet
{
private:

	MyString name;
	MyString color;

public:

	iPet();
	iPet(const MyString& name, const MyString& color);

	virtual void Sound() = 0;
	virtual void Show();
	virtual void Type() = 0;

	virtual ~iPet();
};

