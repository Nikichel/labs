#pragma once
#include "Queue.h"

template <typename T>
void queue<T>::headTable() {
	T obj;
	obj.head();			//вывод шапки таблицы 
}

template <typename T>
void queue<T>::put(T value) {			//добавить элемент
	node<T>* newq = new node<T>;
	newq->inform = value;
	newq->nx = newq->pr = nullptr;				//объ€вление нового элемента
	if (head && tail) {				//если очередь есть
		newq->nx = tail;
		newq->pr = nullptr;
		tail->pr = newq;
		tail = newq;				//занести элемент в хвост
	}
	else {				//если очереди нет
		head = tail = newq;
		head->nx = tail->nx = nullptr;
		head->pr = tail->pr = nullptr;				//голова = хвост = элемент
	}
	this->size++;
}

template <typename T>
void queue<T>::show() {			//вывод на экран очереди с хвоста
	if (!isEmpty()) {
		node<T>* tmpq = tail;
		do {
			cout << tmpq->inform << endl;				//вывод информации
			tmpq = tmpq->nx;
		} while (tmpq);
	}
}

template <typename T>
void queue<T>::del() {				//удалить с головы
	if (isEmpty())
		throw MyException(-5, "ќчередь пуста");
	if (!isEmpty()) {
		if (tail == head) {				//если 1 элемент
			delete head;				//удалить
			head = tail = nullptr;
		}
		else {
			node<T>* tmphead = head->pr;
			delete head;
			tmphead->nx = nullptr;
			head = tmphead;					//удалить голову и переместить на предыдущий за головой
		}
		size--;
	}
}

template <typename T>
void queue<T>::del(T& value) {			//удалить с сохранением элемента
	if (isEmpty())
		throw MyException(-5, "ќчередь пуста");
	if (!isEmpty()) {
		if (tail == head) {					//если 1 элемент
			value = head->inform;			//сохранить элемент
			delete head;
			head = tail = nullptr;				//удалить очередь
		}
		else {
			node<T>* tmphead = head->pr;
			value = head->inform;				//сохранить элемент
			delete head;
			tmphead->nx = nullptr;
			head = tmphead; // удалить голову и переместить на предыдущий за головой
		}
		size--;
	}
}

template <typename T>
void queue<T>::del_any(queue<T> other) {		//удалить из очереди очередь
	if (isEmpty())
		throw MyException(-5, "ќчередь пуста");
	node<T>* tmp = tail;
	node<T>* del = other.tail;
	for (del; del; del = del->nx) {			//цикл по элементам очереди которые нужно удалить
		for (tmp = this->tail; tmp; tmp = tmp->nx) {			//цикл по основной очереди
			if (tmp->inform == del->inform) {
				if (tail == head) {				//если удал€ем голову=хвост
					delete head;
					head = tail = nullptr;
					tmp = nullptr;
					this->size--;
					break;
				}
				else if (tmp == tail) {			//удал€ем хвост
					tail = tail->nx;
					delete tmp;
					tail->pr = nullptr;
					tmp = tail;
				}
				else if (tmp == head) {			//удал€ем голову
					head = head->pr;
					delete tmp;
					head->nx = nullptr;
					tmp = head;
				}
				else {							//удал€ем другой элемент
					node<T>* tmpdel = tmp;
					tmp->pr->nx = tmp->nx;
					tmp->nx->pr = tmp->pr;
					tmp = tmp->nx;
					delete tmpdel;
				}
				this->size--;			//уменьшаем размер
			}
		}
	}
}


template <typename T>
bool queue<T>::isEmpty() {			//пуста ли очередь
	if (size)
		return false;
	return true;
}

template <typename T>
queue<T> queue<T>::search(T obj) {					//поиск
	queue<T> rez;				//результирующа€ очередь
	node<T>* tmp = tail;
	while (tmp) {				//пока не конец очереди
		if (tmp->inform == obj)					//если элемент совпал
			rez.put(tmp->inform);				//добавить в результирующую очередь
		tmp = tmp->nx;
	}
	return rez;
}

template <typename T>
queue<T> queue<T>::operator=(const queue<T>& other) {					//опретор =
	while (this->size) {
		this->del();			//удаление старой информации
	}
	node<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//занесение в очередь элементов 
	}
	return *this;
}

template <typename T>
queue<T> queue<T>::operator+(const queue<T>& other) {				//оператор +
	node<T>* tmp = other.head;
	while (tmp) {
		this->put(tmp->inform);
		tmp = tmp->pr;				//занемение элементов в очередь
	}
	return *this;
}