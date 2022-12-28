#pragma once
#include "Human.h"
#include "Tourist.h"
#include "Entrepreneur.h"

#include "Struct.h"

class Business :public Tourist, public Entrepreneur			//класс преприниматель
{
	char product[count_ms][20];			//массив товаров
public:
	Business() : Tourist(), Entrepreneur() {				//конструктор по умолчанию
		for (int i = 0; i < count_ms; i++)
			product[i][0] = '\0';
	};

	Business(int day, int month, int year, const char* surname, const char* name, const char* midname, int num_passport, cross broad_cross[5],
		int license, char* country, char* street, int home, tax taxes[5],
		char** product)
		:Tourist(day, month, year, surname, name, midname, num_passport, broad_cross),
		Entrepreneur(day, month, year, surname, name, midname, license, country, street, home, taxes),
		Human(day, month, year, surname, name, midname) {																							//конструктор с параметрами

		for (int i = 0; i < count_ms; i++)
			strcpy_s(this->product[i], 10, product[i]);

	};

	Business(const Business& other) :Tourist(other),					//конструктор копирования
		Entrepreneur(other),
		Human(other) {
		for (int i = 0; i < count_ms; i++)
			strcpy_s(this->product[i], 10, other.product[i]);
	}

	Business operator=(const Business& other);				//obj=obj
	bool operator==(Business& other);					//сравнение

	char** getProducts();							//геттер
	void setProducts(char** products);				//сеттер

	void addProduct(const char* product);			//добавить

	void head() override;			//шапка

	void change();
	 
	friend ostream& operator<<(ostream& out, Business& other);			//вывод 
	friend istream& operator>>(istream& in, Business& other);			//ввод
};	