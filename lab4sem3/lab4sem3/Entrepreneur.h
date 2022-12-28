#pragma once
#include "Human.h"
#include "Struct.h"

class Entrepreneur : public virtual Human
{
protected:
	int license;
	addres addresLicense;
	tax taxes[count_ms];

public:
	Entrepreneur() : Human() {
		/*cout << "Entrepreneur" << endl;*/
		this->license = 0;
	}

	Entrepreneur(int day, int month, int year, const char* surname, const char* name, const char* midname, int license, char* country, char* street, int home, tax taxes[5])
		: Human(day, month, year, surname, name, midname)
	{
		//cout << "Entrepreneur" << endl;
		this->license = license;
		strcpy_s(this->addresLicense.city, 10, country);
		strcpy_s(this->addresLicense.street, 10, street);
		this->addresLicense.home = home;
		for (int i = 0; i < count_ms; i++) {
			this->taxes[i] = taxes[i];
		}
	}

	Entrepreneur(const Entrepreneur& other) : Human(other)
	{
		//cout << "Entrepreneur" << endl;
		this->license = other.license;
		strcpy_s(this->addresLicense.city, 10, other.addresLicense.city);
		strcpy_s(this->addresLicense.street, 10, other.addresLicense.street);
		this->addresLicense.home = other.addresLicense.home;
		for (int i = 0; i < count_ms; i++)
			this->taxes[i] = other.taxes[i];
	}

	~Entrepreneur() {

	}

	void setLicense(int);
	void setAddres(const char* country, const char* street, const int home);
	void setTaxes(tax taxes[]);
	int getLicense();
	addres getAddres();
	tax* getTaxes();
	void addTax(Date date, int summa);

	bool operator==(Entrepreneur& other);

	void head() override;

	void change();

	Entrepreneur operator=(const Entrepreneur& other);

	friend ostream& operator<<(ostream& out, Entrepreneur& other);
	friend istream& operator>>(istream&, Entrepreneur&);

};