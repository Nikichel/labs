#include "Entrepreneur.h"
#include "Date.h"

Entrepreneur Entrepreneur::operator=(const Entrepreneur& other) {			//оператор =
	*((Human*)this) = (Human&)other;			//копирование полей Human
	this->license = other.license;
	strcpy_s(this->addresLicense.city, 10, other.addresLicense.city);
	strcpy_s(this->addresLicense.street, 10, other.addresLicense.street);
	this->addresLicense.home = other.addresLicense.home;
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = other.taxes[i];		//копирование полей Entrepreneur
	return *this;
}

void Entrepreneur::setLicense(int license) {			//установить номер лицензии
	this->license = license;
}

void Entrepreneur::setAddres(const char* city, const char* street, const int home) {		//установка адреса лицензии
	strcpy_s(this->addresLicense.city, 10, city);
	strcpy_s(this->addresLicense.street, 10, street);
	this->addresLicense.home = home;					//установка
}

void Entrepreneur::setTaxes(tax taxes[]) {			//установка списка нологов
	for (int i = 0; i < count_ms; i++)
		this->taxes[i] = taxes[i];
}

int Entrepreneur::getLicense() {			//получение лицензии
	return license;
}

addres Entrepreneur::getAddres() {			//получение адреса лицензии
	return addresLicense;
}

tax* Entrepreneur::getTaxes() {				//получение налогов
	return taxes;
}

void Entrepreneur::addTax(Date date, int summa) {			//добавить налог
	for (int i = count_ms - 1; i > 0; i--) {
		this->taxes[i] = this->taxes[i - 1];				//смещение налогов вниз
	}
	this->taxes[0].data = date;
	this->taxes[0].summa = summa;			//1 элемент - новый налог
}

void Entrepreneur::change() {			//смена данных
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<< "4. Номер лицензии" << endl << "5. Добавить выплату налога" << endl << "6. Выйти" << endl;
		exc.getNum(var);			//вариант
		cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			exc.getEngStr(name, 15);			//имя
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			exc.getEngStr(surname, 15);			//фамилия
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			exc.getEngStr(midname, 15);			//отчество
			break;
		}
		case 4: {
			cout << "Введите лицензию" << endl;
			exc.getPositivNum(license);				//лицензия
			break;
		}
		case 5: {
			int summ;
			cout << "Сумма: ";
			exc.getPositivNum(summ);
			cout << "Дата пересечения" << endl;
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
			cout << "Пункта нет" << endl;
			break;
		}
		}
	}
}

void Entrepreneur::filter() {		//фильтр поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl << "4. Дату"
			<< endl << "5. Лицензию" << endl << "6. Выйти из фильтра" << endl;				//выбор параметра
		exc.getNum(var);
		cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			exc.getEngStr(this->name, 15);
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			exc.getEngStr(this->surname, 15);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите дату" << endl;
			cin >> this->date;
			break;
		}
		case 5: {
			cout << "Введите лицензию" << endl;			//ввод фильтра
			exc.getPositivNum(license);
			break;
		}
		case 6: {
			return;
		}
		default: {
			cout << "Пункта нет" << endl;
			break;
		}
		}
	}
}

bool Entrepreneur::operator==(Entrepreneur& other) {			//оператор сравнения
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//если не нуллевые знач., но разные => false
	if (other.license)
		if (this->license != other.license) return false;

	return true;
}

void Entrepreneur::head() {			//вывод шапки таблицы
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);		//выравнивание по левому краю
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(17) << "Дата рождения" << setw(23) << "Адрес лицензии"
		<< setw(17) << "Номер лицензии" << "Выплаты налогов" << endl;			//вывод названия полей полей 
	cout << setw(119) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Entrepreneur& other)			//вывод информации класса Entrepreneur на экран
{
	out << dynamic_cast<Human&>(other);			//вывод информации Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);			//выравнивание по леаому краю
	out << setw(7) << "" << setw(8) << other.addresLicense.city << setw(10) << other.addresLicense.street << setw(5) << other.addresLicense.home << setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;;
			continue;
		}
		out << setw(102) << "" << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;			//вывод полей Entrepreneur
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Entrepreneur& other) {					//ввод
	in >> dynamic_cast<Human&>(other);
	cout << "Адрес регистрации" << endl << "Город: ";
	rewind(stdin);
	other.exc.getRuStr(other.addresLicense.city, 10);
	cout << "Улица: ";
	rewind(stdin);
	other.exc.getRuStr(other.addresLicense.street, 10);
	cout << "Дом: ";
	other.exc.getPositivNum(other.addresLicense.home);
	cout << "Номер лицензии: ";
	other.exc.getPositivNum(other.license);							//ввод и проверка данных класса
	return in;
}

ifstream& operator>>(ifstream& in, Entrepreneur& other) {
	in >> dynamic_cast<Human&>(other);			//вывод информации Human
	in.setf(ios::left);			//выравнивание по леаому краю
	in >> setw(8) >> other.addresLicense.city >> setw(10) >> other.addresLicense.street >> setw(5) >> other.addresLicense.home >> setw(17) >> other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			in >> other.taxes[i].data >> setw(3) >> other.taxes[i].summa;
			continue;
		}
		in  >> other.taxes[i].data >> setw(3) >> other.taxes[i].summa;			//вывод полей Entrepreneur
	}
	in.unsetf(ios::left);
	return in;
};

ofstream& operator<<(ofstream& out, Entrepreneur& other) {
	out << dynamic_cast<Human&>(other);			//вывод информации Human
	out.setf(ios::left);			//выравнивание по леаому краю
	out << setw(7) << "" << setw(8) << other.addresLicense.city << setw(10) << other.addresLicense.street << setw(5) << other.addresLicense.home << setw(17) << other.license;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;
			continue;
		}
		out << setw(102) << "" << other.taxes[i].data << setw(3) << "" << other.taxes[i].summa << endl;			//вывод полей Entrepreneur
	}
	out.unsetf(ios::left);
	return out;
};