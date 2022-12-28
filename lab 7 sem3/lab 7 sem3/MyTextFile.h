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

	bool OpenRead();		//������� � ������ ������
	bool OpenWrite();		//������� � ������ ������
	bool OpenAdd();			//������� � ������ ��������
	void Write(T& inform);		//��������
	void Read(T& inform);		//���������
};
