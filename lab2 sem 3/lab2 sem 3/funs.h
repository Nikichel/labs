#pragma once
#include "Class.h"
#define MAX_LEN 80			//����. ����� ������
#define start_ind 1			//��a������ ������ ��� ���������
#define end_ind 4			//�������� ������ ��� ���������	

my_string operator+(const char* str, const my_string& my_str);		//char*+obj

istream& operator>>(istream&, my_string&);			//���������� cin
ostream& operator<<(ostream&, my_string&);			//���������� cout