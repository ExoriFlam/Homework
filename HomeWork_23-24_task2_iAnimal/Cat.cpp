#include "Cat.h"
#include <iostream>
#include <Windows.h> 
#include <MMSystem.h>

using std::cout;

Cat::Cat() : iPet() {}


Cat::Cat(const MyString& name, const MyString& color) : iPet(name, color) {}


void Cat::Sound()
{
	cout << "\n мяу-мяу";
	PlaySound(TEXT("sounds\\cat.wav"), NULL, SND_SYNC);
}

void Cat::Show()
{
	iPet::Show();
}

void Cat::Type()
{
	cout << "\n семейсво кошачих";
}

Cat::~Cat() {}

