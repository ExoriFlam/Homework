#pragma once
#include "iPet.h"


class Cat : public iPet
{
public:

	Cat();
	Cat(const MyString& name, const MyString& color);

	void Sound()override;
	void Show()override;
	void Type()override;

	~Cat()override;
};

