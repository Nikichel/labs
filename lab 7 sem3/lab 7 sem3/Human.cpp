#include "Human.h"

void Human::setDate(int day, int month, int year) {			//установить дату
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
};

void Human::setName(const char* name) {				//установить имя
	strcpy_s(this->name, 15, name);
};

void Human::setSurname(const char* surname) {			//установить фамилию
	strcpy_s(this->surname, 15, surname);
};

void Human::setMidname(const char* midname) {			//установить отчество
	strcpy_s(this->midname, 15, midname);
};

char* Human::getName() {				//получить имя
	return this->name;
};

char* Human::getSurname() {				//получить фамилия
	return this->surname;
};

char* Human::getMidname() {				//получить отчество
	return this->midname;
};

Date Human::getDate() {					//получить дату
	return this->date;
};

Human Human::operator=(const Human& other) {			//оператор =
	this->date = other.date;
	strcpy_s(this->name, 15, other.name);
	strcpy_s(this->surname, 15, other.surname);
	strcpy_s(this->midname, 15, other.midname);					//присваивание данных
	return *this;
}

bool Human::operator==(Human& other) {					//оператор ==
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//если не нуллевые знач., но разные => false

	return true;
}

void Human::change() {
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<< "4. Выйти" << endl;
		exc.getNum(var);			//выбор варианта
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
			cout << "Введите отччество" << endl;			//измеение полей
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
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

void Human::filter() {
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl << "4. Дату"
			<< endl << "5. Выйти из фильтра" << endl;				//выбор параметра
		exc.getNum(var);
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
			cout << "Введите отччество" << endl;
			exc.getEngStr(this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите дату" << endl;			//ввод полей в фильтр
			cin >> this->date;
			break;
		}
		case 5: {
			return;
		}
		default: {
			cout << "Пункта нет" << endl;
			break;
		}
		}
	}
}

void Human::head() {				//шапка
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << "Дата рождения" << endl;
	cout << setw(58) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Human& other) {			//вывод
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);				//изменить цвет
	out.setf(ios::left);
	out << setw(15) << other.surname << setw(15) << other.name << setw(15) << other.midname << other.date;			//вывод полей
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}

istream& operator>>(istream& in, Human& other) {			//ввод
	rewind(stdin);
	cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
	cout << "Фамилия: ";
	other.exc.getEngStr(other.surname, 15);
	rewind(stdin);
	cout << "Имя: ";
	other.exc.getEngStr(other.name, 15);
	rewind(stdin);
	cout << "Отчество: ";
	other.exc.getEngStr(other.midname, 15);
	rewind(stdin);
	cout << "Введите дату рождения (dd mm yyyy): ";
	in >> other.date;										//ввод данных
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
	out << setw(15) << other.surname << setw(15) << other.name << setw(15) << other.midname << other.date;			//вывод полей
	out.unsetf(ios::left);
	return out;
};