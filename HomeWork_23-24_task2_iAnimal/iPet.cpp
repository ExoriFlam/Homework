#include "iPet.h"

iPet::iPet()
{
	this->name = "отсутсвует";
	this->color = "отсутсвует";
}

iPet::iPet(const MyString& name, const MyString& color)
{
	this->name = name;
	this->color = color;
}

void iPet::Show()
{
	std::cout << "\n кличка: " << name;
	std::cout << "\n цвет:   " << color;
}

iPet::~iPet() {}
