#pragma once
#include "Human.h"
#include "Tourist.h"
#include "Entrepreneur.h"

class Business :public Tourist, public Entrepreneur
{
	char product[count_ms][10];
public:
	Business() : Tourist(), Entrepreneur() {
		for (int i = 0; i < count_ms; i++)
			product[i][0] = '\0';
	};

	Business(int day, int month, int year, const char* surname, const char* name, const char* midname, int num_passport, cross broad_cross[5],
		int license, char* country, char* street, int home, tax taxes[5],
		char** product)
		:Tourist(day, month, year,surname, name, midname, num_passport, broad_cross),
		Entrepreneur(day, month, year, surname, name, midname, license, country, street, home, taxes),
		Human(day, month, year, surname, name, midname) {

		for (int i = 0; i < count_ms; i++)
			strcpy_s(this->product[i], 10, product[i]);

	};

	Business(const Business& other) :Tourist(other),
		Entrepreneur(other),
		Human(other) {
		for (int i = 0; i < count_ms; i++)
			strcpy_s(this->product[i], 10, other.product[i]);
	}

	Business operator=(const Business& other);

	char** getProducts();
	void setProducts(char** products);

	void addProduct(const char* product);

	void head() override;

	friend ostream& operator<<(ostream& out, Business& other);
	friend istream& operator>>(istream& in, Business& other);
};