#include "checking.h"

template <typename T>
void checking::getNum(T& value) {				//проверка числа
	bool fl = true;
	do {
		fl = true;
		try {
			cin >> value;
			cin.ignore(80, '\n');				//наличие лишних символов
			if (cin.fail())						//введенно не число - символ
				throw MyExceptionNUM(1, "Введенно не число", "Вместо числа вы ввели символ");
			else if (cin.gcount() > 1)			//есть лишние символы в записи числа 
				throw MyExceptionNUM(2, "В записи числа присутсвуют сторонние символы" , "Введите число без символов!");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();						//вывод оишбки
			cin.clear();
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}

template < typename T1, typename T2, typename T3 >
void checking::getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder) {			//проверка числа в границах
	double tmp;
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(tmp);					//ввод числа
			value = static_cast<T1> (tmp);			//для проверки на целое
			if (tmp < FirstBorder || tmp > SecondBorder)			//выход за границы
				throw MyExceptionNUM(3, "Выход за границы", "Введите число меньше/больше");
			if (value - tmp)										//если введенное число - int а ввели double
				throw MyExceptionNUM(-3, "Ожидался ввод целого типа", "Вы ввели число типа double");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();				//вывод ошибки
			cin.clear();	
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}


template <typename T>
void checking::getPositivNum(T& value) {				//ввод неотрицательного числа
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(value);			//ввод числа
			if (value <= 0)			//если неположительное
				throw MyExceptionNUM(4, "Введенно неположительное число", "Введите число больше 0");
		}
		catch (MyExceptionNUM errNum) {
			errNum.what();				//вывод ошибки
			rewind(stdin);
			fl = false;
		}

	} while (!fl);
}

void checking::getRuStr(char* str, int len) {
	rewind(stdin);
	bool fl = true;
	int i = 0;
	do {
		fl = true;
		try {
			cin.getline(str, len);				//ввод строки
			if (!strlen(str))			//если пустая строка
				throw MyException(12, "Строка пустая");
			while (str[i] != '\0') {
				if ((str[i] > 'я' || str[i] < 'А') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//проверка символов
					throw MyExceptionSTR(10, "Некорректный русский ввод", str[i], i);
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();				//вывод ошибки
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException err) {
			err.what();					//вывод ошибки
			rewind(stdin);
			i = 0;
			fl = false;
		}
	} while (!fl);
};

void checking::getEngStr(char* str, int len) {
	rewind(stdin);
	bool fl = true;
	int i = 0;
	do {
		fl = true;
		try {
			cin.getline(str, len);				//ввод строки
			if (!strlen(str))			//если пустая строка
				throw MyException(12, "Строка пустая");
			while (str[i] != '\0') {
					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//проверка символов
						throw MyExceptionSTR(11, "Некорректный english ввод", str[i], i);
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();				//вывод ошибки
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException err) {
			err.what();					//вывод ошибки
			rewind(stdin);
			i = 0;
			fl = false;
		}
	} while (!fl);
};

//void checking::getStr(const char* language, char* str, int len) {				//проверка ввода строки
//	rewind(stdin);
//	bool fl = true;
//	int i = 0;
//	do {
//		fl = true;
//		try {
//			cin.getline(str, len);				//ввод строки
//			if (!strlen(str))			//если пустая строка
//				throw MyException(12, "Строка пустая");
//			while (str[i] != '\0') {
//				if (!strcmp(language, "RU"))			//если русская строка
//					if ((str[i] > 'я' || str[i] < 'А') && str[i] != ' ' && str[i] !='-'&& str[i] !='.')			//проверка символов
//						throw MyExceptionSTR(10, "Некорректный русский ввод", str[i], i);
//				if (!strcmp(language, "ENG"))			//если английская
//					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//проверка символов
//						throw MyExceptionSTR(11, "Некорректный english ввод", str[i], i);
//				i++;
//			}
//		}
//		catch (MyExceptionSTR errStr) {
//			errStr.what();				//вывод ошибки
//			rewind(stdin);
//			i = 0;
//			fl = false;
//		}
//		catch (MyException err) {
//			err.what();					//вывод ошибки
//			rewind(stdin);
//			i = 0;
//			fl = false;
//		}
//	} while (!fl);
//}

void checking::getDate(int& dd, int& mm, int& yyyy) {				//проверка и ввод даты
	cout << "Год:";
	getPositivNum(yyyy);			//ввод года
	cout << "Месяц: ";
	getNumWithBorders(mm, 1, 12);			//вод месяца
	cout << "День:";
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)	
		getNumWithBorders(dd, 1, 31);
	else if (mm == 2 && yyyy % 4 == 0)			//високосный год
		getNumWithBorders(dd, 1, 29);
	else if (mm == 2)
		getNumWithBorders(dd, 1, 28);
	else
		getNumWithBorders(dd, 1, 30);			//ввод дня
}