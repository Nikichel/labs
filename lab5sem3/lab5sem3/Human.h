#pragma once
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#define count_ms 3

class Human {
protected:
	Date date;		//дата рождения
	char name[15];
	char surname[15];
	char midname[15];		//фио
	checking exc;
public:
	Human() {				//по умолчанию
		/*cout << "Human" << endl;*/
		name[0] = '\0';
		surname[0] = '\0';
		midname[0] = '\0';
		date = { 0,0,0 };
	}

	Human(int day, int month, int year, const char* surname, const char* name, const char* midname) {			//с параметрами
		//cout << "Human" << endl;
		this->date.setDay(day);
		this->date.setMonth(month);
		this->date.setYear(year);
		strcpy_s(this->name, 15, name);
		strcpy_s(this->surname, 15, surname);
		strcpy_s(this->midname, 15, midname);
	}

	Human(const Human& other) {						//копирования
		//cout << "Human" << endl;
		strcpy_s(this->name, 15, other.name);
		strcpy_s(this->surname, 15, other.surname);
		strcpy_s(this->midname, 15, other.midname);
		this->date = other.date;
	}

	void setDate(int day, int month, int year);
	void setName(const char* name);
	void setSurname(const char* surname);
	void setMidname(const char* midname);			//установить дату, имя, фамилия, отчество 

	char* getName();
	char* getSurname();
	char* getMidname();
	Date getDate();						//получить имя, фамилию, отчество, дату

	virtual void head();			//шапка таблицы

	void change();		//изменить данные
	void filter();		//ввод  полей для поиска

	Human operator=(const Human& other);				//оператор =
	bool operator==(Human& other);			//оператор ==

	friend ostream& operator<<(ostream&, Human&);			//вывод
	friend istream& operator>>(istream&, Human&);			//ввод
};