#include "funs.h"
#include "class.h"

void menu(int& ch) {			//функция меню
	cout << "1-создать массив(ы)" << endl;
	cout << "2-заполнить массив(ы)" << endl;
	cout << "3-вывести массивы на экран" << endl;
	cout << "4-найти персечение двух массивов" << endl;
	cout << "5-найти пересечение всех массивов" << endl;
	cout << "6-выход их программы" << endl;
	do {
		rewind(stdin);
		input_unsignet_int(ch);			//ввод и проверка числа
		if (ch < 0 || ch>6)
			cout << "Такого пункта нет! Повторите ввод" << endl;
	} while (ch < 0 || ch>6);
}

void input_unsignet_int(int& num) {			//ввод и проверка положительного числа
	while (1) {
		if ((cin >> num).good() && num > 0) {
			return;
		}
		if (cin.fail() || num <= 0) {				//ввод и проверка числа
			rewind(stdin);
			cin.clear();
			cout << "Неверный ввод" << endl;
		}
	}
}

void give_mem(Array** ars, int count) {			//выделение памяти для массива массивов
	if ((*ars) != NULL)
		delete[](*ars);				//очистка старой
	*ars = new Array[count];		//выделение памяти
}

void input_arrays(Array* ars, int count) {			//заполнение массивов
	for (int i = 0; i < count; i++) {			//цикл по элементам массива масивов
		cout << "Ar" << i << endl;
		if (ars[i].getSize() == 0) {
			int len=0;
			cout << "Введите длину массива: ";
			input_unsignet_int(len);
			ars[i].setSize(len);
		}
		ars[i].input();				//ввод значений в массив
	}
}

void show_arrays(Array* ars, int count) {			//вывод массивов на экран
	for (int i = 0; i < count; i++) {			//цикл по массивам
		cout << "\nAr" << i << ": ";
		ars[i].show();			//вывод массива
	}
}

void cross_two(Array* ars, int count) {				//пересечение двух массивов
	int num1, num2;					
	num1 = num2 = 0;
	cout << "Введите номерa массивов для которых найти пересечение: ";
	for (int i = 0; i < count; i++)
		cout << i + 1 << "\t";			//вывод номеров массивов
	cout << "\n";
	do {
		input_unsignet_int(num1);
		input_unsignet_int(num2);			//выбор масивов для нахождения пересечения
		if ((num1 - 1) >= count || (num2 - 1) >= count)
			cout << "Вы ввели номер несуществующего массива. Повторите попытку" << endl;
	} while ((num1 - 1) >= count || (num2 - 1) >= count);
	cout << "Ar" << num1 - 1 << ": ";
	ars[num1 - 1].show();			//вывод первого массива
	cout << "Ar" << num2 - 1 << ": ";
	ars[num2 - 1].show();			//вывод второго массива
	Array cross_arr= ars[num1 - 1] & (ars[num2 - 1]);			//нахождение пересечения
	cout << "Пересечение Ar" << num1 - 1 << " и Ar" << num2 - 1 << ": ";
	if (cross_arr.getSize())
		cross_arr.show();			//вывод пересечения
	else
		cout << "Пересечения нет" << endl;
}

void cross_all(Array* ars, int count) {				//пересечение всех  массивов
	Array cross_arr(ars[0]);
	for (int i = 1; i < count; i++) {
		cross_arr = cross_arr & (ars[i]);			//пересечение всех массивов
	}
	show_arrays(ars, count);			//вывод массивов 
	cout << "\nПересечение всех массивов: " ;
	if (cross_arr.getSize())
		cross_arr.show();			//вывод пересечения
	else
		cout << "Пересечения нет" << endl;
}