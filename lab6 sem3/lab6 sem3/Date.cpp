#include "Date.h"

Date Date::operator=(const Date& other) {		//�������� =(date)
	this->dd = other.dd;
	this->mm = other.mm;
	this->yyyy = other.yyyy;			//����������� ������
	return *this;
}

Date Date::operator=(const int ms[]) {			//��������= (int*)
	dd = ms[0];
	mm = ms[1];
	yyyy = ms[2];			//������������ ������
	return *this;
}

void Date::setDay(int dd) {			//���������� ����
	this->dd = dd;
}
void Date::setMonth(int mm) {		//���������� �����
	this->mm = mm;
}

void Date::setYear(int yyyy) {		//���������� ���
	this->yyyy = yyyy;
}

int Date::getDay() {		//�������� ����
	return this->dd;
}

int Date::getMonth() {		//�������� �����
	return this->mm;
}

int Date::getYear() {		//�������� ���
	return this->yyyy;
}

bool Date::isNull() {		//�������� �� ����
	if (dd == 0 && mm == 0 && yyyy == 0)	//���� ����	
		return true;
	return false;
};
bool Date::operator==(const Date& other) {			//�������� ==
	if (other.dd)
		if (dd != other.dd) return false;
	if (other.mm)
		if (mm != other.mm) return false;
	if (other.dd)
		if (yyyy != other.yyyy) return false;

	return true;
	
};

ostream& operator<<(ostream& out, Date& other) {			//�����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);			//���� ������� � ������
	out.unsetf(ios::left);
	out << setfill('0') << setw(2) << other.dd << " " << setfill('0') << setw(2) << other.mm << setfill(' ') << " " << setfill('0') << setw(4) << other.yyyy << setfill(' ');
	out.setf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Date& other) {			//����
	other.exc.getDate(other.dd, other.mm, other.yyyy);
	return in;
}

ifstream& operator>>(ifstream& in, Date& other) {
	in.unsetf(ios::left);
	in >> setw(2) >> other.dd  >> setw(2) >> other.mm >> setw(4) >> other.yyyy;
	in.setf(ios::left);
	return in;
};