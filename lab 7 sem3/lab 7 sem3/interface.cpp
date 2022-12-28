#include "interface.h"

void myInterface::menu() {
	int Type;
	bool fl = true;
	queue<Human> humans;            //������� Human
	queue<Entrepreneur> entrepreneurs;      //������� Entrepreneur
	queue<Tourist> tourists;            //������� Tourist
	queue<Business> businesses;             //������� Business
	while (fl) {
		cout << "�������: " << endl << "1. �������" << endl << "2. ��������������" << endl
			<< "3. ������" << endl << "4. ���������" << endl << "5. �����" << endl;
		exc.getNumWithBorders(Type, 1, 5);			 //����� ���� ������
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
			menuq(businesses);			//����� ���� �������
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
void myInterface::menu_add(queue<T>& q) {		//���� ��������
	checking exc;
	int var;
	cout << "�������� ��������: " << endl << "1. �������� �������" << endl << "2. �������� �������" << endl;
	exc.getNumWithBorders(var, 1, 2);
	//cin >> var;
	cout << endl;
	switch (var)			//����� ��������
	{
	case 1:
	{
		cout << "������� ����������" << endl;
		T addElem;
		cin >> addElem;
		q.put(addElem);		//�������� �������		
		break;
	}
	case 2:
	{
		int count;
		T addElem;
		queue<T> add;
		cout << "������� ���������� ��������� �������: ";
		cin >> count;
		for (int i = 0; i < count; i++) {
			cin >> addElem;
			add.put(addElem);				//�������� �������
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
	cout << "�������� ��������: " << endl << "1. ������� � ������" << endl << "2. ������� �� ���������� � �����������" << endl;
	exc.getNumWithBorders(var, 1, 2);		//����� ��������
	cout << endl;
	switch (var)
	{
	case 1:
	{
		try {
			q.del();				//������� � ������
		}
		catch (MyException err) {
			err.what();
		}
		break;
	}
	case 2:
	{
		T find;
		find.filter();			//���� ���������� ��� ������
		queue<T> rez=alg.searchQueue(q.Begin(), q.End(), find);
		q.del_any(rez);
		cout << "��������� ����������: " << endl;
		rez.headTable();
		rez.show();						//����� ���������� ������
		break;
	}
	}
}

template <typename T>
void myInterface::saveInFile(queue<T>& q) {
	int var;
	char fileName[40];
	cout << endl << "�������� ��������: " << endl << "1. ��������� � ��������" << endl << "2. ��������� � ��������" << endl;
	exc.getNumWithBorders(var, 1, 2);		//����� ��������
	switch (var)
	{
	case(1): {
		cout << "������� �������� �����: ";
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
		cout << "������� �������� �����: ";
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
	cout << endl << "�������� ��������: " << endl << "1. ��������� �� ���������" << endl << "2. ��������� �� ���������" << endl;
	exc.getNumWithBorders(var, 1, 2);		//����� ��������
	switch (var)
	{
	case(1): {
		cout << "������� �������� �����: ";
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
		cout << "������� �������� �����: ";
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
void myInterface::menuq(queue<T>& q) {			//����
	checking exc;
	algorithm<T> alg;
	int var;
	bool flag = false;
	do {
		cout << endl << "�������� ��������: " << endl << "1. ��������" << endl << "2. �������" << endl << "3. �����������" << endl
			<< "4. �����" << endl << "5. �������� ������" << endl << "6. �������� �������" << endl << "7. ��������� ���������� � ����" << endl
			<< "8. ��������� ���������� �� �����" << endl << "9. ������� �����" << endl;
		exc.getNumWithBorders(var, 1, 9);		//����� ��������

		cout << endl;
		switch (var)
		{
		case 1:
		{
			menu_add(q);			//���� ��������
			break;
		}
		case 2:
		{
			if (!q.isEmpty())
				menu_del(q);			//���� �������
			break;
		}
		case 3:
		{
			cout << "���� �������:" << endl;
			if (!q.isEmpty()) {
				q.headTable();				//����� �����
				q.show();					//����� �������
				cout << endl;
			}
			break;
		}
		case 4:
		{
			
			T obj;
			obj.filter();		//���� ����� ������� ��� ������
			queue<T> rez = alg.searchQueue(q.Begin(), q.End(), obj);
			cout << "���������:" << endl;
			if (rez.isEmpty())
				cout << "��� ������";
			else {
				rez.headTable();
				rez.show();						//����� ���������� ������
			}

			break;
		}
		case 5: {
			T obj;
			obj.filter();		//���� ����� ������� ��� ������
			queue<T> rez = alg.searchQueue(q.Begin(), q.End(), obj);	//�����
			if (!rez.isEmpty()) {
				q.del_any(rez);
				for (queue<T>::template Iterator iter = rez.Begin(); iter != rez.End(); iter++) {
					cout << (*iter) << endl;
					(*iter).change();
					q.put(*iter);			//��������� ������
				}
			}
			break;
		}
		case 6:
		{
			while (!q.isEmpty()) {		//���� ������� ����
				q.del();				//������� � ������
			}
			break;
		}
		case 9:
		{
			flag = true;			//�����
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