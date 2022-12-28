#pragma once
#include "Date.h"

struct tax {			//выплата налогов
	Date data;			//дата выплаты
	int summa;			//сумма

	tax() {		//по умолчанию
		data = { 0,0,0 };
		summa = 0;
	}

	tax(const tax& other) {			//копиривания
		this->data = other.data;
		this->summa = other.summa;
	}

	tax operator= (const tax& other) {		//оператор =
		this->data = other.data;
		this->summa = other.summa;
		return *this;
	}
};

struct addres {				//адрес
	char city[10];			//город
	char street[10];		//улица
	int home;				//дом

	addres() {			//по умолчанию
		city[0] = '\0';
		street[0] = '\0';
		home = 0;
	}

	addres(const addres& other) {		//копирования
		this->home = other.home;
		strcpy_s(this->city, 10, other.city);
		strcpy_s(this->street, 10, other.street);
	}

	addres operator=(const addres& other) {			//оператор =
		this->home = other.home;
		strcpy_s(this->city, 10, other.city);
		strcpy_s(this->street, 10, other.street);
		return *this;
	}
};

struct cross {			//пересечение границы
	Date data;			//дата пересечения
	char country[10];	//страна

	cross() {			//по умолчанию
		data = { 0,0,0 };
		strcpy_s(country, 10, "-");
	}

	cross operator= (const cross& other) {			//оператор =
		this->data = other.data;
		strcpy_s(this->country, 10, other.country);
		return *this;
	}
};
