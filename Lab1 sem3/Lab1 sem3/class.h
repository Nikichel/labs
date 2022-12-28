#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Array {
private:
	int length;			//�����
	int* ms;		//������
	bool rep_num(int num, int pos);			//������. ����.
	void correct_cin(int& num);				//���������� ����
public:
	Array() {			//����������� �� ���������
		length = 0;
		ms = NULL;
	};			
	Array(int length) {			//����������� � �����������
		this->length = length;			//������ �����
		ms = new int[this->length];			//��������� ������
		for (int i = 0; i < this->length; i++)
			ms[i] = 0;			//�������������
	};			
	Array(const Array& other) {				//����������� �����������
		this->length = other.length;		//����������� �����
		ms = new int[this->length];				//��������� ������
		for (int i = 0; i < this->length; i++)	
			this->ms[i] = other.ms[i];			//����������� �������
	};			
	~Array() {			//����������
		delete[] ms;		//������������ ������
	};				
	
	

	void setSize(int length);			//���������� �����
	int getSize();			//�������� �����
	void show();			//����� �������
	void input();			//���� �������
	Array operator& (const Array& other);			//����������� ��������
	void operator=(const Array& other);			//�������� =
	void cut(int new_size);				//�������� �������
};