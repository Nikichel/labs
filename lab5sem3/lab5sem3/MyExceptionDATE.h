#pragma once
#include "MyException.h"

class MyExceptionDATE : public MyException {			//������ ����
protected:
	int errNum;		// ��������� �����
public:
	MyExceptionDATE() : MyException() {				//�� ���������
		errNum = 0;
	}

	MyExceptionDATE(int code, const char* message, int errNum) : MyException(code,message) {		//� �����������
		this->errNum = errNum;
	}

	MyExceptionDATE(const MyExceptionDATE& other) : MyException(other) {		//�����������
		this->errNum = other.errNum;
	}

	~MyExceptionDATE() {}
		
	void what() override {			//����� ������
		cout << "��� ������: " << code << endl;
		cout << "���������: " << message << endl;
		cout << "�� �����: " << errNum;
	}
};