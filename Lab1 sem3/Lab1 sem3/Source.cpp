#include "class.h"
#include "funs.h"

int main() {

	setlocale(LC_ALL, "RU");
	int ch = 0;
	int count = 0;
	Array* ars = NULL;

	while (1) {
		rewind(stdin);

		menu(ch);			//выбор пункта меню
		system("cls");
		switch (ch) {
		case(1): {
			cout << "¬ведите кол-во массивов: ";
			input_unsignet_int(count);		//ввод кол-ва массивов
			give_mem(&ars, count);			//выделение пам€ти
			break;
		}
		case(2): {
			input_arrays(ars, count);			//ввод массивов
			break;
		}
		case(3): {
			show_arrays(ars, count);		//вывод массивов
			break;
		}
		case(4): {
			if(ars)
				cross_two(ars, count);		//пересечение 2-ух массивов
			break;
		}
		case(5): {
			if(ars)
				cross_all(ars, count);		//пересечение всех массивов
			break;
		}
		case(6): {
			delete[] ars;			//очистка
			return 0;
		}
		}
	}

}