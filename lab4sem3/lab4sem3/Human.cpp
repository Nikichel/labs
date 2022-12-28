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
	if(strlen(other.name))
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
			<< "4. Выйти"<<endl;
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
			fl = false;
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
	cout << "Фамилия: ";
	in.getline(other.surname, 15);
	rewind(stdin);
	cout << "Имя: ";
	in.getline(other.name, 15);
	rewind(stdin);
	cout << "Отчество: ";
	in.getline(other.midname, 15);
	rewind(stdin);
	cout << "Введите дату рождения (dd mm yyyy): ";
	in >> other.date;										//ввод данных
	return in;
}