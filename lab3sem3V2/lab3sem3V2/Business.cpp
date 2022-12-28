#include "Business.h"

Business Business::operator=(const Business& other) {
	*((Tourist*)this) = (Tourist&)other;
	*((Entrepreneur*)this) = (Entrepreneur&)other;
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 10, other.product[i]);
	return *this;
}

char** Business::getProducts() {
	return (char**)product;
}
void Business::setProducts(char** products) {
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 10, products[i]);
}

void Business::addProduct(const char* product) {
	for (int i = count_ms-1; i > 0; i--) {
		strcpy_s(this->product[i], 10, this->product[i-1]);
	}
	strcpy_s(this->product[0], 10, product);
}

void Business::head() {
	cout.setf(ios::left);
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(15) << "Дата рождения"<< setw(17) << "Номер паспорта"
		<< setw(20) << "Адрес лицензии" << setw(17) << "Номер лицензии" 
		<<setw(22) << "Выплаты налогов" <<setw(25) << "Пересечение границ" <<"Товары" << endl;
	cout << setw(167) << setfill('-')<<""<<endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
}

ostream& operator<<(ostream& out, Business& other) {
	out << (Human&)other;
	out.setf(ios::left);
	out << setw(5) << "" << setw(17) << other.num_passport 
		<< other.addresLicense.country << "," << other.addresLicense.street << "," << setw(6) << other.addresLicense.home 
		<<setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << setw(9) << other.taxes[i].summa;
			out << other.broad_cross[i].data << setw(3) << "" << setw(12) << other.broad_cross[i].country;
			out << other.product[i] << endl;
			continue;
		}
		out << setw(115) << "" << other.taxes[i].data << setw(3) << "" << setw(9) << other.taxes[i].summa;
		out << other.broad_cross[i].data << setw(3) << "" << setw(12) << other.broad_cross[i].country;
		out << other.product[i] << endl;
	}
	out.unsetf(ios::left);
	return out;
}

istream& operator>>(istream& in, Business& other) {
	in >> (Human&)other;
	in >> other.num_passport;
	in >> other.addresLicense.country >> other.addresLicense.street >> other.addresLicense.home;
	in >> other.license;
	return in;
}