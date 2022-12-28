#pragma once
#include "MyException.h"

class MyExceptionNUM : public MyException {
protected:
	char message2[80];
public:
	MyExceptionNUM() : MyException() {			//�� ���������
		message2[0] = '\0';
	}

	MyExceptionNUM(int code, const char* message, const char* message2) : MyException(code, message) {			//� �����������
		strcpy_s(this->message2, 80, message2);
	}
	MyExceptionNUM(const MyExceptionNUM& other) : MyException (other) {				//�����������
		strcpy_s(message2, 80, other.message2);
	}

	~MyExceptionNUM() {}

	void what() override {
		cout << "��� ������: " << code << endl;
		cout << "���������: " << message << endl;
		cout << message2 << endl;				//����� ������
	};
};