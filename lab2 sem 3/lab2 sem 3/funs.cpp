#include "funs.h"

my_string operator+(const char* str, const my_string& other)			//char*+obj
{
	my_string summ;
	summ.len = other.len + strlen(str);
	summ.str = new char[summ.len + 1];			//выделение памяти
	strcpy_s(summ.str, strlen(str)+1, str);			//копирование char*
	strcat_s(summ.str, other.len + 1, other.str);			//дозапись other

	return summ;
};

istream& operator>>(istream& in, my_string& other) {			//перегрузка cin
	rewind(stdin);
	if (other.str) {
		delete[] other.str;
		other.len = 0;		//удаление стараой строки
	}		
	char* str = new char[MAX_LEN];			//выделени под строку
	in.getline(str, MAX_LEN);			//ввод строки
	other.len = strlen(str);
	other.str = new char[other.len + 1];			//выделение памяти
	strcpy_s(other.str, other.len + 1, str);			//копирование строки в obj
	delete[] str;			

	return in;
}

ostream& operator<<(ostream& out, my_string& other) {		//перегрузка cout
	out << other.str;			//вывод строки
	return out;
}