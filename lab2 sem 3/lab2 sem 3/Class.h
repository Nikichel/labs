#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class my_string {
	char* str;
	int len;
public:
	my_string() {		//конструктор по умолчанию
		len = 0;
		str = nullptr;
	}

	my_string(const char* str) {		//конструктор с параметрами
		len = strlen(str);
		this->str = new char[len + 1];			//выделение памяти
		strcpy_s(this->str, len + 1, str);			//копирование строки
	}

	my_string(const my_string& other) {				//конструктор копирования
		this->len = other.len;
		this->str = new char[this->len + 1];			//выделение памяти
		strcpy_s(this->str, this->len + 1, other.str);			//копирование
	}

	~my_string() {			//деструктор
		delete[] str;
	}

	my_string(my_string&& other) noexcept		//конструктор перемещения 
		: str(nullptr),
		len(0)				//определение пустого метода
	{
		str = other.str;
		len = other.len;			//присвоение значений
		other.str = nullptr;
		other.len = 0;			//присвоение значений по умолчанию
	}

	int size();				//длина строки

	my_string operator()(int start);			//подстрока с указанной позиции до конца
	my_string operator()(int start, int end);			//подстрока между позициями

	my_string operator= (const my_string& other);			//obj=obj
	my_string operator= (const char* str);			//obj=char*

	bool operator== (const my_string& other);			//obj==obj
	bool operator!=(const my_string& other);			//obj!=obj

	bool operator==(const char* str);				//obj==char*
	bool operator!=(const char* str);				//obj!=char*

	char& operator[](int poz);			//перегрузка []

	my_string operator+(const my_string& other);					//obj+obj	
	my_string operator+(const char* str);							//obj+char*
	friend my_string operator+(const char*, const my_string&);		//char*+obj

	void operator+=(const my_string& other);		//obj+=obj
	void operator+=(const char* other);				//obj+=char*

	friend istream& operator>>(istream&, my_string&);			//перегрузка cin
	friend ostream& operator<<(ostream&, my_string&);			//перегрузка cout
};