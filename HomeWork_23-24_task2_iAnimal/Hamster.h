#pragma once
#include "iPet.h"

class Hamster : public iPet
{
public:
	Hamster();
	Hamster(const MyString& name, const MyString& color);

	void Sound()override;
	void Show()override;
	void Type()override;

	~Hamster()override;
};

