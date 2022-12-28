#pragma once
#include "Human.h"
#include "Struct.h"

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

	Tourist operator=(Tourist& other);

	void setNumPassport(int);
	void setBroadCross(cross broadCross[]);

	void head() override;

	void change();

	int getNumPassport();
	cross* getBroadCross();

	bool operator==(Tourist& other);

	void addBroadCross(const char* country, Date date);

	friend ostream& operator<<(ostream& out, Tourist& other);
	friend istream& operator>>(istream& in, Tourist& other);

};