#pragma once
#include "MyBinFile.h"

template <typename T>
bool MyBinFile<T>::OpenRead() {			//������� � ������ ������
	try {
		this->fin.open(this->nameFile, ios::in | ios::binary);
		if (!this->isOpen()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(100, "������ �������� �����", "����� ���");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
bool MyBinFile<T>::OpenWrite() {			//������� � ������ ������
	try {
		this->fout.open(this->nameFile, ios::out | ios::binary);
		if (!this->isOpen()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(100, "������ �������� �����", "�������� ����� ��� �/��� ������������ �������� �����");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
bool MyBinFile<T>::OpenAdd() {			//������� � ������ ��������
	try {
		this->fout.open(this->nameFile, ios::out | ios::app | ios::binary);
		if (!this->isOpen()) 			//���� ���� �� ��������/����� ���
			throw MyExceptionFILE(100, "������ �������� �����", "�������� ����� ��� �/��� ������������ �������� �����");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
		return false;
	}
	return true;
};

template <typename T>
void MyBinFile<T>::Write(T& inform) {		//��������
	try {
		if (!this->fout.is_open() && this->fin.is_open())		//���� ����� ������
			throw MyExceptionFILE(-100, "�������� �����", "�� ������� �������� � ���� � ������ ������");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
		this->fout.write((char*)&inform, sizeof(T));
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
	}
};

template <typename T>
void MyBinFile<T>::Read(T& inform) {		//���������
	try {
		if (this->fout.is_open() && !this->fin.is_open())				//���� �� ��� �����
			throw MyExceptionFILE(-100, "�������� �����", "�� ������� ������� �� ����� � ������ ������");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
		this->fin.read((char*)&inform, sizeof(T));		//������
		
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();				//����� ������
	}
};