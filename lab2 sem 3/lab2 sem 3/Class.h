#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class my_string {
	char* str;
	int len;
public:
	my_string() {		//����������� �� ���������
		len = 0;
		str = nullptr;
	}

	my_string(const char* str) {		//����������� � �����������
		len = strlen(str);
		this->str = new char[len + 1];			//��������� ������
		strcpy_s(this->str, len + 1, str);			//����������� ������
	}

	my_string(const my_string& other) {				//����������� �����������
		this->len = other.len;
		this->str = new char[this->len + 1];			//��������� ������
		strcpy_s(this->str, this->len + 1, other.str);			//�����������
	}

	~my_string() {			//����������
		delete[] str;
	}

	my_string(my_string&& other) noexcept		//����������� ����������� 
		: str(nullptr),
		len(0)				//����������� ������� ������
	{
		str = other.str;
		len = other.len;			//���������� ��������
		other.str = nullptr;
		other.len = 0;			//���������� �������� �� ���������
	}

	int size();				//����� ������

	my_string operator()(int start);			//��������� � ��������� ������� �� �����
	my_string operator()(int start, int end);			//��������� ����� ���������

	my_string operator= (const my_string& other);			//obj=obj
	my_string operator= (const char* str);			//obj=char*

	bool operator== (const my_string& other);			//obj==obj
	bool operator!=(const my_string& other);			//obj!=obj

	bool operator==(const char* str);				//obj==char*
	bool operator!=(const char* str);				//obj!=char*

	char& operator[](int poz);			//���������� []

	my_string operator+(const my_string& other);					//obj+obj	
	my_string operator+(const char* str);							//obj+char*
	friend my_string operator+(const char*, const my_string&);		//char*+obj

	void operator+=(const my_string& other);		//obj+=obj
	void operator+=(const char* other);				//obj+=char*

	friend istream& operator>>(istream&, my_string&);			//���������� cin
	friend ostream& operator<<(ostream&, my_string&);			//���������� cout
};