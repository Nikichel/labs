#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

#include "MyException.h"
using namespace std;

template <typename T>
class queue {				//�������

	nodeQ<T>* head;		//��������� �� ������
	nodeQ<T>* tail;		//�� �����
	int size;		//���-�� ���������

public:
	queue() {			//�� ���������
		head = tail = nullptr;
		size = 0;
	}

	queue(T* arr, int count) {			//� �����������
		head = tail = nullptr;
		for (int i = 0; i < count; i++)
			put(arr[i]);			//���������� ��������
		size = count;
	}

	queue(const queue<T>& other) {				//�����������
		//cout << "������" << endl;
		this->size = 0;
		head = tail = nullptr;
		nodeQ<T>* tmp = other.head;
		while (tmp) {
			this->put(tmp->inform);
			tmp = tmp->pr;				//����������� ������
		}

	}

	~queue() {				//����������
		if (!isEmpty()) {		//���� �� �����
			do {
				del();				//�������� ���������
			} while (head && tail);				//���� �� �����
		}
		head = tail = nullptr;
	}

	void put(T& value);			//�������� � �������

	void show();			//����� �������

	void del();				//������� � ������
	void del(T del_value);			//������� � ����������� ��������
	void del_any(queue<T> other);
	void clear();

	bool isEmpty();			//����� �� �������
	int getSize();			//���������� ���������

	queue<T> operator=(const queue<T>& other);			//�������� =
	queue<T> operator+(const queue<T>& other);			//������� +

	void headTable();		//����� �������

	class Iterator {			//����� ��������
		nodeQ<T>* curNode;		//�������
		nodeQ<T>* prevNode;		//����������
	public:
		Iterator() {			//����������� �� ���������
			curNode = nullptr;
			prevNode = nullptr;
		}

		Iterator(nodeQ<T>* current, nodeQ<T>* prev = nullptr) {		//�����������
			this->curNode = current;
			this->prevNode = prev;
		}

		T& operator++(int value);		//��������++
		T& operator--(int value);		//��������--
		T& operator*();					//�������� *

		bool operator==(Iterator other);		//�������� ==
		bool operator!=(Iterator other);		//�������� !=
	};

	Iterator Begin();		//�������� �� ������
	Iterator End();			//�������� �� �����
};

template<typename T>
queue<T>::template Iterator queue<T>::Begin() {		//�������� �� ������
	Iterator it(queue<T>::head);
	return it;
}

template<typename T>
queue<T>::template Iterator queue<T>::End() {			//�������� �� �����
	Iterator iter(queue<T>::tail->pr, queue<T>::tail);		//�������� �� ����. �� ���������
	return iter;
}

template<typename T>
T& queue<T>::Iterator::operator++(int value) {		//�������� ++
	try {
		if (curNode) {
			prevNode = curNode;
			curNode = curNode->pr;			//�������� ��������� � ������� ������
			return curNode->inform;
		}
		else
			throw MyException(-15, "����� �� ������� ����������");
	}
	catch (MyException err) {
		err.what();
	}
}

template<typename T>
T& queue<T>::Iterator::operator--(int value) {		//�������� --
	try {
		if (curNode) {
			prevNode = prevNode->nx;
			curNode = curNode->nx;			//�������� ��������� � ������� ������
			return curNode->inform;
		}
		else
			throw MyException(-15, "����� �� ������� ����������");
	}
	catch (MyException err) {
		err.what();
	}
}

template<typename T>
T& queue<T>::Iterator::operator*() {		//�������� *
	return curNode->inform;		//��������� ��������
}

template<typename T>
bool queue<T>::Iterator::operator==(Iterator other) {			//�������� ==
	if (this->curNode != other.curNode || this->prevNode != other.prevNode)		//��������� �����
		return false;
	return true;
}

template<typename T>
bool queue<T>::Iterator::operator!=(Iterator other) {		//�������� !=
	return !(*this == other);
}