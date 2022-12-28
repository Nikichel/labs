#include "Tourist.h"

Tourist Tourist::operator=(const Tourist& other) {
	*((Human*)this) = (Human&)other;
	this->num_passport = other.num_passport;
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = other.broad_cross[i];
	return *this;
}

void Tourist::setNumPassport(int numPassport) {
	this->num_passport = numPassport;
};

void Tourist::setBroadCross(cross broadCross[]) {
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = broadCross[i];
};

int Tourist::getNumPassport() {
	return num_passport;
};

cross* Tourist::getBroadCross() {
	return broad_cross;
}

void Tourist::addBroadCross(const char* country, Date date) {
	for (int i = count_ms-1; i > 0; i--) {
		this->broad_cross[i] = this->broad_cross[i-1];
	}
	strcpy_s(this->broad_cross[0].country, 10, country);
	this->broad_cross[0].data = date;
}

void Tourist::head() {
	cout.setf(ios::left);
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(15)<< "Дата рождения" << setw(17) <<"Номер паспорта" 
		<<"Пересечение границ" << endl;
	cout << setw(96) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
}

ostream& operator<<(ostream& out, Tourist& other) {
	out << (Human&)other;
	out.setf(ios::left);
	out << setw(5) << "" << setw(17) << other.num_passport;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;
			continue;
		}
		out << setw(77) << "" << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;
	}
	out.unsetf(ios::left);
	return out;
}

istream& operator>>(istream& in, Tourist& other) {
	in >> (Human&)other;
	in >> other.num_passport;
	return in;
}