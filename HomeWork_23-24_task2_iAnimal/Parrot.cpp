#include "Parrot.h"
#include <iostream>
#include <Windows.h> 
#include <MMSystem.h>

using std::cout;

Parrot::Parrot() : iPet() {}

Parrot::Parrot(const MyString& name, const MyString& color) : iPet(name, color) {}

void Parrot::Sound()
{
	cout << "\nчирик-чирик";
	PlaySound(TEXT("sounds\\parrot.wav"), NULL, SND_SYNC);
}

void Parrot::Show()
{
	iPet::Show();
}

void Parrot::Type()
{
	cout << "\n класс птиц";
}

Parrot::~Parrot()
{
}
