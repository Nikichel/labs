#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class Date {
	int dd, mm, yyyy;
public:
	Date() {			//�� ���������
		dd = mm = yyyy = 0;
	}

	Date(int day, int month, int year) {			//����������� � �����������
		dd = day;
		mm = month;
		yyyy = year;
	}

	Date(Date& other) {				//�����������
		this->dd = other.dd;
		this->mm = other.mm;
		this->yyyy = other.yyyy;
	}

	~Date() {}				//����������

	Date operator= (const Date& other);		//�������� = (date)
	Date operator= (const int ms[]);		//�������� = (int*)

	bool isNull();				//�������� �� ������ ����
	bool operator==(const Date& other);				//�������� ==

	void setDay(int dd);		
	void setMonth(int mm);
	void setYear(int yyyy);				//����������� ���/������/����

	int getDay();
	int getMonth();
	int getYear();			//�������� ����, �����, ���
		
	friend ostream& operator<<(ostream&, Date&);			//�����
	friend istream& operator>>(istream&, Date&);			//�����
};