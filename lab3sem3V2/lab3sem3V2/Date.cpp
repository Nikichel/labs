#include "Date.h"

Date Date::operator=(const Date& other) {
	this->dd = other.dd;
	this->mm = other.mm;
	this->yyyy = other.yyyy;
	return *this;
}

Date Date::operator=(const int ms[]) {
	dd = ms[0];
	mm = ms[1];
	yyyy = ms[2];
	return *this;
}

void Date::setDay(int dd) {
	this->dd = dd;
}
void Date::setMonth(int mm) {
	this->mm = mm;
}

void Date::setYear(int yyyy) {
	this->yyyy = yyyy;
}

int Date::getDay() {
	return this->dd;
}

int Date::getMonth() {
	return this->mm;
}

int Date::getYear() {
	return this->yyyy;
}

ostream& operator<<(ostream& out, Date& other) {
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << "." << setfill('0') << setw(2) << other.mm << setfill(' ') << "." << setfill('0') << setw(4) << other.yyyy << setfill(' ');
	out.setf(ios::left);
	return out;
}

istream& operator>>(istream& in, Date& other) {
	in >> other.dd >> other.mm >> other.yyyy;
	return in;
}