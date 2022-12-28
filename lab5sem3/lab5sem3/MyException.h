#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class MyException {
protected:
	int code;		//���
	char message[80];		//������
public:
	MyException() {		//���������
		code = 0;
		message[0] = '\0';
	}

	MyException(int code, const char* message) {		//� �����������
		this->code = code;
		strcpy_s(this->message, 80, message);
	}
		
	MyException(const MyException& other){		//�����������
		this->code = other.code;
		strcpy_s(this->message, 80, other.message);
	}

	~MyException() {}

	virtual void what() {			//����� ������
		cout << "��� ������: " << code << endl;			//���
		cout << "���������: " << message << endl;			//���������
	};
};