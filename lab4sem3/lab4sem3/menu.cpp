#include "Queue.h"
#include "Business.h"

template <typename T>
void menu_add(queue<T>& q) {		//меню добавить
	int var;
	cout << "Выберите операцию: " << endl << "1. Добавить элемент" << endl << "2. Добавить очередь" << endl;
	cin >> var;
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
void menu_del(queue<T>& q) {
	int var;
	cout << "Выберите операцию: " << endl << "1. Удалить с головы" << endl << "2. Удалить по параметрам с сохранением" << endl;
	cin >> var;			//выбор операции
	cout << endl;
	switch (var)
	{
	case 1:
	{
		q.del();				//удалить с головы
		break;
	}
	case 2:
	{
		T find;
		cout << "Если параметр вам не нужен пропускайте его(enter для строк, 0 для чисел)" << endl;
		cout << "Введите информацию для поиска:" << endl;
		cin >> find;			//ввод информации для поиска

		queue<T> rez = q.search(find);				//поиск
		q.del_any(rez);
		cout << "Удаленная информация: " << endl;
		rez.headTable();
		rez.show();						//вывод результата поиска
		break;
	}
	}
}

template <typename T>
queue<T> findInf(queue<T> q) {			//поиск
	int var;
	T obj;
	while (!q.isEmpty()) {
		cout << "Поиск по:" << endl << "1. Имяни" << endl << "2. Фамилии" << endl << "3. Отчеству" << endl << "4. Дате"
			<< endl << "5. Выйти" << endl;				//выбор параметра
		cin >> var;
		cout << "Введите информацию" << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			char name[15];
			cin.getline(name, 15);
			obj.setName(name);				//по имени
			break;
		}
		case 2: {
			char surname[15];
			cin.getline(surname, 15);
			obj.setSurname(surname);		//по фамилии
			break;
		}
		case 3: {
			char midname[15];
			cin.getline(midname, 15);
			obj.setMidname(midname);		//по отчеству
			break;
		}
		case 4: {
			Date data;
			cin >> data;
			obj.setDate(data.getDay(), data.getMonth(), data.getYear());			//по дате
			break;
		}
		case 5: {
			return q;
		}
		}
		q = q.search(obj);
		q.show();
		cout << endl;				//вывод промежуточного поиска
	}

	return q;
}

template <typename T>
void menuq(queue<T>& q) {			//меню
	int var;
	bool flag = false;
	do {
		cout << endl << "Выберите операцию: " << endl << "1. Добавить" << endl << "2. Удалить" << endl
			<< "3. Просмотреть" << endl << "4. Поиск" << endl <<"5. Изменить данные" << endl << "6. Очистить очередь" << endl << "7. Сменить класс" << endl;
		cin >> var;			//выбор операции
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
			//T find;
			//cout << "Если параметр вам не нужен пропускайте его(enter для строк, 0 для чисел)" << endl;
			//cout << "Введите информацию для поиска:" << endl;

			//cin >> find;			//ввод информации для поиска

			//queue rez = this->search(find);				//поиск

			queue<T> rez = findInf(q);

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
			node<T>* tmp = q.getTail();
			while (tmp) {
				cout << tmp->inform << endl;
				tmp->inform.change();
				tmp = tmp->nx;
			}
			break;
		}
		case 6:
		{
			while (!q.isEmpty()) {
				q.del();
			}
			break;
		}
		case 7:
		{
			flag = true;			//выход
		}
		}
	} while (!flag);
}