#pragma once
#include "Date.h"

struct tax {			//������� �������
	Date data;			//���� �������
	int summa;			//�����

	tax() {		//�� ���������
		data = { 0,0,0 };
		summa = 0;
	}

	tax(const tax& other) {			//�����������
		this->data = other.data;
		this->summa = other.summa;
	}

	tax operator= (const tax& other) {		//�������� =
		this->data = other.data;
		this->summa = other.summa;
		return *this;
	}
};

struct addres {				//�����
	char city[10];			//�����
	char street[10];		//�����
	int home;				//���

	addres() {			//�� ���������
		city[0] = '\0';
		street[0] = '\0';
		home = 0;
	}

	addres(const addres& other) {		//�����������
		this->home = other.home;
		strcpy_s(this->city, 10, other.city);
		strcpy_s(this->street, 10, other.street);
	}

	addres operator=(const addres& other) {			//�������� =
		this->home = other.home;
		strcpy_s(this->city, 10, other.city);
		strcpy_s(this->street, 10, other.street);
		return *this;
	}
};

struct cross {			//����������� �������
	Date data;			//���� �����������
	char country[10];	//������

	cross() {			//�� ���������
		data = { 0,0,0 };
		strcpy_s(country, 10, "-");
	}

	cross operator= (const cross& other) {			//�������� =
		this->data = other.data;
		strcpy_s(this->country, 10, other.country);
		return *this;
	}
};
