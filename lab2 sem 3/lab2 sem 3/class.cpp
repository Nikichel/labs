#include "Class.h"

int my_string::size() {			//длина строки
	return len;
}

my_string my_string::operator()(int start) {		//подстрока с указанной позиции до конца	
	my_string substr;
	substr.len = this->len - start;			
	substr.str = new char[this->len - start + 1];		//выделение памяти
	int i = start;
	int j = 0;
	while (*(this->str + i) != '\0') {				//запись подстроки
		*(substr.str + j) = *(this->str + i);
		i++; j++;
	}
	*(substr.str + j) = '\0';			//конец строки
	return substr;
}

my_string my_string::operator()(int start, int end) {			//подстрока с указанной позиции до указаной позиции
	if (end < start) {			//end раньше чем start
		int tmp = end;
		end = start;
		start = tmp;
	}
	my_string substr;
	substr.len = end-start;
	substr.str = new char[substr.len + 1];			//выделение памяти
	int i = start;
	int j = 0;
	while (*(this->str + i) != '\0' && i<end) {			//запись подстроки
		*(substr.str + j) = *(this->str + i);
		i++; j++;
	}
	*(substr.str + j) = '\0';			//конец строки
	substr.len = j;			//длина строки
	return substr;
}

my_string my_string::operator= (const my_string& other) {			//obj=obj
	this->len = other.len;
	this->str = new char[this->len + 1];			//выделени памяти
	strcpy_s(this->str, len + 1, other.str);		//копирование строки	
	return *this;
}

my_string my_string::operator= (const char* str) {
	this->len = strlen(str);
	this->str = new char[this->len + 1];			//выделени памяти
	strcpy_s(this->str, len + 1, str);		//копирование строки
	return *this;
}

bool my_string::operator== (const my_string& other) {			//obj==obj
	return !(strcmp(this->str, other.str));
}

bool my_string::operator!=(const my_string& other) {			//obj!=obj
	return !(*this == other);
}

bool my_string::operator==(const char* str) {			//obj==char*
	return !(strcmp(this->str, str));
}

bool my_string::operator!=(const char* str) {			//obj!=char*
	return !(*this == str);
}

char& my_string::operator[](int poz) {				//перегрузка []
	return str[poz];
}

my_string my_string::operator+(const my_string& other) {			//obj+obj
	my_string summ;
	summ.len = this->len + other.len;
	summ.str = new char[summ.len + 1];			//выдление памяти
	strcpy_s(summ.str, this->len + 1, this->str);			//копирование this
	strcat_s(summ.str, summ.len+1, other.str);				//запись other
	return summ;
}

my_string my_string::operator+(const char* str) {			//obj+char*
	my_string summ;
	summ.len = this->len + strlen(str);
	summ.str = new char[summ.len + 1];			//выделение памяти
	strcpy_s(summ.str, this->len + 1, this->str);		//копирование this
	strcat_s(summ.str, summ.len + 1, str);				//запись str
	return summ;	
}

void my_string::operator+=(const my_string& other) {			//obj+=obj
	*this = *this + other;
}

void my_string::operator+=(const char* other) {			//obj+=char*
	*this = *this + other;
}
