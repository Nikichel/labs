#pragma once
#include "MyFile.h"

template <typename T>
class MyBinFile :
	public MyFile<T>
{
public:
	MyBinFile() : MyFile<T>() {};
	MyBinFile(char* fileName) : MyFile<T>(fileName) {};
	~MyBinFile() {};

	void OpenRead();		//������� � ������ ������
	void OpenWrite();		//������� � ������ ������
	void OpenAdd();			//������� � ������ ��������
	void Write(T& inform);		//��������
	void Read(T& inform);		//���������
};

