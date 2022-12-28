#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

using namespace std;

template <typename T>
class queue {

	node<T>* head;
	node<T>* tail;
	int size;

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
		node<T>* tmp = other.head;
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

	node<T>* getHead() {
		return head;
	};

	node<T>* getTail(){
		return tail;
	};

	void put(T value);			//�������� � �������

	void show();			//����� �������

	void del();				//������� � ������
	void del(T& value);			//������� � ����������� ��������
	void del_any(queue<T> other);

	bool isEmpty();			//����� �� �������

	queue<T> search(T obj);				//�����
	queue<T> operator=(const queue<T>& other);			//�������� =
	queue<T> operator+(const queue<T>& other);			//������� +

	void headTable();
};