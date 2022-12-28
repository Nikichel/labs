#pragma once
#include "checking.h"
#include "Business.h"
#include "Queue.cpp"
#include "checking.h"
#include "Human.h"
#include "MyTextFile.cpp"
#include "MyBinFile.cpp"
using namespace std;

class myInterface {
	checking exc;			//����� ��������

	template <typename T>
	void menu_add(queue<T>& q);		//���� ��������

	template <typename T>
	void menu_del(queue<T>& q);			//���� �������

	template <typename T>
	void menuq(queue<T>& q);		//����

	template <typename T>
	void saveInFile(queue<T>& q);

	template <typename T>
	void loadFromFile(queue<T>& q);
public:
	myInterface() {};
	
	~myInterface() {};

	void menu();
};