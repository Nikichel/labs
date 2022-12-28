#include "class.h"


void Array::setSize(int length) {			//���������� �����
	this->length = length;			//������ �����
	if (ms!=NULL) 
		delete[] ms;			//�������� ������ ����������
	ms = new int[this->length];			//��������� ������
	for (int i = 0; i < this->length; i++) {
		ms[i] = 0;			//�������������
	}
}
int Array::getSize() {			//�������� �����
	return length;
}

void Array::show() {			//����� �������
	if (ms == NULL) {
		cout << "������� ���!"<<endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		cout<<setw(3)<< ms[i] ;			//����� �������
	}
	cout << endl;
}

bool Array::rep_num(int num, int pos) {				//���������� �����
	for (int i = 0; i < pos; i++) {
		if (ms[i] == num) {				//���� ���� ����������
			return true;
		}
	}
	return false;			//���� ���
}

void Array::correct_cin(int& num) {				//���������� ����
	do {
		cin.clear();
		cin >> num;
		if (cin.fail()) {			//������������ ����
			rewind(stdin);			//������� 
			cout << "������ �����!" << endl;
		}
	} while (cin.fail());
}

void Array::input() {			//���� �������
	if (ms == NULL) {
		cout << "������� ���!" << endl;
		return;
	}
	int num=0;
	for (int i = 0; i < length; i++) {
		cout << "[" << i << "]: ";
		correct_cin(num);		//�������� �����
		if (rep_num(num,i)) {			//������ �����
			i--;
			cout << "����� ��� ����!" << endl;
		}
		else {
			ms[i] = num;			//������ �����
		}
	}
	rewind(stdin);
}

void Array::cut(int new_size) {				//�������� �����
	Array tmp(*this);		//����������� ���. �������
	delete[] ms;		//��������
	length = new_size;			//����� �����
	ms = new int[length];		//��������� ������
	for (int i = 0; i < length; i++)	
		ms[i] = tmp.ms[i];				//����������� 
}

Array Array::operator& (const Array& other) {			//����������� 2-�� ��������
	Array cross_arr(length);			//������ �����������
	int i1, i2, i3;
	i1 = i2 = i3 = 0;
	for (i1; i1 < this->length; i1++) {			//���� �� 1 �������
		i2 = 0;
			for (i2; i2 < other.length; i2++)			//���� �� 2-��
				if (this->ms[i1] == other.ms[i2] && i3 < cross_arr.length)			//���� �����������
					cross_arr.ms[i3++] = this->ms[i1];
	}
	cross_arr.cut(i3);			//�������� �����
	return cross_arr;
}

void Array::operator=(const Array& other) {			//�������� =
	delete[] ms;		//�������� 
	this->length = other.length;		//������ �����
	ms = new int[this->length];		//��������� ������
	for (int i = 0; i < this->length; i++)	
		this->ms[i] = other.ms[i];			//������ �����
}