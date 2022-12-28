#include "Business.h"

Business Business::operator=(const Business& other) {		//������� =
	*((Tourist*)this) = (Tourist&)other;		//����������� ����� Tourist
	*((Entrepreneur*)this) = (Entrepreneur&)other;		//����������� Entrepreneur
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 20, other.product[i]);		//����������� ������ ���������
	return *this;
}

char** Business::getProducts() {		//��������� ������ ���������
	return (char**)product;
}
void Business::setProducts(char** products) {		//��������� ������ ���������
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 20, products[i]);
}

void Business::addProduct(const char* product) {			//�������� �������
	for (int i = count_ms - 1; i > 0; i--) {
		strcpy_s(this->product[i], 20, this->product[i - 1]);			//�������� ��������� ����
	}
	strcpy_s(this->product[0], 20, product);		//1 ������� - ����� �������
}

bool Business::operator==(Business& other) {
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//���� �� �������� ����., �� ������ => false
	if (other.num_passport)
		if (num_passport != other.num_passport) return false;
	if (other.license)
		if (license != other.license) return false;

	return true;
}

void Business::change() {
	int var;
	bool fl = true;
	while (fl) {
		cout << "�������" << endl << "1. ���" << endl << "2. �������" << endl << "3. ��������" << endl
			<<"4. �������" <<endl<<"5. ����� ��������" << "6. �����"<<endl;
		cin >> var;
		cout << "������� ����� ����������" << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cin.getline(this->name, 15);
			break;
		}
		case 2: {
			cin.getline(this->surname, 15);
			break;
		}
		case 3: {
			cin.getline(this->midname, 15);
			break;
		}
		case 4: {
			cin >> this->num_passport;
			break;
		}
		case 5: {
			cin >> this->license;
			break;
		}
		case 6: {
			fl = false;
		}
		}
	}
}

void Business::head() {			//����� ����� �������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);			//������������ �� ������ ����
	cout << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "���� ��������" << setw(17) << "����� ��������"
		<< setw(25) << "����� ��������" << setw(17) << "����� ��������"
		<< setw(22) << "������� �������" << setw(25) << "����������� ������" << "������" << endl;
	cout << setw(172) << setfill('-') << "" << endl;			//���������� '_'
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Business& other) {			//����� ������ �� �����
	out << dynamic_cast<Human&>(other);		//����� ����� Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);		//������������ �� ������ ����
	out << setw(5) << "" << setw(17) << other.num_passport
		<< setw(7) << other.addresLicense.city << setw(10) << other.addresLicense.street << setw(8) << other.addresLicense.home
		<< setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << setw(9) << other.taxes[i].summa;
			out << other.broad_cross[i].data << setw(3) << "" << setw(12) << other.broad_cross[i].country;
			out << other.product[i] << endl;
			continue;
		}
		out << setw(119) << "" << other.taxes[i].data << setw(3) << "" << setw(9) << other.taxes[i].summa;
		out << other.broad_cross[i].data << setw(3) << "" << setw(12) << other.broad_cross[i].country;
		out << other.product[i] << endl;																	//����� ����� Business
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Business& other) {
	in >> dynamic_cast<Human&>(other);
	cout << "����� ��������: ";
	in >> other.num_passport;
	cout << "����� �����������"<<endl<<"�����: ";
	rewind(stdin);
	in.getline(other.addresLicense.city, 10);
	cout << "�����: ";
	rewind(stdin);
	in.getline(other.addresLicense.street, 10);
	cout << "���: ";
	in>> other.addresLicense.home;
	cout << "����� ��������: ";
	in >> other.license;
	return in;
}