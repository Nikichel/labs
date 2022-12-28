#include "Entrepreneur.h"
#include "Date.h"

Entrepreneur Entrepreneur::operator=(const Entrepreneur& other) {			//�������� =
	*((Human*)this) = (Human&)other;			//����������� ����� Human
	this->license = other.license;
	strcpy_s(this->addresLicense.city, 10, other.addresLicense.city);
	strcpy_s(this->addresLicense.street, 10, other.addresLicense.street);
	this->addresLicense.home = other.addresLicense.home;
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = other.taxes[i];		//����������� ����� Entrepreneur
	return *this;
}

void Entrepreneur::setLicense(int license) {			//���������� ����� ��������
	this->license = license;
}

void Entrepreneur::setAddres(const char* city, const char* street, const int home) {		//��������� ������ ��������
	strcpy_s(this->addresLicense.city, 10, city);
	strcpy_s(this->addresLicense.street, 10, street);
	this->addresLicense.home = home;					//���������
}

void Entrepreneur::setTaxes(tax taxes[]) {			//��������� ������ �������
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = taxes[i];
}

int Entrepreneur::getLicense() {			//��������� ��������
	return license;
}

addres Entrepreneur::getAddres() {			//��������� ������ ��������
	return addresLicense;
}

tax* Entrepreneur::getTaxes() {				//��������� �������
	return taxes;
}

void Entrepreneur::addTax(Date date, int summa) {			//�������� �����
	for (int i = count_ms - 1; i > 0; i--) {
		this->taxes[i] = this->taxes[i - 1];				//�������� ������� ����
	}
	this->taxes[0].data = date;
	this->taxes[0].summa = summa;			//1 ������� - ����� �����
}

void Entrepreneur::change() {			//����� ������
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl
			<< "4. ����� ��������" << endl << "5. �������� ������� ������" << endl << "6. �����" << endl;
		exc.getNum(var);			//�������
		cout << "��������� ��� �� ����������! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "������� ���" << endl;
			exc.getEngStr(name, 15);			//���
			break;
		}
		case 2: {
			cout << "������� �������" << endl;
			exc.getEngStr(surname, 15);			//�������
			break;
		}
		case 3: {
			cout << "������� ��������" << endl;
			exc.getEngStr(midname, 15);			//��������
			break;
		}
		case 4: {
			cout << "������� ��������" << endl;
			exc.getPositivNum(license);				//��������
			break;
		}
		case 5: {
			int summ;
			cout << "�����: ";
			exc.getPositivNum(summ);
			cout << "���� �����������" << endl;
			Date pay;
			cin >> pay;
			addTax(pay, summ);
			break;
		}
		case 6: {
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

void Entrepreneur::filter() {		//������ ������
	int var;
	while (1) {
		cout << "����� ��:" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl << "4. ����"
			<< endl << "5. ��������" << endl << "6. ����� �� �������" << endl;				//����� ���������
		exc.getNum(var);
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
			cout << "������� ��������" << endl;
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
			cout << "������� ����" << endl;
			cin >> this->date;
			break;
		}
		case 5: {
			cout << "������� ��������" << endl;			//���� �������
			exc.getPositivNum(license);
			break;
		}
		case 6: {
			return;
		}
		default: {
			cout << "������ ���" << endl;
			break;
		}
		}
	}
}

bool Entrepreneur::operator==(Entrepreneur& other) {			//�������� ���������
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//���� �� �������� ����., �� ������ => false
	if (other.license)
		if (this->license != other.license) return false;

	return true;
}

void Entrepreneur::head() {			//����� ����� �������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);		//������������ �� ������ ����
	cout << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(17) << "���� ��������" << setw(23) << "����� ��������"
		<< setw(17) << "����� ��������" << "������� �������" << endl;			//����� �������� ����� ����� 
	cout << setw(119) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Entrepreneur& other)			//����� ���������� ������ Entrepreneur �� �����
{
	out << dynamic_cast<Human&>(other);			//����� ���������� Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);			//������������ �� ������ ����
	out << setw(7) << "" << setw(8) << other.addresLicense.city << setw(10) << other.addresLicense.street << setw(5) << other.addresLicense.home << setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;;
			continue;
		}
		out << setw(102) << "" << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;			//����� ����� Entrepreneur
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Entrepreneur& other) {					//����
	in >> dynamic_cast<Human&>(other);
	cout << "����� �����������" << endl << "�����: ";
	rewind(stdin);
	other.exc.getRuStr(other.addresLicense.city, 10);
	cout << "�����: ";
	rewind(stdin);
	other.exc.getRuStr(other.addresLicense.street, 10);
	cout << "���: ";
	other.exc.getPositivNum(other.addresLicense.home);
	cout << "����� ��������: ";
	other.exc.getPositivNum(other.license);							//���� � �������� ������ ������
	return in;
}

ifstream& operator>>(ifstream& in, Entrepreneur& other) {
	in >> dynamic_cast<Human&>(other);			//����� ���������� Human
	in.setf(ios::left);			//������������ �� ������ ����
	in >> setw(8) >> other.addresLicense.city >> setw(10) >> other.addresLicense.street >> setw(5) >> other.addresLicense.home >> setw(17) >> other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			in >> other.taxes[i].data >> setw(3) >> other.taxes[i].summa;
			continue;
		}
		in  >> other.taxes[i].data >> setw(3) >> other.taxes[i].summa;			//����� ����� Entrepreneur
	}
	in.unsetf(ios::left);
	return in;
};

ofstream& operator<<(ofstream& out, Entrepreneur& other) {
	out << dynamic_cast<Human&>(other);			//����� ���������� Human
	out.setf(ios::left);			//������������ �� ������ ����
	out << setw(7) << "" << setw(8) << other.addresLicense.city << setw(10) << other.addresLicense.street << setw(5) << other.addresLicense.home << setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;
			continue;
		}
		out << setw(102) << "" << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;			//����� ����� Entrepreneur
	}
	out.unsetf(ios::left);
	return out;
};