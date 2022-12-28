#include "interface.h"

void myInterface::menu() {
    int Type;
    bool fl = true;
    queue<Human> humans;					//������� Human
    queue<Entrepreneur> entrepreneurs;      //������� Entrepreneur
    queue<Tourist> tourists;				//������� Tourist
    queue<Business> businesses;             //������� Business
    while (fl) {
        cout << "�������: " << endl << "1. �������" << endl << "2. ��������������" << endl
            << "3. ������" << endl << "4. ���������" <<endl <<"5. �����" << endl;

        exc.getNum(Type);					//����� ���� ������
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
		default: {
			cout << "������ ���" << endl;
			break;
		}
        }
    }
};

template <typename T>
void myInterface::menu_add(queue<T>& q) {		//���� ��������
	int var;
	cout << "�������� ��������: " << endl << "1. �������� �������" << endl << "2. �������� �������" << endl;
	exc.getNum(var);
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
	default: {
		cout << "������ ���" << endl;
		break;
	}
	}
}

template <typename T>
void myInterface::menu_del(queue<T>& q) {		//���� �������
	int var;
	cout << "�������� ��������: " << endl << "1. ������� � ������" << endl << "2. ������� �� ���������� � �����������" << endl;
	exc.getNum(var);	//����� ��������
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
		T obj;
		obj.filter();	//���� ����� ������� ��� ������
		queue<T> rez = q.search(obj);		//����		//���� ���������� ��� ������

		q.del_any(rez);
		cout << "��������� ����������: " << endl;
		rez.headTable();
		rez.show();						//����� ���������� ������
		break;
	}
	default: {
		cout << "������ ���" << endl;
		break;
	}
	}
}

template <typename T>
void myInterface::menuq(queue<T>& q) {			//����
	int var;
	bool flag = false;
	do {
		cout << endl << "�������� ��������: " << endl << "1. ��������" << endl << "2. �������" << endl << "3. �����������" << endl 
			<< "4. �����" << endl << "5. �������� ������" << endl << "6. �������� �������" << endl << "7. ������� �����" << endl;
		exc.getNum(var);	//����� ��������
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
			if(!q.isEmpty())
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
			obj.filter();	//���� ����� ������� ��� ������
			queue<T> rez = q.search(obj);		//����

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
			obj.filter();	//���� ����� ������� ��� ������
			queue<T> rez = q.search(obj);		//�����
			node<T>* tmp = rez.getTail();
			if (!rez.isEmpty()) {
				q.del_any(rez);
				while (tmp) {
					cout << tmp->inform << endl;
					tmp->inform.change();
					q.put(tmp->inform);
					tmp = tmp->nx;					//��������� ������
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
		case 7:
		{
			flag = true;			//�����
		}
		default: {
			cout << "������ ���" << endl;
			break;
		}
		}
	} while (!flag);
}