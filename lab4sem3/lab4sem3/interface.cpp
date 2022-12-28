#include "interface.h"
#include "Human.h"
#include "Tourist.h"
#include "Entrepreneur.h"
#include "Business.h"
#include "Queue.cpp"
#include "menu.cpp"

void myInterface::menu() {
    int Type;
    bool fl = true;
    queue<Human> humans;            //������� Human
    queue<Entrepreneur> entrepreneurs;      //������� Entrepreneur
    queue<Tourist> tourists;            //������� Tourist
    queue<Business> businesses;             //������� Business
    while (fl) {
        cout << "�������: " << endl << "1. �������" << endl << "2. ��������������" << endl
            << "3. ������" << endl << "4. ���������" <<endl <<"5. �����" << endl;
        cin >> Type;            //����� ���� ������
        cout << endl;
        switch (Type)
        {
        case 1:
        {
            menuq(humans);
            break;
        }
        case 2:
        {
            menuq(entrepreneurs);
            break;
        }
        case 3:
        {

            menuq(tourists);
            break;
        }
        case 4:
        {
            menuq(businesses);
            break;
        }
        case(5):
        {
            fl = false;
        }
        }
    }
};