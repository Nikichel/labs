#pragma once
#include "MyException.h"
class MyExceptionFILE : public MyException {			//������ �����
protected:
	char message2[80];		//2 ��������� ���������
public:
	MyExceptionFILE() : MyException() {
		message2[0] = '\0';
	}

	MyExceptionFILE(int code, const char* message ,const char* message2) : MyException(code, message) {			//� �����������
		strcpy_s(this->message2, 80, message2);
	}

	MyExceptionFILE(const MyExceptionFILE& other) : MyException(other) {			//�����������
		strcpy_s(message2, 80, other.message2);
	}
	~MyExceptionFILE() {}

	void what() override {		//����� ������
		cout << "��� ������: " << code << endl;
		cout << "���������: " << message << endl;
		cout << message2 << endl;					//����� ������
	}

};

