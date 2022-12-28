#pragma once
#include <fstream>
#include <iostream>
#include "MyExceptionFILE.h"

using namespace std;
template <typename T>
class MyFile
{
protected:
	ofstream fout;		//запись
	ifstream fin;		//чтения
	char nameFile[40];		//название
public:
	MyFile() {
		strcpy_s(nameFile, 40, "\0");
	}
	~MyFile() {	
		
	}
	MyFile(char* fileName) {
		strcpy_s(this->nameFile, 40, fileName);
	}
	void fileClose();			//закрыть
	//void Write(T& inform);		//записать
	//void Read(T& inform);		//прочитать
	void remote();			//в начало файла
	bool isEnd();			//конец?
	bool isOpen();			//открыт?
};

template <typename T>
void MyFile<T>::fileClose() {				//закрыть
	try {
		if (fout.is_open())
			fout.close();
		if (fin.is_open())
			fin.close();				//закрыть открытый файл
		if (fout.is_open() || fin.is_open()) {			//если не закрылся
			throw MyExceptionFILE(101, "Ошибка закрытия файла", "Файл поврежден");
		}
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
	}
};

template <typename T>
void MyFile<T>::remote() {					//в начало файла
	if (fout.is_open())
		fout.seekp(0, ios::beg);		//перемещение указатель в начале
};

template <typename T>
bool MyFile<T>::isEnd() {					//конец?
	if (fin.eof() && fin.is_open() || fout.eof() && fout.is_open())
		return true;			//да конец
	else
		return false;		//нет 
};

template <typename T>
bool MyFile<T>::isOpen() {
	if (fin.is_open() || fout.is_open())
		return true;
	return false;
}