#include "Class.h"

int my_string::size() {			//����� ������
	return len;
}

my_string my_string::operator()(int start) {		//��������� � ��������� ������� �� �����	
	my_string substr;
	substr.len = this->len - start;			
	substr.str = new char[this->len - start + 1];		//��������� ������
	int i = start;
	int j = 0;
	while (*(this->str + i) != '\0') {				//������ ���������
		*(substr.str + j) = *(this->str + i);
		i++; j++;
	}
	*(substr.str + j) = '\0';			//����� ������
	return substr;
}

my_string my_string::operator()(int start, int end) {			//��������� � ��������� ������� �� �������� �������
	if (end < start) {			//end ������ ��� start
		int tmp = end;
		end = start;
		start = tmp;
	}
	my_string substr;
	substr.len = end-start;
	substr.str = new char[substr.len + 1];			//��������� ������
	int i = start;
	int j = 0;
	while (*(this->str + i) != '\0' && i<end) {			//������ ���������
		*(substr.str + j) = *(this->str + i);
		i++; j++;
	}
	*(substr.str + j) = '\0';			//����� ������
	substr.len = j;			//����� ������
	return substr;
}

my_string my_string::operator= (const my_string& other) {			//obj=obj
	this->len = other.len;
	this->str = new char[this->len + 1];			//�������� ������
	strcpy_s(this->str, len + 1, other.str);		//����������� ������	
	return *this;
}

my_string my_string::operator= (const char* str) {
	this->len = strlen(str);
	this->str = new char[this->len + 1];			//�������� ������
	strcpy_s(this->str, len + 1, str);		//����������� ������
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

char& my_string::operator[](int poz) {				//���������� []
	return str[poz];
}

my_string my_string::operator+(const my_string& other) {			//obj+obj
	my_string summ;
	summ.len = this->len + other.len;
	summ.str = new char[summ.len + 1];			//�������� ������
	strcpy_s(summ.str, this->len + 1, this->str);			//����������� this
	strcat_s(summ.str, summ.len+1, other.str);				//������ other
	return summ;
}

my_string my_string::operator+(const char* str) {			//obj+char*
	my_string summ;
	summ.len = this->len + strlen(str);
	summ.str = new char[summ.len + 1];			//��������� ������
	strcpy_s(summ.str, this->len + 1, this->str);		//����������� this
	strcat_s(summ.str, summ.len + 1, str);				//������ str
	return summ;	
}

void my_string::operator+=(const my_string& other) {			//obj+=obj
	*this = *this + other;
}

void my_string::operator+=(const char* other) {			//obj+=char*
	*this = *this + other;
}
