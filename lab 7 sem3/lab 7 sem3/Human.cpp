#include "Human.h"

void Human::setDate(int day, int month, int year) {			//���������� ����
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
};

void Human::setName(const char* name) {				//���������� ���
	strcpy_s(this->name, 15, name);
};

void Human::setSurname(const char* surname) {			//���������� �������
	strcpy_s(this->surname, 15, surname);
};

void Human::setMidname(const char* midname) {			//���������� ��������
	strcpy_s(this->midname, 15, midname);
};

char* Human::getName() {				//�������� ���
	return this->name;
};

char* Human::getSurname() {				//�������� �������
	return this->surname;
};

char* Human::getMidname() {				//�������� ��������
	return this->midname;
};

Date Human::getDate() {					//�������� ����
	return this->date;
};

Human Human::operator=(const Human& other) {			//�������� =
	this->date = other.date;
	strcpy_s(this->name, 15, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);					//������������ ������
	return *this;
}

bool Human::operator==(Human& other) {					//�������� ==
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//���� �� �������� ����., �� ������ => false

	return true;
}

void Human::change() {
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl
			<< "4. �����" << endl;
		exc.getNum(var);			//����� ��������
		cout << "��������� ��� �� ����������! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			exc.getEngStr(this->name, 15);
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			exc.getEngStr(this->surname, 15);
			break;
		}
		case 3: {
			cout << "������� ���������" << endl;			//�������� �����
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
			fl = false;
			break;
		}
		default: {
			cout << "������ ���" << endl;
			break;
		}
		}
	}
}

void Human::filter() {
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl << "4. ����"
			<< endl << "5. ����� �� �������" << endl;				//����� ���������
		exc.getNum(var);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			exc.getEngStr(this->name, 15);
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			exc.getEngStr(this->surname, 15);
			break;
		}
		case 3: {
			cout << "������� ���������" << endl;
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ����" << endl;			//���� ����� � ������
			cin >> this->date;
			break;
		}
		case 5: {
			return;
		}
		default: {
			cout << "������ ���" << endl;
			break;
		}
		}
	}
}

void Human::head() {				//�����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);
	cout << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << "���� ��������" << endl;
	cout << setw(58) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Human& other) {			//�����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);				//�������� ����
	out.setf(ios::left);
	out << setw(15) << other.surname << setw(15) << other.name << setw(15) << other.midname << other.date;			//����� �����
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Human& other) {			//����
	rewind(stdin);
	cout << "��������� ��� �� ����������! " << endl;
	cout << "�������: ";
	other.exc.getEngStr(other.surname, 15);
	rewind(stdin);
	cout << "���: ";
	other.exc.getEngStr(other.name, 15);
	rewind(stdin);
	cout << "��������: ";
	other.exc.getEngStr(other.midname, 15);
	rewind(stdin);
	cout << "������� ���� �������� (dd mm yyyy): ";
	in >> other.date;										//���� ������
	return in;
}

ifstream& operator>>(ifstream& in , Human& other) {
	int dd, mm, yyyy;
	in.setf(ios::left);
	in >> setw(15) >> other.surname >> setw(15) >> other.name >> setw(15) >> other.midname
		>> setw(2) >> dd >>setw(2) >> mm >> setw(4) >> yyyy;
	other.date.setDay(dd);
	other.date.setMonth(mm);
	other.date.setYear(yyyy);
	return in;
}

ofstream& operator<<(ofstream& out, Human& other) {
	out.setf(ios::left);
	out << setw(15) << other.surname << setw(15) << other.name << setw(15) << other.midname << other.date;			//����� �����
	out.unsetf(ios::left);
	return out;
};