#pragma once
#include "MyFile.h"

template <typename T>
class MyTextFile :
    public MyFile<T>
{
public:

	MyTextFile() : MyFile<T>(){};
	MyTextFile(char* fileName) : MyFile<T>(fileName) {};
	~MyTextFile() {};

	void OpenRead();		//������� � ������ ������
	void OpenWrite();		//������� � ������ ������
	void OpenAdd();			//������� � ������ ��������
	void Write(T& inform);		//��������
	void Read(T& inform);		//���������
};
