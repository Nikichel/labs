#include "funs.h"

my_string operator+(const char* str, const my_string& other)			//char*+obj
{
	my_string summ;
	summ.len = other.len + strlen(str);
	summ.str = new char[summ.len + 1];			//��������� ������
	strcpy_s(summ.str, strlen(str)+1, str);			//����������� char*
	strcat_s(summ.str, other.len + 1, other.str);			//�������� other

	return summ;
};

istream& operator>>(istream& in, my_string& other) {			//���������� cin
	rewind(stdin);
	if (other.str) {
		delete[] other.str;
		other.len = 0;		//�������� ������� ������
	}		
	char* str = new char[MAX_LEN];			//�������� ��� ������
	in.getline(str, MAX_LEN);			//���� ������
	other.len = strlen(str);
	other.str = new char[other.len + 1];			//��������� ������
	strcpy_s(other.str, other.len + 1, str);			//����������� ������ � obj
	delete[] str;			

	return in;
}

ostream& operator<<(ostream& out, my_string& other) {		//���������� cout
	out << other.str;			//����� ������
	return out;
}