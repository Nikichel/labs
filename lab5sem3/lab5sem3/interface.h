#pragma once
#include "checking.h"
#include "Business.h"
#include "Queue.cpp"
#include "checking.h"
//#include "Myfile.cpp"

using namespace std;

class myInterface {
	checking exc;			//����� ��������
public:
	myInterface() {};
	
	~myInterface() {};

	void menu();			//������� ����

	template <typename T>
	void menu_add(queue<T>& q);		//���� ��������

	template <typename T>
	void menu_del(queue<T>& q);			//���� �������

	template <typename T>
	void menuq(queue<T>& q);		//����
};