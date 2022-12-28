#include "Entrepreneur.h"
#include "Date.h"

Entrepreneur Entrepreneur::operator=(const Entrepreneur& other) {
	*((Human*)this) = (Human&)other;
	this->license = other.license;
	strcpy_s(this->addresLicense.country, 10, other.addresLicense.country);
	strcpy_s(this->addresLicense.street, 10, other.addresLicense.street);
	this->addresLicense.home = other.addresLicense.home;
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = other.taxes[i];
	return *this;
}

void Entrepreneur::setLicense(int license) {
	this->license = license;
}

void Entrepreneur::setAddres(const char* country,const char* street,const int home) {
	strcpy_s(this->addresLicense.country, 10, country);
	strcpy_s(this->addresLicense.street, 10, street);
	this->addresLicense.home = home;
}

void Entrepreneur::setTaxes(tax taxes[]) {
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = taxes[i];
}

int Entrepreneur::getLicense() {
	return license;
}

addres Entrepreneur::getAddres() {
	return addresLicense;
}

tax* Entrepreneur::getTaxes() {
	return taxes;
}

void Entrepreneur::addTax(Date date, int summa) {
	for (int i = count_ms-1; i > 0; i--) {
		this->taxes[i] = this->taxes[i-1];
	}
	this->taxes[0].data = date;
	this->taxes[0].summa = summa;
}

void Entrepreneur::head() {
	cout.setf(ios::left);
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(15) << "Дата рождения" << setw(20) << "Адрес лицензии"
		<< setw(17) << "Номер лицензии" <<"Выплаты налогов" << endl;
	cout << setw(113) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
}

ostream& operator<<(ostream& out, Entrepreneur& other)
{
	out << (Human&)other;

	out.setf(ios::left);
	out << setw(5) << "" << other.addresLicense.country<<","<<other.addresLicense.street<<","<<setw(5) << other.addresLicense.home << setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;;
			continue;
		}
		out << setw(97) << "" << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;
	}
	out.unsetf(ios::left);
	return out;
}

istream& operator>>(istream& in, Entrepreneur& other) {
	in >> (Human&)other;
	in >> other.addresLicense.country >> other.addresLicense.street >> other.addresLicense.home;
	in >> other.license;
	return in;
}