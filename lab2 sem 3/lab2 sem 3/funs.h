#pragma once
#include "Class.h"
#define MAX_LEN 80			//макс. длина строки
#define start_ind 1			//стaртовый индекс для подстроки
#define end_ind 4			//конечный индекс для подстроки	

my_string operator+(const char* str, const my_string& my_str);		//char*+obj

istream& operator>>(istream&, my_string&);			//перегрузка cin
ostream& operator<<(ostream&, my_string&);			//перегрузка cout