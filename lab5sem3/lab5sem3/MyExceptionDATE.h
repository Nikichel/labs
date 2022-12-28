#pragma once
#include "MyException.h"

class MyExceptionDATE : public MyException {			//ошибка даты
protected:
	int errNum;		// ошибочное число
public:
	MyExceptionDATE() : MyException() {				//по умолчанию
		errNum = 0;
	}

	MyExceptionDATE(int code, const char* message, int errNum) : MyException(code,message) {		//с параметрами
		this->errNum = errNum;
	}

	MyExceptionDATE(const MyExceptionDATE& other) : MyException(other) {		//копирования
		this->errNum = other.errNum;
	}

	~MyExceptionDATE() {}
		
	void what() override {			//вывод ошибки
		cout << "Код ошибки: " << code << endl;
		cout << "Пояснение: " << message << endl;
		cout << "Вы ввели: " << errNum;
	}
};