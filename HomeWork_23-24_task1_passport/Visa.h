#pragma once
#include "Date.h"
#include "MyString.h"
#include <iostream>
struct visa
{
	struct entry
	{
		MyString transport_type;
		Date date_entrance;
		MyString customs_name;

		entry() : transport_type{ "<blank>" }, customs_name{ "<blank>" }
		{
			date_entrance.set_date("1.1.1");
		}

	};

	struct exit
	{
		MyString transport_type;
		Date date_exit;
		MyString customs_name;

		exit() : transport_type{ "<blank>" }, customs_name{ "<blank>" }
		{
			date_exit.set_date("1.1.1");
		}
	};


	entry entry;
	exit exit;
	friend ostream& operator<<(ostream& out, const visa obj)
	{
		out << "\n=================";
		out << "\nДата въезда......:" << obj.entry.date_entrance;
		out << "\nНазвание таможнии:" << obj.entry.customs_name;
		out << "\nТип транспорта...:" << obj.entry.transport_type;
		

		out << "\nДата выезда......:" << obj.exit.date_exit;
		out << "\nНазвание таможнии:" << obj.exit.customs_name;
		out << "\nТип транспорта...:" << obj.exit.transport_type;
		out << "\n=================\n";
		return out;
	}

};