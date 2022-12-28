#pragma once
#include "MyException.h"
#include "MyExceptionDATE.h"
#include "MyExceptionNUM.h"
#include "MyExceptionSTR.h"
#include "windows.h"

using namespace std;
class checking			//класс проверка
{
public:
	template <typename T>
	void getNum(T& value);			//ввод и проверка числа

	template <typename T1, typename T2, typename T3 >
	void getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder);			//ввод и проверка числа в границах

	template <typename T>
	void getPositivNum(T& value);			//ввод положительного числа
	
	void getRuStr(char* str, int len);		//ввод русской строки
	void getEngStr(char* str, int len);		//ввод английской строки


	void getDate(int& dd, int& mm, int& yyyy);				//ввод даты
};

