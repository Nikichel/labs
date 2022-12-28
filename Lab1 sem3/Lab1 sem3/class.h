#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Array {
private:
	int length;			//длина
	int* ms;		//массив
	bool rep_num(int num, int pos);			//повтор. знач.
	void correct_cin(int& num);				//правильный ввод
public:
	Array() {			//конструктор по умолчанию
		length = 0;
		ms = NULL;
	};			
	Array(int length) {			//конструктор с параметрами
		this->length = length;			//запись длины
		ms = new int[this->length];			//выделение памяти
		for (int i = 0; i < this->length; i++)
			ms[i] = 0;			//инициализация
	};			
	Array(const Array& other) {				//конструктор копирования
		this->length = other.length;		//копирование длины
		ms = new int[this->length];				//выделение памяти
		for (int i = 0; i < this->length; i++)	
			this->ms[i] = other.ms[i];			//копирование массива
	};			
	~Array() {			//деструктор
		delete[] ms;		//освобождение памяти
	};				
	
	

	void setSize(int length);			//установить длину
	int getSize();			//получить длину
	void show();			//вывод массива
	void input();			//ввож массива
	Array operator& (const Array& other);			//пересечение массивов
	void operator=(const Array& other);			//оператор =
	void cut(int new_size);				//усечение массива
};