#include "Business.h"

Business Business::operator=(const Business& other) {		//опертор =
	*((Tourist*)this) = (Tourist&)other;		//копирование полей Tourist
	*((Entrepreneur*)this) = (Entrepreneur&)other;		//копирование Entrepreneur
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 20, other.product[i]);		//копирование списка продуктов
	return *this;
}

char** Business::getProducts() {		//получение список продуктов
	return (char**)product;
}
void Business::setProducts(char** products) {		//установка списка продуктов
	for (int i = 0; i < count_ms; i++)
		strcpy_s(this->product[i], 20, products[i]);
}

void Business::addProduct(const char* product) {			//добавить продукт
	for (int i = count_ms - 1; i > 0; i--) {
		strcpy_s(this->product[i], 20, this->product[i - 1]);			//смещение продуктов вниз
	}
	strcpy_s(this->product[0], 20, product);		//1 элемент - новый продукт
}

bool Business::operator==(Business& other) {
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//если не нуллевые знач., но разные => false
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
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<<"4. Паспорт" <<endl<<"5. Номер лицензии" << "6. Выйти"<<endl;
		cin >> var;
		cout << "Введите новую информацию" << endl;
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

void Business::head() {			//вывод шапки таблицы
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);			//выравнивание по левому краю
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(15) << "Дата рождения" << setw(17) << "Номер паспорта"
		<< setw(25) << "Адрес лицензии" << setw(17) << "Номер лицензии"
		<< setw(22) << "Выплаты налогов" << setw(25) << "Пересечение границ" << "Товары" << endl;
	cout << setw(172) << setfill('-') << "" << endl;			//заполнение '_'
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Business& other) {			//вывод класса на экран
	out << dynamic_cast<Human&>(other);		//вывод полей Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);		//выравнивание по левому краю
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
		out << other.product[i] << endl;																	//вывод полей Business
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Business& other) {
	in >> dynamic_cast<Human&>(other);
	cout << "Номер паспорта: ";
	in >> other.num_passport;
	cout << "Адрес регистрации"<<endl<<"Город: ";
	rewind(stdin);
	in.getline(other.addresLicense.city, 10);
	cout << "Улица: ";
	rewind(stdin);
	in.getline(other.addresLicense.street, 10);
	cout << "Дом: ";
	in>> other.addresLicense.home;
	cout << "Номер лицензии: ";
	in >> other.license;
	return in;
}