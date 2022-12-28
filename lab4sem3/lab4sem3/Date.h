#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class Date {
	int dd, mm, yyyy;
public:
	Date() {			//по умолчанию
		dd = mm = yyyy = 0;
	}

	Date(int day, int month, int year) {			//конструктор с параметрами
		dd = day;
		mm = month;
		yyyy = year;
	}

	Date(Date& other) {				//копирования
		this->dd = other.dd;
		this->mm = other.mm;
		this->yyyy = other.yyyy;
	}

	~Date() {}				//деструктор

	Date operator= (const Date& other);		//оператор = (date)
	Date operator= (const int ms[]);		//оператор = (int*)

	bool isNull();				//проверка на пустую дату
	bool operator==(const Date& other);				//оператор ==

	void setDay(int dd);		
	void setMonth(int mm);
	void setYear(int yyyy);				//установщики дня/месяца/года

	int getDay();
	int getMonth();
	int getYear();			//получить день, месяц, год
		
	friend ostream& operator<<(ostream&, Date&);			//вывод
	friend istream& operator>>(istream&, Date&);			//вывод
};