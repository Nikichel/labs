#pragma once
#include "MyBinFile.h"

template <typename T>
bool MyBinFile<T>::OpenRead() {			//открыть в режиме чтения
	try {
		this->fin.open(this->nameFile, ios::in | ios::binary);
		if (!this->isOpen()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(100, "Ошибка открытия файла", "Файла нет");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
bool MyBinFile<T>::OpenWrite() {			//открыть в режиме записи
	try {
		this->fout.open(this->nameFile, ios::out | ios::binary);
		if (!this->isOpen()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(100, "Ошибка открытия файла", "Возможно файла нет и/или некорректное название файла");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
bool MyBinFile<T>::OpenAdd() {			//открыть в режиме добавить
	try {
		this->fout.open(this->nameFile, ios::out | ios::app | ios::binary);
		if (!this->isOpen()) 			//если файл не открылся/файла нет
			throw MyExceptionFILE(100, "Ошибка открытия файла", "Возможно файла нет и/или некорректное название файла");
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
		return false;
	}
	return true;
};

template <typename T>
void MyBinFile<T>::Write(T& inform) {		//записать
	try {
		if (!this->fout.is_open() && this->fin.is_open())		//если режмм чтения
			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете записать в файл в режиме чтения");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме записи");
		this->fout.write((char*)&inform, sizeof(T));
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();			//вывод ошибки
	}
};

template <typename T>
void MyBinFile<T>::Read(T& inform) {		//прочитать
	try {
		if (this->fout.is_open() && !this->fin.is_open())				//если не тот режим
			throw MyExceptionFILE(-100, "Неверный режим", "Вы пытаете прочить из файла в режиме записи");
		if (!this->isOpen())
			throw MyExceptionFILE(-101, "Файл закрыт", "Откройте файл в режиме чтения");
		this->fin.read((char*)&inform, sizeof(T));		//чтение
		
	}
	catch (MyExceptionFILE ErrFile) {
		ErrFile.what();				//вывод ошибки
	}
};