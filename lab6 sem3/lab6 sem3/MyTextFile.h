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

	void OpenRead();		//открыть в режиме чтения
	void OpenWrite();		//открыть в режиме записи
	void OpenAdd();			//открыть в режиме добавить
	void Write(T& inform);		//записать
	void Read(T& inform);		//прочитать
};
