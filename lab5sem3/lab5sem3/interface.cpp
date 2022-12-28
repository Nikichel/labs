#include "interface.h"

void myInterface::menu() {
    int Type;
    bool fl = true;
    queue<Human> humans;					//очередь Human
    queue<Entrepreneur> entrepreneurs;      //очередь Entrepreneur
    queue<Tourist> tourists;				//очередь Tourist
    queue<Business> businesses;             //очередь Business
    while (fl) {
        cout << "Введите: " << endl << "1. Человек" << endl << "2. Препринематель" << endl
            << "3. Турист" << endl << "4. Бизнесмен" <<endl <<"5. Выход" << endl;

        exc.getNum(Type);					//выбор типа класса
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
		default: {
			cout << "Пункта нет" << endl;
			break;
		}
        }
    }
};

template <typename T>
void myInterface::menu_add(queue<T>& q) {		//меню добавить
	int var;
	cout << "Выберите операцию: " << endl << "1. Добавить элемент" << endl << "2. Добавить очередь" << endl;
	exc.getNum(var);
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
	default: {
		cout << "Пункта нет" << endl;
		break;
	}
	}
}

template <typename T>
void myInterface::menu_del(queue<T>& q) {		//меню удалить
	int var;
	cout << "Выберите операцию: " << endl << "1. Удалить с головы" << endl << "2. Удалить по параметрам с сохранением" << endl;
	exc.getNum(var);	//выбор операции
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
		T obj;
		obj.filter();	//ввод полей объекта для поиска
		queue<T> rez = q.search(obj);		//поис		//ввод информации для поиска

		q.del_any(rez);
		cout << "Удаленная информация: " << endl;
		rez.headTable();
		rez.show();						//вывод результата поиска
		break;
	}
	default: {
		cout << "Пункта нет" << endl;
		break;
	}
	}
}

template <typename T>
void myInterface::menuq(queue<T>& q) {			//меню
	int var;
	bool flag = false;
	do {
		cout << endl << "Выберите операцию: " << endl << "1. Добавить" << endl << "2. Удалить" << endl << "3. Просмотреть" << endl 
			<< "4. Поиск" << endl << "5. Изменить данные" << endl << "6. Очистить очередь" << endl << "7. Сменить класс" << endl;
		exc.getNum(var);	//выбор операции
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
			if(!q.isEmpty())
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
			obj.filter();	//ввод полей объекта для поиска
			queue<T> rez = q.search(obj);		//поис

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
			obj.filter();	//ввод полей объекта для поиска
			queue<T> rez = q.search(obj);		//поиск
			node<T>* tmp = rez.getTail();
			if (!rez.isEmpty()) {
				q.del_any(rez);
				while (tmp) {
					cout << tmp->inform << endl;
					tmp->inform.change();
					q.put(tmp->inform);
					tmp = tmp->nx;					//изменение данных
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
		case 7:
		{
			flag = true;			//выход
		}
		default: {
			cout << "Пункта нет" << endl;
			break;
		}
		}
	} while (!flag);
}