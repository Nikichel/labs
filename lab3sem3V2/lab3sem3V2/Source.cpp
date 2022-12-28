#include "Entrepreneur.h"
#include "Tourist.h"
#include "Business.h"
#include <Windows.h> 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ru");

	//Entrepreneur man;
	//man.setName("Nikita");
	//man.setSurname("Garashchuk");
	//man.setMidname("Vasil");
	//man.setDate(30, 10, 2003);

	//man.setLicense(123234);
	//man.setAddres("Минск", "Энгельса", 23);
	////man.setNumPassport(121212);
	//Date data1 = { 30,10,2013 };
	////man.addBroadCross("Mosсow", data1);
	//man.addTax(data1, 123);
	////man.addProduct("Apple");
	////man.addProduct("Orange");
	////man.addProduct("Apple");
	////man.addBroadCross("Poland", data1);

	////Human man1(30,10,2003, "Гаращук", "Никита", "Васильевич");
	////Tourist man1((Tourist)man);
	////cout << man1;

	////Entrepreneur man2((Entrepreneur)man);
	////cout << man2;
	//man.head();
	//cout << man;

	Entrepreneur man1;
	cout << "ФИО, дата рождения, адрес лизенции(город, улица, дом), номер лизензии" << endl;
	cin >> man1;

	/*Tourist man2;
	cout << "ФИО, дата рождения, номер паспорта" << endl;
	cin >> man2;

	Business man3;
	cout<< "ФИО, дата рождения, номер паспорта, адрес лизенции(город, улица, дом), номер лизензии" << endl;
	cin >> man3;*/

	man1.head();
	cout << man1 << endl << endl;

	//man2.head();
	//cout << man2 << endl << endl;

	//man3.head();
	//cout << man3 << endl << endl;
	return 0;
}