#include "Tourist.h"

Tourist Tourist::operator=(Tourist& other) {			//�������� =
	*(dynamic_cast<Human*>(this))= dynamic_cast<Human&>(other);
	this->num_passport = other.num_passport;
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = other.broad_cross[i];			//����������� ����� Tourist
	return *this;
}

void Tourist::setNumPassport(int numPassport) {		//��������� ������ ��������
	this->num_passport = numPassport;
};

void Tourist::setBroadCross(cross broadCross[]) {			//��������� ����������� ������
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = broadCross[i];
};

int Tourist::getNumPassport() {				//��������� ������ ��������
	return num_passport;
};

cross* Tourist::getBroadCross() {			//��������� ���������� � ������������ �������
	return broad_cross;
}

void Tourist::addBroadCross(const char* country, Date date) {			//�������� ����������� �������
	for (int i = count_ms - 1; i > 0; i--) {
		this->broad_cross[i] = this->broad_cross[i - 1];				//�������� ����
	}
	strcpy_s(this->broad_cross[0].country, 10, country);
	this->broad_cross[0].data = date;							//1 ������� - ����� �����������
}

void Tourist::change() {			//���� ����� ������
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl
			<< "4. �������" <<endl<<"5. �������� ����������� �������"<<endl<<"6. �����"<<endl;
		exc.getNum(var);			//����� ��������
		cout << "��������� ��� �� ����������! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			exc.getEngStr( name, 15);
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			exc.getEngStr(surname, 15);
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			exc.getEngStr( midname, 15);
			break;
		}
		case 4: {
			cout << "������� ����� ��������" << endl;
			exc.getPositivNum(num_passport);			//��������� ������
			break;
		}
		case 5: {
			char country[10];
			cout << "������: ";
			exc.getRuStr(country, 10);
			cout << "���� �����������" << endl;
			Date cross;
			cin >> cross;
			addBroadCross(country, cross);
			break;
		}
		case 6: {
			fl = false;
			break;
		}
		default: {
			cout << "��� ������ ������" << endl;
			break;
		}
		}
	}
}

void Tourist::filter() {		//������ ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl << "4. ����"
			<< endl << "5. �������" << endl << "6. ����� �� �������" << endl;				//����� ���������
		exc.getNum(var);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			exc.getEngStr( this->name, 15);
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			exc.getEngStr( this->surname, 15);
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			exc.getEngStr( this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ����" << endl;
			cin >> this->date;
			break;
		}
		case 5: {
			cout << "������� ����� ��������" << endl;
			exc.getPositivNum(num_passport);
			break;
		}
		case 6: {
			return;
		}
		default: {
			cout << "��� ������ ������" << endl;
			break;
		}
		}
	}
}

bool Tourist::operator==(Tourist& other) {			//�������� ���������
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//���� �� �������� ����., �� ������ => false
	if(other.num_passport)
		if (num_passport != other.num_passport) return false;			//���� �� �������� ����., �� ������ => false

	return true;
}

void Tourist::head() {				//����� Tourist
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);			//������������ �� ������ ����
	cout << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "���� ��������" << setw(17) << "����� ��������"
		<< "����������� ������" << endl;						//����� �������� ����� Tourist
	cout << setw(96) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Tourist& other) {				//����� ������ Tourist
	out << dynamic_cast<Human&>(other);			//����� ����� Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);			//������������ �� ������ ����
	out << setw(5) << "" << setw(17) << other.num_passport;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;
			continue;
		}
		out << setw(77) << "" << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;			//����� ����� Tourist
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}
 
istream& operator>>(istream& in, Tourist& other) {		//����
	in >> dynamic_cast<Human&>(other);
	cout << "����� ��������: ";
	other.exc.getPositivNum(other.num_passport);			//���� � �������� ������ ��������
	return in;
}