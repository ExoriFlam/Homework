#pragma once
#include "iPet.h"
class Parrot : public iPet
{
public:
	Parrot();
	Parrot(const MyString& name, const MyString& color);

	void Sound()override;
	void Show()override;
	void Type()override;

	~Parrot()override;
};

