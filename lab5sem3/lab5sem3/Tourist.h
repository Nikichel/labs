#pragma once
#include "Human.h"
#include "Struct.h"

class Tourist : public virtual Human
{
protected:
	int num_passport;			//номер паспорта
	cross broad_cross[count_ms];		//пересечение границы

public:
	Tourist() : Human() {			//по умолчанию
		/*cout << "Tourist" << endl;*/
		this->num_passport = 0;
	}

	Tourist(int day, int month, int year, const char* surname, const char* name, const char* midname,
		int num_passport, cross broad_cross[5])
		: Human(day, month, year, surname, name, midname)			//с параметрами
	{
		cout << "Tourist" << endl;
		this->num_passport = num_passport;
		for (int i = 0; i < count_ms; i++) {
			this->broad_cross[i] = broad_cross[i];
		}
	}

	Tourist(const Tourist& other) : Human(other)			//копирования
	{
		//cout << "Tourist" << endl;
		this->num_passport = other.num_passport;
		for (int i = 0; i < count_ms; i++)
			this->broad_cross[i] = other.broad_cross[i];
	}

	~Tourist() {}

	Tourist operator=(Tourist& other);			//оператор =

	void setNumPassport(int);			//установить паспорт
	void setBroadCross(cross broadCross[]);			//установить пересечение границы

	void head() override;			//шапка таблицы

	void change();		//изменить данные
	void filter();		//ввод  полей для поиска

	int getNumPassport();			//получить номер паспорта
	cross* getBroadCross();			//получить пересечения границы

	bool operator==(Tourist& other);			//оператор сравнения

	void addBroadCross(const char* country, Date date);			//добавить пересечение границы

	friend ostream& operator<<(ostream& out, Tourist& other);			//вывод
	friend istream& operator>>(istream& in, Tourist& other);			//ввод
};