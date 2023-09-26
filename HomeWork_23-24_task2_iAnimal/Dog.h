#pragma once
#include "iPet.h"
class Dog : public iPet
{
public:

	Dog();
	Dog(const MyString& name, const MyString& color);

	void Sound()override;
	void Show()override;
	void Type()override;

	~Dog()override;
};

