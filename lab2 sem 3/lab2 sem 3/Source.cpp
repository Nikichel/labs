#include "Class.h"
#include "funs.h"
 
int main() {
	setlocale(LC_ALL, "ru");
	cout << "������� ������: ";
	char* str = new char[MAX_LEN];			//��������� ������
	cin.getline(str, MAX_LEN);
	my_string obj1(str), obj2, obj3, obj4, obj5;		//���������� �������� ������
	delete[] str;
	system("cls");
	cout << "obj1: " << obj1 << endl;		//����� obj1
	cout << "������� obj2: ";			
	cin >> obj2;				//���� obj2
	obj3 = obj1 + " " + obj2;			//obj=obj+char*+obj
	cout << "obj1+obj2= "<< obj3<<endl;
	obj4 = obj1;			//obj=obj
	cout << "obj4: " << obj4<<endl;
	cout<<"obj1 == obj4: "<< (obj1 == obj4) << endl;			//obj==obj
	obj5 = obj1(start_ind);			//��������� ��������� � 4-�� ������� �� �����
	cout <<"��������� obj1 � "<<start_ind<<" ������� �� �����: " << obj5<<endl;
	obj5 = obj1(start_ind,end_ind);		//��������� ��������� � 4-�� �� 8-��
	cout << "��������� obj1 � "<<start_ind <<" ������� �� "<<end_ind<<" :" << obj5<<endl;
	cout << "obj1 == Nikita: " << (obj1 == "Nikita") << endl;		//obj==char*
	obj5 = obj1 + " " + obj2 + " " + obj3 + " Nikita" + " Garashchuk " + obj5;		//��������� �����
	cout << obj5<<endl;
	obj1 = obj2 = obj3 = "Nikita";			//����������
	cout << obj1 << " " << obj2 << " " << obj3 << endl;			//�����
	return 0;
}