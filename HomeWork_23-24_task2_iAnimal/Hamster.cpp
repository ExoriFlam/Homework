#include "Hamster.h"
#include <iostream>
#include <Windows.h> 
#include <MMSystem.h>

using std::cout;

Hamster::Hamster() : iPet() {}

Hamster::Hamster(const MyString& name, const MyString& color) : iPet(name, color) {}

void Hamster::Sound()
{
	cout << "\nХрум-хрум";
	PlaySound(TEXT("sounds\\hamster.wav"), NULL, SND_SYNC);
}

void Hamster::Show()
{
	iPet::Show();
}

void Hamster::Type()
{
	cout << "\nОтряд грызунов";
}

Hamster::~Hamster()
{
}
