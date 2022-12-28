#include "Tourist.h"

Tourist Tourist::operator=(Tourist& other) {			//оператор =
	*(dynamic_cast<Human*>(this))= dynamic_cast<Human&>(other);
	this->num_passport = other.num_passport;
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = other.broad_cross[i];			//копирование полей Tourist
	return *this;
}

void Tourist::setNumPassport(int numPassport) {		//установка номера паспорта
	this->num_passport = numPassport;
};

void Tourist::setBroadCross(cross broadCross[]) {			//установка пересечений границ
	for (int i = 0; i < count_ms; i++)
		this->broad_cross[i] = broadCross[i];
};

int Tourist::getNumPassport() {				//получение номера паспорта
	return num_passport;
};

cross* Tourist::getBroadCross() {			//получение информации о пересечениях границы
	return broad_cross;
}

void Tourist::addBroadCross(const char* country, Date date) {			//добавить пересечение границы
	for (int i = count_ms - 1; i > 0; i--) {
		this->broad_cross[i] = this->broad_cross[i - 1];				//смещение вниз
	}
	strcpy_s(this->broad_cross[0].country, 10, country);
	this->broad_cross[0].data = date;							//1 элемент - новое пересечение
}

void Tourist::change() {			//меню смены данных
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<< "4. Паспорт" <<endl<<"5. Добавить пересечение границы"<<endl<<"6. Выйти"<<endl;
		exc.getNum(var);			//выбор варианта
		cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			exc.getEngStr( name, 15);
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			exc.getEngStr(surname, 15);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			exc.getEngStr( midname, 15);
			break;
		}
		case 4: {
			cout << "Введите номер паспорта" << endl;
			exc.getPositivNum(num_passport);			//изменение данных
			break;
		}
		case 5: {
			char country[10];
			cout << "Страна: ";
			exc.getRuStr(country, 10);
			cout << "Дата пересечения" << endl;
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
			cout << "Нет такого пункта" << endl;
			break;
		}
		}
	}
}

void Tourist::filter() {		//фильтр поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl << "4. Дату"
			<< endl << "5. Паспорт" << endl << "6. Выйти из фильтра" << endl;				//выбор параметра
		exc.getNum(var);
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			exc.getEngStr( this->name, 15);
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			exc.getEngStr( this->surname, 15);
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			exc.getEngStr( this->midname, 15);
			break;
		}
		case 4: {
			cout << "Введите дату" << endl;
			cin >> this->date;
			break;
		}
		case 5: {
			cout << "Введите номер паспорта" << endl;
			exc.getPositivNum(num_passport);
			break;
		}
		case 6: {
			return;
		}
		default: {
			cout << "Нет такого пункта" << endl;
			break;
		}
		}
	}
}

bool Tourist::operator==(Tourist& other) {			//оператор сравнения
	if (strlen(other.name))
		if (strcmp(name, other.name)) return false;
	if (strlen(other.surname))
		if (strcmp(surname, other.surname)) return false;
	if (strlen(other.midname))
		if (strcmp(midname, other.midname)) return false;
	if (!(other.date.isNull()))
		if (!(date == other.date)) return false;				//если не нуллевые знач., но разные => false
	if(other.num_passport)
		if (num_passport != other.num_passport) return false;			//если не нуллевые знач., но разные => false

	return true;
}

void Tourist::head() {				//шапка Tourist
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 5);
	cout.setf(ios::left);			//выравнивание по левому краю
	cout << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << setw(15) << "Дата рождения" << setw(17) << "Номер паспорта"
		<< "Пересечение границ" << endl;						//вывод названия полей Tourist
	cout << setw(96) << setfill('-') << "" << endl;
	cout << setfill(' ');
	cout.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
}

ostream& operator<<(ostream& out, Tourist& other) {				//вывод класса Tourist
	out << dynamic_cast<Human&>(other);			//вывод полей Human
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 4);
	out.setf(ios::left);			//выравнивание по левому краю
	out << setw(5) << "" << setw(17) << other.num_passport;
	for (int i = 0; i < count_ms; i++) {
		if (i == 0) {
			out << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;
			continue;
		}
		out << setw(77) << "" << other.broad_cross[i].data << setw(3) << "" << other.broad_cross[i].country << endl;			//вывод полей Tourist
	}
	out.unsetf(ios::left);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	return out;
}
 
istream& operator>>(istream& in, Tourist& other) {		//ввод
	in >> dynamic_cast<Human&>(other);
	cout << "Номер паспорта: ";
	other.exc.getPositivNum(other.num_passport);			//ввод и проверка номера паспорта
	return in;
}