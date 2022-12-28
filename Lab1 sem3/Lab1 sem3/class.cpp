#include "class.h"


void Array::setSize(int length) {			//установить длину
	this->length = length;			//запись длины
	if (ms!=NULL) 
		delete[] ms;			//удаление старой информации
	ms = new int[this->length];			//выделение пам€ти
	for (int i = 0; i < this->length; i++) {
		ms[i] = 0;			//инициализаци€
	}
}
int Array::getSize() {			//получить длину
	return length;
}

void Array::show() {			//вывод массива
	if (ms == NULL) {
		cout << "ћассива нет!"<<endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		cout<<setw(3)<< ms[i] ;			//вывод массива
	}
	cout << endl;
}

bool Array::rep_num(int num, int pos) {				//повторение чисел
	for (int i = 0; i < pos; i++) {
		if (ms[i] == num) {				//если есть повторение
			return true;
		}
	}
	return false;			//если нет
}

void Array::correct_cin(int& num) {				//правильный ввод
	do {
		cin.clear();
		cin >> num;
		if (cin.fail()) {			//неправильный ввод
			rewind(stdin);			//очистка 
			cout << "ќшибка ввода!" << endl;
		}
	} while (cin.fail());
}

void Array::input() {			//ввод массива
	if (ms == NULL) {
		cout << "ћассива нет!" << endl;
		return;
	}
	int num=0;
	for (int i = 0; i < length; i++) {
		cout << "[" << i << "]: ";
		correct_cin(num);		//проверка ввода
		if (rep_num(num,i)) {			//повтор числа
			i--;
			cout << "„исло уже есть!" << endl;
		}
		else {
			ms[i] = num;			//запись числа
		}
	}
	rewind(stdin);
}

void Array::cut(int new_size) {				//усечение длины
	Array tmp(*this);		//копирование исх. массива
	delete[] ms;		//удаление
	length = new_size;			//нова€ длина
	ms = new int[length];		//выделение пам€ти
	for (int i = 0; i < length; i++)	
		ms[i] = tmp.ms[i];				//копирование 
}

Array Array::operator& (const Array& other) {			//пересечение 2-ух массивов
	Array cross_arr(length);			//массив пересечени€
	int i1, i2, i3;
	i1 = i2 = i3 = 0;
	for (i1; i1 < this->length; i1++) {			//цикл по 1 массиву
		i2 = 0;
			for (i2; i2 < other.length; i2++)			//цикл по 2-му
				if (this->ms[i1] == other.ms[i2] && i3 < cross_arr.length)			//есть пересечение
					cross_arr.ms[i3++] = this->ms[i1];
	}
	cross_arr.cut(i3);			//усечение длины
	return cross_arr;
}

void Array::operator=(const Array& other) {			//оператор =
	delete[] ms;		//удаление 
	this->length = other.length;		//запись длины
	ms = new int[this->length];		//выделение пам€ти
	for (int i = 0; i < this->length; i++)	
		this->ms[i] = other.ms[i];			//запись чисел
}