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
    queue<Human> humans;            //очередь Human
    queue<Entrepreneur> entrepreneurs;      //очередь Entrepreneur
    queue<Tourist> tourists;            //очередь Tourist
    queue<Business> businesses;             //очередь Business
    while (fl) {
        cout << "Введите: " << endl << "1. Человек" << endl << "2. Препринематель" << endl
            << "3. Турист" << endl << "4. Бизнесмен" <<endl <<"5. Выход" << endl;
        cin >> Type;            //выбор типа класса
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