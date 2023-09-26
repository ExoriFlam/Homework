#include "Dog.h"
#include <iostream>
#include <Windows.h> 
#include <MMSystem.h>

using std::cout;

Dog::Dog() : iPet() {}

Dog::Dog(const MyString& name, const MyString& color) : iPet(name, color) {}

void Dog::Sound()
{
	cout << "\nГав-гав";
	PlaySound(TEXT("sounds\\dog.wav"), NULL, SND_SYNC);
}

void Dog::Show()
{
	iPet::Show();
}

void Dog::Type()
{
	cout << "\nСемейство псовых";
}

Dog::~Dog()
{
}
