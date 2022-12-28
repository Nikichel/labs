#include "Queue.h"
#include "Business.h"

template <typename T>
void menu_add(queue<T>& q) {		//���� ��������
	int var;
	cout << "�������� ��������: " << endl << "1. �������� �������" << endl << "2. �������� �������" << endl;
	cin >> var;
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
void menu_del(queue<T>& q) {
	int var;
	cout << "�������� ��������: " << endl << "1. ������� � ������" << endl << "2. ������� �� ���������� � �����������" << endl;
	cin >> var;			//����� ��������
	cout << endl;
	switch (var)
	{
	case 1:
	{
		q.del();				//������� � ������
		break;
	}
	case 2:
	{
		T find;
		cout << "���� �������� ��� �� ����� ����������� ���(enter ��� �����, 0 ��� �����)" << endl;
		cout << "������� ���������� ��� ������:" << endl;
		cin >> find;			//���� ���������� ��� ������

		queue<T> rez = q.search(find);				//�����
		q.del_any(rez);
		cout << "��������� ����������: " << endl;
		rez.headTable();
		rez.show();						//����� ���������� ������
		break;
	}
	}
}

template <typename T>
queue<T> findInf(queue<T> q) {			//�����
	int var;
	T obj;
	while (!q.isEmpty()) {
		cout << "����� ��:" << endl << "1. �����" << endl << "2. �������" << endl << "3. ��������" << endl << "4. ����"
			<< endl << "5. �����" << endl;				//����� ���������
		cin >> var;
		cout << "������� ����������" << endl;
		rewind(stdin);
		switch (var) {
		case 1: {
			char name[15];
			cin.getline(name, 15);
			obj.setName(name);				//�� �����
			break;
		}
		case 2: {
			char surname[15];
			cin.getline(surname, 15);
			obj.setSurname(surname);		//�� �������
			break;
		}
		case 3: {
			char midname[15];
			cin.getline(midname, 15);
			obj.setMidname(midname);		//�� ��������
			break;
		}
		case 4: {
			Date data;
			cin >> data;
			obj.setDate(data.getDay(), data.getMonth(), data.getYear());			//�� ����
			break;
		}
		case 5: {
			return q;
		}
		}
		q = q.search(obj);
		q.show();
		cout << endl;				//����� �������������� ������
	}

	return q;
}

template <typename T>
void menuq(queue<T>& q) {			//����
	int var;
	bool flag = false;
	do {
		cout << endl << "�������� ��������: " << endl << "1. ��������" << endl << "2. �������" << endl
			<< "3. �����������" << endl << "4. �����" << endl <<"5. �������� ������" << endl << "6. �������� �������" << endl << "7. ������� �����" << endl;
		cin >> var;			//����� ��������
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
			//T find;
			//cout << "���� �������� ��� �� ����� ����������� ���(enter ��� �����, 0 ��� �����)" << endl;
			//cout << "������� ���������� ��� ������:" << endl;

			//cin >> find;			//���� ���������� ��� ������

			//queue rez = this->search(find);				//�����

			queue<T> rez = findInf(q);

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
			flag = true;			//�����
		}
		}
	} while (!flag);
}