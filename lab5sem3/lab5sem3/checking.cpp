#include "checking.h"

template <typename T>
void checking::getNum(T& value) {				//�������� �����
	bool fl = true;
	do {
		fl = true;
		try {
			cin >> value;
			cin.ignore(80, '\n');				//������� ������ ��������
			if (cin.fail())						//�������� �� ����� - ������
				throw MyExceptionNUM(1, "�������� �� �����", "������ ����� �� ����� ������");
			else if (cin.gcount() > 1)			//���� ������ ������� � ������ ����� 
				throw MyExceptionNUM(2, "� ������ ����� ����������� ��������� �������" , "������� ����� ��� ��������!");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();						//����� ������
			cin.clear();
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}

template < typename T1, typename T2, typename T3 >
void checking::getNumWithBorders(T1& value, T2 FirstBorder, T3 SecondBorder) {			//�������� ����� � ��������
	double tmp;
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(tmp);					//���� �����
			value = static_cast<T1> (tmp);			//��� �������� �� �����
			if (tmp < FirstBorder || tmp > SecondBorder)			//����� �� �������
				throw MyExceptionNUM(3, "����� �� �������", "������� ����� ������/������");
			if (value - tmp)										//���� ��������� ����� - int � ����� double
				throw MyExceptionNUM(-3, "�������� ���� ������ ����", "�� ����� ����� ���� double");
		}
		catch (MyExceptionNUM errNUM) {
			errNUM.what();				//����� ������
			cin.clear();	
			rewind(stdin);
			fl = false;
		}
	} while (!fl);
}


template <typename T>
void checking::getPositivNum(T& value) {				//���� ���������������� �����
	bool fl = true;
	do {
		fl = true;
		try {
			getNum(value);			//���� �����
			if (value <= 0)			//���� ���������������
				throw MyExceptionNUM(4, "�������� ��������������� �����", "������� ����� ������ 0");
		}
		catch (MyExceptionNUM errNum) {
			errNum.what();				//����� ������
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
			cin.getline(str, len);				//���� ������
			if (!strlen(str))			//���� ������ ������
				throw MyException(12, "������ ������");
			while (str[i] != '\0') {
				if ((str[i] > '�' || str[i] < '�') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//�������� ��������
					throw MyExceptionSTR(10, "������������ ������� ����", str[i], i);
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();				//����� ������
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException err) {
			err.what();					//����� ������
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
			cin.getline(str, len);				//���� ������
			if (!strlen(str))			//���� ������ ������
				throw MyException(12, "������ ������");
			while (str[i] != '\0') {
					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//�������� ��������
						throw MyExceptionSTR(11, "������������ english ����", str[i], i);
				i++;
			}
		}
		catch (MyExceptionSTR errStr) {
			errStr.what();				//����� ������
			rewind(stdin);
			i = 0;
			fl = false;
		}
		catch (MyException err) {
			err.what();					//����� ������
			rewind(stdin);
			i = 0;
			fl = false;
		}
	} while (!fl);
};

//void checking::getStr(const char* language, char* str, int len) {				//�������� ����� ������
//	rewind(stdin);
//	bool fl = true;
//	int i = 0;
//	do {
//		fl = true;
//		try {
//			cin.getline(str, len);				//���� ������
//			if (!strlen(str))			//���� ������ ������
//				throw MyException(12, "������ ������");
//			while (str[i] != '\0') {
//				if (!strcmp(language, "RU"))			//���� ������� ������
//					if ((str[i] > '�' || str[i] < '�') && str[i] != ' ' && str[i] !='-'&& str[i] !='.')			//�������� ��������
//						throw MyExceptionSTR(10, "������������ ������� ����", str[i], i);
//				if (!strcmp(language, "ENG"))			//���� ����������
//					if ((str[i] < 'A' || str[i]> 'Z' && str[i] < 'a' || str[i]>'z') && str[i] != ' ' && str[i] != '-' && str[i] != '.')			//�������� ��������
//						throw MyExceptionSTR(11, "������������ english ����", str[i], i);
//				i++;
//			}
//		}
//		catch (MyExceptionSTR errStr) {
//			errStr.what();				//����� ������
//			rewind(stdin);
//			i = 0;
//			fl = false;
//		}
//		catch (MyException err) {
//			err.what();					//����� ������
//			rewind(stdin);
//			i = 0;
//			fl = false;
//		}
//	} while (!fl);
//}

void checking::getDate(int& dd, int& mm, int& yyyy) {				//�������� � ���� ����
	cout << "���:";
	getPositivNum(yyyy);			//���� ����
	cout << "�����: ";
	getNumWithBorders(mm, 1, 12);			//��� ������
	cout << "����:";
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)	
		getNumWithBorders(dd, 1, 31);
	else if (mm == 2 && yyyy % 4 == 0)			//���������� ���
		getNumWithBorders(dd, 1, 29);
	else if (mm == 2)
		getNumWithBorders(dd, 1, 28);
	else
		getNumWithBorders(dd, 1, 30);			//���� ���
}