#pragma once
#include <iostream>
#include "class.h"
using namespace std;


void menu(int& ch);
void input_unsignet_int(int& num);			//���� �������������� �����
void give_mem(Array** ars, int count);			//��������� ������
void input_arrays(Array* ars, int count);				//���� ��������
void show_arrays(Array* ars, int count);			//����� ��������
void cross_two(Array* ars, int count);				//����������� ���� ��������
void cross_all(Array* ars, int count);				//����������� ���� ��������
