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
	queue() {			//по умолчанию
		head = tail = nullptr;
		size = 0;
	}

	queue(T* arr, int count) {			//с параметрами
		head = tail = nullptr;
		for (int i = 0; i < count; i++)
			put(arr[i]);			//добавление элемента
		size = count;
	}

	queue(const queue<T>& other) {				//копирования
		//cout << "КОНСТР" << endl;
		this->size = 0;
		head = tail = nullptr;
		node<T>* tmp = other.head;
		while (tmp) {
			this->put(tmp->inform);
			tmp = tmp->pr;				//копирование данных
		}

	}

	~queue() {				//деструктор
		if (!isEmpty()) {		//если не пусто
			do {
				del();				//удаление элементов
			} while (head && tail);				//пока не пусто
		}
		head = tail = nullptr;
	}

	node<T>* getHead() {
		return head;
	};

	node<T>* getTail(){
		return tail;
	};

	void put(T value);			//добавить в очередь

	void show();			//вывод очереди

	void del();				//удалить с головы
	void del(T& value);			//удалить с сохранением элемента
	void del_any(queue<T> other);

	bool isEmpty();			//пуста ли очередь

	queue<T> search(T obj);				//поиск
	queue<T> operator=(const queue<T>& other);			//оператор =
	queue<T> operator+(const queue<T>& other);			//опертор +

	void headTable();
};