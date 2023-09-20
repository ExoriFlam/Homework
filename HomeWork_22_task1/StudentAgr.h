#pragma once
#include <fstream>
#include <iostream>
#include "ListTwoTemplate.h"
#include <fstream>
#include "My_Array.h"
#include "MyString.h"
class StudentAgr
{
private:

	MyString surname;
	MyString name;
	int age;
	MyString vuz;
	MyArray marks;
	ListTwoTemplate<MyString> subjects;

public:

	StudentAgr();
	StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz,
		const MyArray& marks, const ListTwoTemplate<MyString>& subjects);

	friend ostream& operator<<(ostream& out, const StudentAgr& obj);

	friend ofstream& operator<<(ofstream& f_out,const StudentAgr& obj);
	friend ifstream& operator>>(ifstream& f_in, StudentAgr& obj);
	void save_to_txt(fstream& f_out)const;

	bool operator<(const StudentAgr& other);
	double get_avg();
	void add_subject(const MyString& data);
	void save_txt(FILE* f)const;
	void save_to_bin_file(FILE* file)const;
	void read_from_bin_file(FILE* file);

};