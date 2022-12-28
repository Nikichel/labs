#include "class.h"
#include "funs.h"

int main() {

	setlocale(LC_ALL, "RU");
	int ch = 0;
	int count = 0;
	Array* ars = NULL;

	while (1) {
		rewind(stdin);

		menu(ch);			//����� ������ ����
		system("cls");
		switch (ch) {
		case(1): {
			cout << "������� ���-�� ��������: ";
			input_unsignet_int(count);		//���� ���-�� ��������
			give_mem(&ars, count);			//��������� ������
			break;
		}
		case(2): {
			input_arrays(ars, count);			//���� ��������
			break;
		}
		case(3): {
			show_arrays(ars, count);		//����� ��������
			break;
		}
		case(4): {
			if(ars)
				cross_two(ars, count);		//����������� 2-�� ��������
			break;
		}
		case(5): {
			if(ars)
				cross_all(ars, count);		//����������� ���� ��������
			break;
		}
		case(6): {
			delete[] ars;			//�������
			return 0;
		}
		}
	}

}