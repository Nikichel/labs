#pragma once
#include "Date.h"
#include <iostream>
#include <iomanip>

#define count_ms 3

class Human {
protected:
	Date date;
	char name[15];
	char surname[15];
	char midname[15];
public:
	Human() {
		/*cout << "Human" << endl;*/
		name[0] = '\0';
		surname[0] = '\0';
		midname[0] = '\0';
		date = { 0,0,0 };
	}

	Human(int day, int month, int year, const char* surname, const char* name, const char* midname) {
		//cout << "Human" << endl;
		this->date.setDay(day);
		this->date.setMonth(month);
		this->date.setYear(year);
		strcpy_s(this->name, 15, name);
		strcpy_s(this->surname, 15, surname);
		strcpy_s(this->midname, 15, midname);
	}

	Human(const Human& other) {
		//cout << "Human" << endl;
		strcpy_s(this->name, 15, other.name);
		strcpy_s(this->surname, 15, other.surname);
		strcpy_s(this->midname, 15, other.midname);
		this->date = other.date;
	}

	void setDate(int day, int month, int year);
	void setName(const char* name);
	void setSurname(const char* surname);
	void setMidname(const char* midname);
	char* getName();
	char* getSurname();
	char* getMidname();
	Date getDate();

	virtual void head();

	Human operator=(const Human& other);

	friend ostream& operator<<(ostream&, Human&);			//перегрузка cout
	friend istream& operator>>(istream&, Human&);
};