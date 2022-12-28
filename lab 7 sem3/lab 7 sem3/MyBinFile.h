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

	bool OpenRead();		//открыть в режиме чтения
	bool OpenWrite();		//открыть в режиме записи
	bool OpenAdd();			//открыть в режиме добавить
	void Write(T& inform);		//записать
	void Read(T& inform);		//прочитать
};

