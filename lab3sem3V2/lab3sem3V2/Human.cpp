#include "Human.h"

void Human::setDate(int day, int month, int year) {
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
};

void Human::setName(const char* name) {
	strcpy_s(this->name, 15, name);
};

void Human::setSurname(const char* surname) {
	strcpy_s(this->surname, 15, surname);
};

void Human::setMidname(const char* midname) {
	strcpy_s(this->midname, 15, midname);
};

char* Human::getName() {
	return this->name;
};

char* Human::getSurname() {
	return this->surname;
};

char* Human::getMidname() {
	return this->midname;
};

Date Human::getDate() {
	return this->date;
};

Human Human::operator=(const Human& other) {
	this->date = other.date;
	strcpy_s(this->name, 15, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);
	return *this;
}

void Human::head() {
	cout.setf(ios::left);
	cout << setw(15) <<"Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << "Дата рождения"<<endl;
	cout.unsetf(ios::left);
}

ostream& operator<<(ostream& out, Human& other) {
	out.setf(ios::left);
	out << setw(15) << other.surname << setw(15) << other.name << setw(15) << other.midname << other.date;
	out.unsetf(ios::left);
	return out;
}

istream& operator>>(istream& in, Human& other) {
	in >> other.surname >> other.name >> other.midname;
	in >> other.date;
	return in;
}