#pragma once
#include "checking.h"
#include "Business.h"
#include "Queue.cpp"
#include "checking.h"
//#include "Myfile.cpp"

using namespace std;

class myInterface {
	checking exc;			//класс проверки
public:
	myInterface() {};
	
	~myInterface() {};

	void menu();			//главное меню

	template <typename T>
	void menu_add(queue<T>& q);		//меню добавить

	template <typename T>
	void menu_del(queue<T>& q);			//меню удалить

	template <typename T>
	void menuq(queue<T>& q);		//меню
};