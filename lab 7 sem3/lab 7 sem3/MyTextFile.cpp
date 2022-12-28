#pragma once
#include "MyTextFile.h"

template <typename T>
bool MyTextFile<T>::OpenRead() {			//������� � ������ ������
	try {
		this->fin.open(this->nameFile, ios::in);
		if (!this->fin.is_open()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(110, "������ �������� �����", "���� �� ����������");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
bool MyTextFile<T>::OpenWrite() {			//������� � ������ ������
	try {
		this->fout.open(this->nameFile, ios::out);
		if (!this->fout.is_open()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(100, "������ �������� �����", "�� ����� �������� ��������� ������");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
bool MyTextFile<T>::OpenAdd() {			//������� � ������ ��������
	try {
		this->fout.open(this->nameFile, ios::out | ios::app);
		if (!this->fout.is_open()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(100, "������ �������� �����", "�� ����� �������� ���������� ������");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
void MyTextFile<T>::Write(T& inform) {		//��������
	try {
		if (!this->fout.is_open() && this->fin.is_open())		//���� ����� ������
			throw MyExceptionFILE(-100, "�������� �����", "�� ������� �������� � ���� � ������ ������");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
		this->fout << inform;			//������
		this->fout << endl;
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
	}
};

template <typename T>
void MyTextFile<T>::Read(T& inform) {		//���������
	try {
		if (this->fout.is_open() && !this->fin.is_open())				//���� �� ��� �����
			throw MyExceptionFILE(-100, "�������� �����", "�� ������� ������� �� ����� � ������ ������");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
		this->fin >> inform;			//������
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();				//����� ������
	}
};