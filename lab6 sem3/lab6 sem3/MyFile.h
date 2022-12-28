#pragma once
#include <fstream>
#include <iostream>
#include "MyExceptionFILE.h"

using namespace std;
template <typename T>
class MyFile
{
protected:
	ofstream fout;		//������
	ifstream fin;		//������
	char nameFile[40];		//��������
public:
	MyFile() {
		strcpy_s(nameFile, 40, "\0");
	}
	~MyFile() {	
		
	}
	MyFile(char* fileName) {
		strcpy_s(this->nameFile, 40, fileName);
	}
	void fileClose();			//�������
	//void Write(T& inform);		//��������
	//void Read(T& inform);		//���������
	void remote();			//� ������ �����
	bool isEnd();			//�����?
	bool isOpen();			//������?
};

template <typename T>
void MyFile<T>::fileClose() {				//�������
	try {
		if (fout.is_open())
			fout.close();
		if (fin.is_open())
			fin.close();				//������� �������� ����
		if (fout.is_open() || fin.is_open()) {			//���� �� ��������
			throw MyExceptionFILE(101, "������ �������� �����", "���� ���������");
		}
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//����� ������
	}
};

template <typename T>
void MyFile<T>::remote() {					//� ������ �����
	if (fout.is_open())
		fout.seekp(0, ios::beg);		//����������� ��������� � ������
};

template <typename T>
bool MyFile<T>::isEnd() {					//�����?
	if (fin.eof() && fin.is_open() || fout.eof() && fout.is_open())
		return true;			//�� �����
	else
		return false;		//��� 
};

template <typename T>
bool MyFile<T>::isOpen() {
	if (fin.is_open() || fout.is_open())
		return true;
	return false;
}