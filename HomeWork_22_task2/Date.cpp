#include "Date.h"
#include <iostream>
using namespace std;



void Date::correct()
{
	bool to_correct = false;

	if (year < 0) year = 0;

	if (month < 0 || month > 12) month = 0;

	if (day < 0 || day > 31) day = 0;
	
	if (!day || !month || !year)
	{
		to_correct = true;
		
	}

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
			{
				to_correct = true;
				
			}
			
				
		}
		else
		{
			if (day > 28)
			{
				to_correct = true;
				
			}
		}

	}
	else
	{
		if ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1))
		{
			if (day > 30)
			{
				to_correct = true;
				
			}

		}
	}
	
	if (to_correct)
	{
		reset();
	}

}

void Date::reset()
{
	year = 0;
	day = 0;
	month = 0;
}

Date::Date() : day{ 1 }, month{ 1 }, year{ 1 } {}

Date::Date(int day, int month, int year) : day{ day }, month{ month }, year{ year } {this->correct();}

Date::Date(const char* date_in_str) : day{ 1 }, month{ 1 }, year{ 1 } { this->set_date(date_in_str);}

int Date::operator-(const Date& other)const
{
	return abs(static_cast<int>(*this) - static_cast<int>(other));
}

Date& Date::operator++()
{
	this->day++;

	bool is_month_30_days = (month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1);

	if (day > 30 && is_month_30_days && month != 2)
	{
		day = 1;
		month++;
	}
	else if (day > 31 && !is_month_30_days && month != 2)
	{
		day = 1;
		month++;
	}
	else if(month == 2)
	{
		if (day > 29 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			day = 1;
			month++;
		}
		else if (day > 28 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day = 1;
			month++;
		}
	}
	
	if (month > 12)
	{
		month = 1;
		year++;
	}


	return *this;
}

const Date Date::operator++(int)
{
	Date temp(*this);
	++(*this);
	return temp;
}

Date& Date::operator--()
{
	this->day--;

	bool is_month_30_days = (month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1);

	if (day == 0 && is_month_30_days && month)
	{
		day = 31;
		month--;
	}
	else if (day == 0 && !is_month_30_days && month != 3)
	{
		day = 30;
		month--;
	}
	else if (month == 3)
	{
		if (day == 0 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			day = 29;
			month--;
		}
		else if (day == 0 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day = 28;
			month--;
		}
	}

	if (month == 0)
	{
		month = 12;
		year--;
	}


	return *this;
}

const Date Date::operator--(int)
{
	Date temp(*this);
	--(*this);
	return temp;
}

Date::operator int()const
{

	int total_in_days = this->day;
	int cnt_leap_year = 0;
	
	


	for (int i = 0; i < this->year; i += 4)
	{
		
		cnt_leap_year += ((i % 100 != 0) || (i % 400 == 0));
		
	}

	total_in_days += this->year * 365;
	total_in_days += cnt_leap_year;

	for (int mth = 1; mth <= this->month; mth++)
	{
		if (mth == 2)
		{
			total_in_days += 28;

			total_in_days += (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			
		}
		else if ((mth <= 7 && mth % 2 == 0) || (mth > 7 && mth % 2 != 0))
		{
			total_in_days += 30;
		}
		else if ((mth <= 7 && mth % 2 != 0) || (mth > 7 && mth % 2 == 0))
		{
			total_in_days += 31;
		}

	}


	return total_in_days;
}

Date& Date::operator+=(int _days)
{
	this->day += _days;

	bool is_month_30_days = (month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1);

	if (day > 30 && is_month_30_days && month != 2)
	{
		month += day / 30;
		day %= 30;
	}
	else if (day > 31 && !is_month_30_days && month != 2)
	{
		month += day / 31;
		day %= 31;
	}
	else if (month == 2)
	{
		if (day > 29 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			month += day / 29;
			day %= 29;
		}
		else if (day > 28 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			month += day / 28;
			day %= 28;
		}
	}

	if (month > 12)
	{
		
		year += month/12;
		month %= 12;
	}


	return *this;
}

bool Date::operator>(const Date& other) const
{
	//return (int)*this > (int)other;// приводим оба объекта к инту и сравниваем но получаетс§ затратно.
	if (year > other.year)return true;
	if (year < other.year)return false;
	if (month > other.month)return true;
	if (month < other.month)return false;
	if (day > other.day)return true;
	if (day < other.day)return false;
	return false;
}

bool Date::operator<(const Date& other) const
{
	return !(*this > other);
}

bool Date::operator==(const Date& other) const
{
	
	return (this->year == other.year && this->month == other.month && this->day == other.day);
}

bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}



void Date::save_to_txt(std::fstream& f_out) const
{
	if (!f_out.is_open()) return;
	f_out << "| " << day << " : " << month << " : " << year << " | ";

}

int Date::get_day() const
{
	return day;
}



int Date::get_month() const
{
	return month;
}

void Date::set_date(const char* date_in_str)
{
	char str[40];

	strcpy_s(str, date_in_str);

	if (str[0] != '\0')
	{
		Date temp = *this;

		this->day = 0;
		this->month = 0;
		this->year = 0;

		int result = 0;

		int i = 0;

		while (str[i] != '\0')
		{
			if (!((str[i] - 0) > 47 && (str[i] - 0) < 58))
			{
				str[i] = '\0';

			}
			i++;
		}

		for (int j = 0; (j <= i); j++)
		{
			
			if (str[j] != '\0')
			{

				result *= 10;
				result += (str[j] - 48);

			}
			else if (result > 0)
			{
				if (!this->day)   
				{
					this->day = result;
					result = 0;

				}
				else if (!this->month)
				{
					this->month = result;
					result = 0;
				}
				else if (!this->year)
				{
					this->year = result;
					break;
				}
			}

		}


		correct();
		if (!day) (*this) = temp;

	}
	else
	{
		cout << "\nпуста¤ строка.";
		
	}
	

}

const char* Date::get_month_in_str()const
{
	switch (this->month)
	{
	case 1:
		return "¤нварь";
	case 2:
		return "февраль";
	case 3:
		return "март";
	case 4:
		return "апрель";
	case 5:
		return "май";
	case 6:
		return "июнь";
	case 7:
		return "июль";
	case 8:
		return "август";
	case 9:
		return "сент§брь";
	case 10:
		return "окт§брь";
	case 11:
		return "но¤брь";
	case 12:
		return "декабрь";
	default:
		return "\0";
	}

}


int Date::get_year() const
{
	return year;
}



ostream& operator<<(ostream& out, const Date& obj)
{
	out << obj.day << " : " << obj.month << " : " << obj.year;

	return out;
}

istream& operator>>(istream& in, Date& obj)
{
	
	cout << "\nђведите ?ень :  ";
	obj.day = obj.check_input<int>();
	
	cout << "\nђведите Юес§ц:  ";
	obj.month= obj.check_input<int>();

	cout << "\nђведите vод  :  ";
	obj.year = obj.check_input<int>();

	return in;
}

std::ofstream& operator<<(std::ofstream& f_out, const Date& obj)
{
	if (!f_out.is_open()) return f_out;

	f_out.write((char*)&obj.day, sizeof(int));
	f_out.write((char*)&obj.month, sizeof(int));
	f_out.write((char*)&obj.year, sizeof(int));

	return f_out;
}

std::ifstream& operator>>(std::ifstream& f_in, Date& obj)
{
	if (!f_in.is_open()) return f_in;

	f_in.read((char*)&obj.day, sizeof(int));
	f_in.read((char*)&obj.month, sizeof(int));
	f_in.read((char*)&obj.year, sizeof(int));

	return f_in;
}
