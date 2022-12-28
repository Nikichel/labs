#include "Class.h"
#include "funs.h"
 
int main() {
	setlocale(LC_ALL, "ru");
	cout << "Введите строку: ";
	char* str = new char[MAX_LEN];			//выделение памяти
	cin.getline(str, MAX_LEN);
	my_string obj1(str), obj2, obj3, obj4, obj5;		//объявление объектов класса
	delete[] str;
	system("cls");
	cout << "obj1: " << obj1 << endl;		//вывод obj1
	cout << "Введите obj2: ";			
	cin >> obj2;				//ввод obj2
	obj3 = obj1 + " " + obj2;			//obj=obj+char*+obj
	cout << "obj1+obj2= "<< obj3<<endl;
	obj4 = obj1;			//obj=obj
	cout << "obj4: " << obj4<<endl;
	cout<<"obj1 == obj4: "<< (obj1 == obj4) << endl;			//obj==obj
	obj5 = obj1(start_ind);			//выделение подстроки с 4-го символа до конца
	cout <<"Подстрока obj1 с "<<start_ind<<" индекса до конца: " << obj5<<endl;
	obj5 = obj1(start_ind,end_ind);		//выделение подстроки с 4-го до 8-го
	cout << "Подстрока obj1 с "<<start_ind <<" индекса до "<<end_ind<<" :" << obj5<<endl;
	cout << "obj1 == Nikita: " << (obj1 == "Nikita") << endl;		//obj==char*
	obj5 = obj1 + " " + obj2 + " " + obj3 + " Nikita" + " Garashchuk " + obj5;		//различная сумма
	cout << obj5<<endl;
	obj1 = obj2 = obj3 = "Nikita";			//присвоение
	cout << obj1 << " " << obj2 << " " << obj3 << endl;			//вывод
	return 0;
}