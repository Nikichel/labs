#include "funs.h"
#include "class.h"

void menu(int& ch) {			//������� ����
	cout << "1-������� ������(�)" << endl;
	cout << "2-��������� ������(�)" << endl;
	cout << "3-������� ������� �� �����" << endl;
	cout << "4-����� ���������� ���� ��������" << endl;
	cout << "5-����� ����������� ���� ��������" << endl;
	cout << "6-����� �� ���������" << endl;
	do {
		rewind(stdin);
		input_unsignet_int(ch);			//���� � �������� �����
		if (ch < 0 || ch>6)
			cout << "������ ������ ���! ��������� ����" << endl;
	} while (ch < 0 || ch>6);
}

void input_unsignet_int(int& num) {			//���� � �������� �������������� �����
	while (1) {
		if ((cin >> num).good() && num > 0) {
			return;
		}
		if (cin.fail() || num <= 0) {				//���� � �������� �����
			rewind(stdin);
			cin.clear();
			cout << "�������� ����" << endl;
		}
	}
}

void give_mem(Array** ars, int count) {			//��������� ������ ��� ������� ��������
	if ((*ars) != NULL)
		delete[](*ars);				//������� ������
	*ars = new Array[count];		//��������� ������
}

void input_arrays(Array* ars, int count) {			//���������� ��������
	for (int i = 0; i < count; i++) {			//���� �� ��������� ������� �������
		cout << "Ar" << i << endl;
		if (ars[i].getSize() == 0) {
			int len=0;
			cout << "������� ����� �������: ";
			input_unsignet_int(len);
			ars[i].setSize(len);
		}
		ars[i].input();				//���� �������� � ������
	}
}

void show_arrays(Array* ars, int count) {			//����� �������� �� �����
	for (int i = 0; i < count; i++) {			//���� �� ��������
		cout << "\nAr" << i << ": ";
		ars[i].show();			//����� �������
	}
}

void cross_two(Array* ars, int count) {				//����������� ���� ��������
	int num1, num2;					
	num1 = num2 = 0;
	cout << "������� �����a �������� ��� ������� ����� �����������: ";
	for (int i = 0; i < count; i++)
		cout << i + 1 << "\t";			//����� ������� ��������
	cout << "\n";
	do {
		input_unsignet_int(num1);
		input_unsignet_int(num2);			//����� ������� ��� ���������� �����������
		if ((num1 - 1) >= count || (num2 - 1) >= count)
			cout << "�� ����� ����� ��������������� �������. ��������� �������" << endl;
	} while ((num1 - 1) >= count || (num2 - 1) >= count);
	cout << "Ar" << num1 - 1 << ": ";
	ars[num1 - 1].show();			//����� ������� �������
	cout << "Ar" << num2 - 1 << ": ";
	ars[num2 - 1].show();			//����� ������� �������
	Array cross_arr= ars[num1 - 1] & (ars[num2 - 1]);			//���������� �����������
	cout << "����������� Ar" << num1 - 1 << " � Ar" << num2 - 1 << ": ";
	if (cross_arr.getSize())
		cross_arr.show();			//����� �����������
	else
		cout << "����������� ���" << endl;
}

void cross_all(Array* ars, int count) {				//����������� ����  ��������
	Array cross_arr(ars[0]);
	for (int i = 1; i < count; i++) {
		cross_arr = cross_arr & (ars[i]);			//����������� ���� ��������
	}
	show_arrays(ars, count);			//����� �������� 
	cout << "\n����������� ���� ��������: " ;
	if (cross_arr.getSize())
		cross_arr.show();			//����� �����������
	else
		cout << "����������� ���" << endl;
}