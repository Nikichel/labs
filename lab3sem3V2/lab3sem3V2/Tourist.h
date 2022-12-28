#pragma once
#include "Human.h"

struct cross {
	Date data;;
	char country[10];

	cross() {
		data = { 0,0,0 };
		country[0] = '\0';
	}

	cross operator= (const cross& other) {
		this->data = other.data;
		strcpy_s(this->country, 10, other.country);
		return *this;
	}
};

class Tourist : public virtual Human
{
protected:
	int num_passport;
	cross broad_cross[count_ms];

public:
	Tourist() : Human() {
		/*cout << "Tourist" << endl;*/
		this->num_passport = 0;
	}

	Tourist(int day, int month, int year, const char* surname, const char* name, const char* midname, 
		int num_passport, cross broad_cross[5])
		: Human(day, month, year, surname, name, midname)
	{
		cout << "Tourist" << endl;
		this->num_passport = num_passport;
		for (int i = 0; i < count_ms; i++) {
			this->broad_cross[i] = broad_cross[i];
		}
	}

	Tourist(const Tourist& other) : Human(other)
	{
		//cout << "Tourist" << endl;
		this->num_passport = other.num_passport;
		for (int i = 0; i < count_ms; i++)
			this->broad_cross[i] = other.broad_cross[i];
	}

	~Tourist() {}

	Tourist operator=(const Tourist& other);

	void setNumPassport(int);
	void setBroadCross(cross broadCross[]);

	void head() override;

	int getNumPassport();
	cross* getBroadCross();

	void addBroadCross(const char* country, Date date);

	friend ostream& operator<<(ostream& out, Tourist& other);
	friend istream& operator>>(istream& in, Tourist& other);

};