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

	bool OpenRead();		//открыть в режиме чтения
	bool OpenWrite();		//открыть в режиме записи
	bool OpenAdd();			//открыть в режиме добавить
	void Write(T& inform);		//записать
	void Read(T& inform);		//прочитать
};
