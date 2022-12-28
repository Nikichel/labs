#pragma once
#include <iostream>
#include "class.h"
using namespace std;


void menu(int& ch);
void input_unsignet_int(int& num);			//ввод положительного числа
void give_mem(Array** ars, int count);			//выделение памяти
void input_arrays(Array* ars, int count);				//ввод массивов
void show_arrays(Array* ars, int count);			//вывод массивов
void cross_two(Array* ars, int count);				//пересечение двух массивов
void cross_all(Array* ars, int count);				//пересечение всех массивов
