#include "interface.h"

void myInterface::menu() {
	int Type;
	bool fl = true;
	queue<Human> humans;            //очередь Human
	queue<Entrepreneur> entrepreneurs;      //очередь Entrepreneur
	queue<Tourist> tourists;            //очередь Tourist
	queue<Business> businesses;             //очередь Business
	while (fl) {
		cout << "Введите: " << endl << "1. Человек" << endl << "2. Препринематель" << endl
			<< "3. Турист" << endl << "4. Бизнесмен" << endl << "5. Выход" << endl;
		exc.getNumWithBorders(Type, 1, 5);			 //выбор типа класса
		cout << endl;
		switch (Type)
		{
		case 1:
		{
			menuq(humans);
			break;
		}
		case 2:
		{
			menuq(entrepreneurs);
			break;
		}
		case 3:
		{

			menuq(tourists);
			break;
		}
		case 4:
		{
			menuq(businesses);			//выбор меню очереди
			break;
		}
		case(5):
		{
			fl = false;
		}
		}
	}
};

template <typename T>
void myInterface::menu_add(queue<T>& q) {		//меню добавить
	checking exc;
	int var;
	cout << "Выберите операцию: " << endl << "1. Добавить элемент" << endl << "2. Добавить очередь" << endl;
	exc.getNumWithBorders(var, 1, 2);
	//cin >> var;
	cout << endl;
	switch (var)			//выбор операции
	{
	case 1:
	{
		cout << "Введите информацию" << endl;
		T addElem;
		cin >> addElem;
		q.put(addElem);		//добавить элемент		
		break;
	}
	case 2:
	{
		int count;
		T addElem;
		queue<T> add;
		cout << "Введите количество элементов очереди: ";
		cin >> count;
		for (int i = 0; i < count; i++) {
			cin >> addElem;
			add.put(addElem);				//добавить очередь
		}
		q = q + add;
		break;
	}
	}
}

template <typename T>
void myInterface::menu_del(queue<T>& q) {
	checking exc;
	algorithm<T> alg;
	int var;
	cout << "Выберите операцию: " << endl << "1. Удалить с головы" << endl << "2. Удалить по параметрам с сохранением" << endl;
	exc.getNumWithBorders(var, 1, 2);		//выбор операции
	cout << endl;
	switch (var)
	{
	case 1:
	{
		try {
			q.del();				//удалить с головы
		}
		catch (MyException err) {
			err.what();
		}
		break;
	}
	case 2:
	{
		T find;
		find.filter();			//ввод информации для поиска
		queue<T> rez=alg.searchQueue(q.Begin(), q.End(), find);
		q.del_any(rez);
		cout << "Удаленная информация: " << endl;
		rez.headTable();
		rez.show();						//вывод результата поиска
		break;
	}
	}
}

template <typename T>
void myInterface::saveInFile(queue<T>& q) {
	int var;
	char fileName[40];
	cout << endl << "Выберите операцию: " << endl << "1. Сохранить в тестовый" << endl << "2. Сохранить в бинарный" << endl;
	exc.getNumWithBorders(var, 1, 2);		//выбор операции
	switch (var)
	{
	case(1): {
		cout << "Введите название файла: ";
		cin.getline(fileName, 40);
		strcat_s(fileName, ".txt");
		MyTextFile<T> file(fileName);
		file.OpenWrite();
		for (queue<T>::template Iterator iter = q.Begin(); iter != q.End(); iter++) {
			file.Write(*iter);
		}
		file.fileClose();
		break;
	}
	case(2): {
		cout << "Введите название файла: ";
		cin.getline(fileName, 40);
		strcat_s(fileName, ".bin");
		MyBinFile<T> file(fileName);
		file.OpenWrite();
		for (queue<T>::template Iterator iter = q.Begin(); iter != q.End(); iter++) {
			file.Write(*iter);
		}
		file.fileClose();
		break;
	}
	default:
		break;
	}
};

template <typename T>
void myInterface::loadFromFile(queue<T>& q) {
	int var;
	char fileName[40];
	cout << endl << "Выберите операцию: " << endl << "1. Прочитать из тестового" << endl << "2. Прочитать из бинарного" << endl;
	exc.getNumWithBorders(var, 1, 2);		//выбор операции
	switch (var)
	{
	case(1): {
		cout << "Введите название файла: ";
		cin.getline(fileName, 40);
		strcat_s(fileName, ".txt");
		MyTextFile<T> file(fileName);
		if (file.OpenRead()) {
			T obj;
			while (!file.isEnd()) {
				file.Read(obj);
				if (!file.isEnd())
					q.put(obj);
			}
			file.fileClose();
		}
		break;
	}
	case(2): {
		cout << "Введите название файла: ";
		cin.getline(fileName, 40);
		strcat_s(fileName, ".bin");
		MyBinFile<T> file(fileName);
		if (file.OpenRead()) {
			T obj;
			while (!file.isEnd()) {
				file.Read(obj);
				if (!file.isEnd())
					q.put(obj);
			}
			file.fileClose();
		}
		break;
	}
	default:
		break;
	}
};

template <typename T>
void myInterface::menuq(queue<T>& q) {			//меню
	checking exc;
	algorithm<T> alg;
	int var;
	bool flag = false;
	do {
		cout << endl << "Выберите операцию: " << endl << "1. Добавить" << endl << "2. Удалить" << endl << "3. Просмотреть" << endl
			<< "4. Поиск" << endl << "5. Изменить данные" << endl << "6. Очистить очередь" << endl << "7. Сохранить информацию в файл" << endl
			<< "8. Загрузить информацию из файла" << endl << "9. Сменить класс" << endl;
		exc.getNumWithBorders(var, 1, 9);		//выбор операции

		cout << endl;
		switch (var)
		{
		case 1:
		{
			menu_add(q);			//меню добавить
			break;
		}
		case 2:
		{
			if (!q.isEmpty())
				menu_del(q);			//меню удалить
			break;
		}
		case 3:
		{
			cout << "Ваша очередь:" << endl;
			if (!q.isEmpty()) {
				q.headTable();				//вывод шапки
				q.show();					//вывод очереди
				cout << endl;
			}
			break;
		}
		case 4:
		{
			
			T obj;
			obj.filter();		//ввод полей объекта для поиска
			queue<T> rez = alg.searchQueue(q.Begin(), q.End(), obj);
			cout << "Результат:" << endl;
			if (rez.isEmpty())
				cout << "Нет данных";
			else {
				rez.headTable();
				rez.show();						//вывод результата поиска
			}

			break;
		}
		case 5: {
			T obj;
			obj.filter();		//ввод полей объекта для поиска
			queue<T> rez = alg.searchQueue(q.Begin(), q.End(), obj);	//поиск
			if (!rez.isEmpty()) {
				q.del_any(rez);
				for (queue<T>::template Iterator iter = rez.Begin(); iter != rez.End(); iter++) {
					cout << (*iter) << endl;
					(*iter).change();
					q.put(*iter);			//изменение данных
				}
			}
			break;
		}
		case 6:
		{
			while (!q.isEmpty()) {		//пока очередь есть
				q.del();				//удалять с головы
			}
			break;
		}
		case 9:
		{
			flag = true;			//выход
		}
		case 7: {
			saveInFile(q);
			break;
		}
		case 8: {
			loadFromFile(q);
			break;
		}
		}
	} while (!flag);
}