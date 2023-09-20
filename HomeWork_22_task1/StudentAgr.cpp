#include "StudentAgr.h"
#include "ListTwoTemplate.h"
#include "MyString.h"
#include "My_Array.h"
StudentAgr::StudentAgr()
{
	surname = "no surname";
	name = "no name";
	this->age = 0;
	vuz = "no vuz";
	marks = 0u;

}

StudentAgr::StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz, const MyArray& marks, const ListTwoTemplate<MyString>& subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}

void StudentAgr::save_to_txt(fstream& f_out)const
{
	if (!f_out.is_open()) return;
	f_out << "Surname: "; surname.save_to_txt(f_out); 
	f_out << "Name:    "; name.save_to_txt(f_out); 
	f_out << "Age:     " << this->age << "\n";
	f_out << "Vuz:     "; vuz.save_to_txt(f_out);
	f_out << "Marks:   "; marks.save_to_txt(f_out); f_out << "\n";
	f_out << "Subjects:"; subjects.save_to_txt(f_out);
}

bool StudentAgr::operator<(const StudentAgr& other)
{
	return surname < other.surname;
}

double StudentAgr::get_avg()
{
	return this->marks.get_avg();
}

void StudentAgr::add_subject(const MyString& data)
{
	this->subjects.push_back(data);
}

void StudentAgr::save_txt(FILE* f) const
{

	fprintf(f, "Surname: %s\n", (char*)surname);
	fprintf(f, "Name: %s\n", (char*)name);
	fprintf(f, "Age: %d\n", age);
	int i = 0;
	fprintf(f, "Subjects: ");
	while (i < subjects.get_count())
	{
		fprintf(f, "%s\n", (char*)subjects.get_by_pos(i++));

	}

	fprintf(f, "Vuz: %s\n", (char*)vuz);
	fprintf(f, "Marks: ");
	for (int i = 0; i < this->marks.get_size(); i++)
	{
		fprintf(f, "%d ", this->marks[i]);
	}

}

void StudentAgr::save_to_bin_file(FILE* file) const
{
	surname.save_to_bin_file(file);
	name.save_to_bin_file(file);
	fwrite(&this->age, sizeof(this->age), 1, file);
	vuz.save_to_bin_file(file);
	marks.save_to_bin_file(file);
	subjects.save_to_bin_file(file);

}

void StudentAgr::read_from_bin_file(FILE* file)
{

	surname.read_from_bin_file(file);
	name.read_from_bin_file(file);
	fread_s(&this->age, sizeof(this->age), sizeof(age), 1, file);
	vuz.read_from_bin_file(file);
	marks.read_from_bin_file(file);
	subjects.read_from_bin_file(file);

}





ostream& operator<<(ostream& out, const StudentAgr& obj)
{
	out << "\nSurname: " << obj.surname << endl;
	out << "\nName:    " << obj.name << endl;
	out << "\nAge:     " << obj.age << endl;
	out << "\nVuz:     " << obj.vuz << endl;
	if (obj.marks.get_size())
	{
		out << "\nMarks:   " << obj.marks << endl;
		out << "\nAverage: " << obj.marks.get_avg();
	}
	else
	{
		out << "\nErr.";
	}
	out << "\nSubjects:" << obj.subjects << endl;

	return out;
}

ofstream& operator<<(ofstream& f_out,const StudentAgr& obj)
{
	if (!f_out.is_open()) return f_out;

	f_out << obj.surname << obj.name;
	f_out.write((char*)&obj.age, sizeof(obj.age));
	f_out << obj.vuz << obj.marks << obj.subjects;

	return f_out;
}

ifstream& operator>>(ifstream& f_in, StudentAgr& obj)
{
	if (!f_in.is_open()) return f_in;

	f_in >> obj.surname >> obj.name;
	f_in.read((char*)&obj.age, sizeof(obj.age));
	f_in >> obj.vuz >> obj.marks >> obj.subjects;

	return f_in;
}
