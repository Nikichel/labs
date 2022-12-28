#pragma once
#include "Queue.h"

template <typename T>
void queue<T>::headTable() {
	T obj;
	obj.head();			//����� ����� ������� 
}

template <typename T>
void queue<T>::put(T value) {			//�������� �������
	node<T>* newq = new node<T>;
	newq->inform = value;
	newq->nx = newq->pr = nullptr;				//���������� ������ ��������
	if (head && tail) {				//���� ������� ����
		newq->nx = tail;
		newq->pr = nullptr;
		tail->pr = newq;
		tail = newq;				//������� ������� � �����
	}
	else {				//���� ������� ���
		head = tail = newq;
		head->nx = tail->nx = nullptr;
		head->pr = tail->pr = nullptr;				//������ = ����� = �������
	}
	this->size++;
}

template <typename T>
void queue<T>::show() {			//����� �� ����� ������� � ������
	if (!isEmpty()) {
		node<T>* tmpq = tail;
		do {
			cout << tmpq->inform << endl;				//����� ����������
			tmpq = tmpq->nx;
		} while (tmpq);
	}
}

template <typename T>
void queue<T>::del() {				//������� � ������
	if (isEmpty())
		throw MyException(-5, "������� �����");
	if (!isEmpty()) {
		if (tail == head) {				//���� 1 �������
			delete head;				//�������
			head = tail = nullptr;
		}
		else {
			node<T>* tmphead = head->pr;
			delete head;
			tmphead->nx = nullptr;
			head = tmphead;					//������� ������ � ����������� �� ���������� �� �������
		}
		size--;
	}
}

template <typename T>
void queue<T>::del(T& value) {			//������� � ����������� ��������
	if (isEmpty())
		throw MyException(-5, "������� �����");
	if (!isEmpty()) {
		if (tail == head) {					//���� 1 �������
			value = head->inform;			//��������� �������
			delete head;
			head = tail = nullptr;				//������� �������
		}
		else {
			node<T>* tmphead = head->pr;
			value = head->inform;				//��������� �������
			delete head;
			tmphead->nx = nullptr;
			head = tmphead; // ������� ������ � ����������� �� ���������� �� �������
		}
		size--;
	}
}

template <typename T>
void queue<T>::del_any(queue<T> other) {		//������� �� ������� �������
	if (isEmpty())
		throw MyException(-5, "������� �����");
	node<T>* tmp = tail;
	node<T>* del = other.tail;
	for (del; del; del = del->nx) {			//���� �� ��������� ������� ������� ����� �������
		for (tmp = this->tail; tmp; tmp = tmp->nx) {			//���� �� �������� �������
			if (tmp->inform == del->inform) {
				if (tail == head) {				//���� ������� ������=�����
					delete head;
					head = tail = nullptr;
					tmp = nullptr;
					this->size--;
					break;
				}
				else if (tmp == tail) {			//������� �����
					tail = tail->nx;
					delete tmp;
					tail->pr = nullptr;
					tmp = tail;
				}
				else if (tmp == head) {			//������� ������
					head = head->pr;
					delete tmp;
					head->nx = nullptr;
					tmp = head;
				}
				else {							//������� ������ �������
					node<T>* tmpdel = tmp;
					tmp->pr->nx = tmp->nx;
					tmp->nx->pr = tmp->pr;
					tmp = tmp->nx;
					delete tmpdel;
				}
				this->size--;			//��������� ������
			}
		}
	}
}


template <typename T>
bool queue<T>::isEmpty() {			//����� �� �������
	if (size)
		return false;
	return true;
}

template <typename T>
queue<T> queue<T>::search(T obj) {					//�����
	queue<T> rez;				//�������������� �������
	node<T>* tmp = tail;
	while (tmp) {				//���� �� ����� �������
		if (tmp->inform == obj)					//���� ������� ������
			rez.put(tmp->inform);				//�������� � �������������� �������
		tmp = tmp->nx;
	}
	return rez;
}

template <typename T>
queue<T> queue<T>::operator=(const queue<T>& other) {					//������� =
	while (this->size) {
		this->del();			//�������� ������ ����������
	}
	node<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//��������� � ������� ��������� 
	}
	return *this;
}

template <typename T>
queue<T> queue<T>::operator+(const queue<T>& other) {				//�������� +
	node<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//��������� ��������� � �������
	}
	return *this;
}