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

void Business::filter() {			//фильт поиска
	int var;
	while (1) {
		cout << "Поиск по:" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl << "4. Дату"
			<< endl << "5. Лицензию" << endl << "6. Паспорт" << endl <<"7. Добавить пересечение границы"
			<<endl<<"8. Добавить выплату налога"<<endl<<"9 Выйти из фильтра" << endl;				//выбор параметра
		cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
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
			cout << "Введите лицензию" << endl;
			exc.getPositivNum(this->license);
			break;
		}
		case 6: {
			cout << "Введите номер паспорта" << endl;
			exc.getPositivNum(this->num_passport);			//ввод данных
			break;
		}
		case 7: {
			char country[10];
			cout << "Страна: ";
			exc.getRuStr(country, 10);
			cout << "Дата пересечения" << endl;
			Date cross;
			cin >> cross;
			addBroadCross(country, cross);
			break;
		}
		case 8: {
			int summ;
			cout << "Сумма: ";
			exc.getPositivNum(summ);
			cout << "Дата пересечения" << endl;
			Date pay;
			cin >> pay;
			addTax(pay, summ);
			break;
		}
		case 9: {
			return;
		}
		default: {
			cout << "Пункта нет" << endl;
			break;
		}
		}
	}
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

void Business::change() {			//меню изменения полей
	int var;
	bool fl = true;
	while (fl) {
		cout << "Сменить" << endl << "1. Имя" << endl << "2. Фамилию" << endl << "3. Отчество" << endl
			<<"4. Паспорт" <<endl<<"5. Номер лицензии" <<endl<< "6. Выйти"<<endl;
		exc.getNum(var);			//выбор варианта
		cout << "Заполнять ФИО на АНГЛИЙСКОМ! " << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			cout << "Введите имя" << endl;
			exc.getEngStr( name, 15);			//менять имя
			break;
		}
		case 2: {
			cout << "Введите фамилию" << endl;
			exc.getEngStr( surname, 15);			//менять фамилию
			break;
		}
		case 3: {
			cout << "Введите отчество" << endl;
			exc.getEngStr( midname, 15);			//менять отчество
			break;
		}
		case 4: {
			cout << "Введите номер паспорта" << endl;
			exc.getPositivNum(num_passport);		//менять паспорт
			break;
		}
		case 5: {
			cout << "Введите номер лицензии" << endl;
			exc.getPositivNum(license);				//менять лицензию
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

istream& operator>>(istream& in, Business& other) {				//ввод
	in >> dynamic_cast<Human&>(other);
	cout << "Номер паспорта: ";
	other.exc.getPositivNum(other.num_passport);
	cout << "Адрес регистрации"<<endl<<"Город: ";
	rewind(stdin);
	other.exc.getRuStr(other.addresLicense.city, 10);
	cout << "Улица: ";
	rewind(stdin);
	other.exc.getRuStr( other.addresLicense.street, 10);
	cout << "Дом: ";
	other.exc.getPositivNum(other.addresLicense.home);
	cout << "Номер лицензии: ";
	other.exc.getPositivNum(other.license);						//ввод и проверка полей класса
	return in;
}