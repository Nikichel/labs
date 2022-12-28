#pragma once
#include "Human.h"
#include "Struct.h"


class Entrepreneur : public virtual Human
{
protected:
	int license;				//номер лицензии
	addres addresLicense;		//адрес
	tax taxes[count_ms];		//налоги

public:
	Entrepreneur() : Human() {			//по умолчанию
		/*cout << "Entrepreneur" << endl;*/
		this->license = 0;
	}

	Entrepreneur(int day, int month, int year, const char* surname, const char* name, const char* midname, int license, char* country, char* street, int home, tax taxes[5])
		: Human(day, month, year, surname, name, midname)			//с параметрами
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

	Entrepreneur(const Entrepreneur& other) : Human(other)			//копирвания
	{
		//cout << "Entrepreneur" << endl;
		this->license = other.license;
		strcpy_s(this->addresLicense.city, 10, other.addresLicense.city);
		strcpy_s(this->addresLicense.street, 10, other.addresLicense.street);
		this->addresLicense.home = other.addresLicense.home;
		for (int i = 0; i < count_ms; i++)
			this->taxes[i] = other.taxes[i];			//копирование данных
	}

	~Entrepreneur() {

	}

	void setLicense(int);			//установить лицензию
	void setAddres(const char* country, const char* street, const int home);		//установить адресс
	void setTaxes(tax taxes[]);			//установить налоги
	int getLicense();			//получить лицензию
	addres getAddres();			//получить адресс
	tax* getTaxes();			//получить налог
	void addTax(Date date, int summa);			//добавить налог

	bool operator==(Entrepreneur& other);			//оператор сравнения

	void head() override;			//шапка таблицы

	void change();		//изменить данные
	void filter();		//ввод  полей для поиска

	Entrepreneur operator=(const Entrepreneur& other);			//присваивание

	friend ostream& operator<<(ostream& out, Entrepreneur& other);			//вывод
	friend istream& operator>>(istream&, Entrepreneur&);			//ввод
};