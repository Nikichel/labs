#include "MyFile.h"

//template <typename T>
//void MyFile<T>::fileClose() {				//�������
//	try {
//		if (_outFile.is_open())
//			_outFile.close();
//		if (_inFile.is_open())
//			_inFile.close();				//������� �������� ����
//		if (_outFile.is_open() || _inFile.is_open()) {			//���� �� ��������
//			throw MyExceptionFILE(101, "������ �������� �����", "���� ���������");
//		}
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();			//����� ������
//	}
//};
//
//template <typename T>
//void MyFile<T>::fileWrite(T& inform) {		//��������
//	try {
//		if (!_outFile.is_open() && _inFile.is_open())		//���� ����� ������
//			throw MyExceptionFILE(-100, "�������� �����", "�� ������� �������� � ���� � ������ ������");
//		if (!isOpen())
//			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
//		_outFile << endl;
//		_outFile << inform;			//������
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();			//����� ������
//	}
//};
//
//template <typename T>
//void MyFile<T>::fileRead(T& inform) {		//���������
//	try {
//		if (!_outFile.is_open() && _inFile.is_open())				//���� �� ��� �����
//			throw MyExceptionFILE(-100, "�������� �����", "�� ������� ������� �� ����� � ������ ������");
//		if (!isOpen())
//			throw MyExceptionFILE(-101, "���� ������", "�������� ���� � ������ ������");
//		_outFile >> inform;			//������
//	}
//	catch (MyExceptionFILE ErrFile) {
//		ErrFile.what();				//����� ������
//	}
//};
//
//template <typename T>
//void MyFile<T>::remote() {					//� ������ �����
//	if (_outFile.is_open())
//		_outFile.seekp(0, ios::beg);		//����������� ��������� � ������
//};
//
//template <typename T>
//bool MyFile<T>::isEnd() {					//�����?
//	if (_inFile.eof() && _inFile.is_open() || _outFile.eof() && _outFile.is_open())
//		return true;			//�� �����
//	else
//		return false;		//��� 
//};
//
//template <typename T>
//bool MyFile<T>::isOpen() {
//	if (_inFile.is_open() || _outFile.is_open())
//		return true;
//	return false;
//}