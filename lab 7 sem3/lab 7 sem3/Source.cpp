#include "interface.h"
int main() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 0);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	myInterface enter;
	
	enter.menu();			//вывод меню

	return 0;
}
