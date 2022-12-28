#pragma once
#include "Queue.h"

template <typename T>
void queue<T>::put(T& value) {			//�������� �������
	nodeQ<T>* newq = new nodeQ<T>;
	newq->inform = value;				//���������� ������ ��������
	if (head && tail) {				//���� ������� ����
		newq->nx = tail;
		tail->pr = newq;
		tail = newq;				//������� ������� � �����
	}
	else {				//���� ������� ���
		head = tail = newq;					//������ = ����� = �������
	}
	this->size++;
}

template <typename T>
void queue<T>::show() {			//����� �� ����� ������� � ������
	if (!isEmpty()) {
		nodeQ<T>* tmpq = tail;
		do {
			cout << tmpq->inform << endl;				//����� ����������
			tmpq = tmpq->nx;
		} while (tmpq);
	}
}

template <typename T>
void queue<T>::del() {				//������� � ������
	try {
		if (!isEmpty()) {
			if (tail == head) {				//���� 1 �������
				delete head;				//�������
				head = tail = nullptr;
			}
			else {
				nodeQ<T>* tmphead = head->pr;
				delete head;
				tmphead->nx = nullptr;
				head = tmphead;					//������� ������ � ����������� �� ���������� �� �������
			}
			size--;
		}
		else
			throw MyException(-20, "������� �����");
	}
	catch (MyException err) {
		err.what();
	}
}

template <typename T>
void queue<T>::del(T del_value) {			//������� �� �������
	nodeQ<T>* tmp = tail;
	if (!isEmpty()) {
		while (tmp) {
			if (tmp->inform == del_value) {
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
					nodeQ<T>* tmpdel = tmp;
					tmp->pr->nx = tmp->nx;
					tmp->nx->pr = tmp->pr;
					tmp = tmp->nx;
					delete tmpdel;
				}
				this->size--;
			}
			tmp = tmp->nx;
		}
	}
}

template <typename T>
void queue<T>::del_any(queue<T> other) {
	try {
		if (isEmpty())
			throw MyException(-5, "������� �����");
		nodeQ<T>* tmp = tail;
		nodeQ<T>* del = other.tail;
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
						nodeQ<T>* tmpdel = tmp;
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
	catch (MyException err) {
		err.what();
	}
}

template <typename T>
void queue<T>::clear() {
	if (!isEmpty()) {		//���� �� �����
		do {
			del();				//�������� ���������
		} while (head && tail);				//���� �� �����
	}
	head = tail = nullptr;
}

template <typename T>
bool queue<T>::isEmpty() {			//����� �� �������
	if (size)
		return false;
	return true;
}

template <typename T>
int queue<T>::getSize() {
	return this->size;
};

template <typename T>
queue<T> queue<T>::operator=(const queue<T>& other) {					//������� =
	while (this->size) {
		this->del();			//�������� ������ ����������
	}
	nodeQ<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//��������� � ������� ��������� 
	}
	return *this;
}

template <typename T>
queue<T> queue<T>::operator+(const queue<T>& other) {				//�������� +
	nodeQ<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//��������� ��������� � �������
	}
	return *this;
}

template <typename T>
void queue<T>::headTable() {
	T obj;
	obj.head();			//����� ����� ������� 
}