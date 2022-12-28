#pragma once
#include "MyTextFile.h"

template <typename T>
bool MyTextFile<T>::OpenRead() {			//открыть в режиме чтения
	try {
		this->fin.open(this->nameFile, ios::in);
		if (!this->fin.is_open()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(110, "Ошибка открытия файла", "Файл не существует");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
bool MyTextFile<T>::OpenWrite() {			//открыть в режиме записи
	try {
		this->fout.open(this->nameFile, ios::out);
		if (!this->fout.is_open()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(100, "Ошибка открытия файла", "Во время открытия произошла ошибка");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
bool MyTextFile<T>::OpenAdd() {			//открыть в режиме добавить
	try {
		this->fout.open(this->nameFile, ios::out | ios::app);
		if (!this->fout.is_open()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(100, "Ошибка открытия файла", "Во время открытия происзошла ошибка");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
void MyTextFile<T>::Write(T& inform) {		//записать
	try {
		if (!this->fout.is_open() && this->fin.is_open())		//если режмм чтения
			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете записать в файл в режиме чтения");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме записи");
		this->fout << inform;			//запись
		this->fout << endl;
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
	}
};

template <typename T>
void MyTextFile<T>::Read(T& inform) {		//прочитать
	try {
		if (this->fout.is_open() && !this->fin.is_open())				//если не тот режим
			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете прочить из файла в режиме записи");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме чтения");
		this->fin >> inform;			//чтение
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();				//вывод ошибки
	}
};