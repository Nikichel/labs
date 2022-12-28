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

	void OpenRead();		//открыть в режиме чтения
	void OpenWrite();		//открыть в режиме записи
	void OpenAdd();			//открыть в режиме добавить
	void Write(T& inform);		//записать
	void Read(T& inform);		//прочитать
};

