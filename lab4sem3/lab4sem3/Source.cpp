#include "interface.h"
//#include "Queue.cpp"
#include <Windows.h>

int main() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (15 << 4) + 0);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	myInterface inter;

	inter.menu();
	
	return 0;
}