#pragma once
#include "MyException.h"
#include "MyExceptionDATE.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"
#include "windows.h"

using namespace std;
class checking			//����� ��������
{
public:
	template <typename T>
	void getNum(T& value);			//���� � �������� �����

	template <typename T1, typename T2, typename T3 >
	void getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder);			//���� � �������� ����� � ��������

	template <typename T>
	void getPositivNum(T& value);			//���� �������������� �����
	
	void getRuStr(char* str, int len);		//���� ������� ������
	void getEngStr(char* str, int len);		//���� ���������� ������


	void getDate(int& dd, int& mm, int& yyyy);				//���� ����
};

