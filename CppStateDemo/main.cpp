#include <iostream>
#include <time.h>
#include "People.h"
using namespace std;

//ÿ��һ��

int main(int argc, char *argv[]) {

	srand((unsigned int)time(NULL));

	People *people = new People;

	for (int i = 0; i < 14; i++) {

		cout << "�� " << i + 1 << " ��";
		int num = rand() % 10;				//0~9�������
		if (num < 3) {						//����ֵ

			cout << "����ֵ" << endl;
			people->payByDay(0);
		}
		else if (num >= 3 && num <= 6) {	//���SVIP

			cout << "ÿ���׳�" << endl;
			people->payByDay(1);
		}
		else {								//���SSSVIP

			cout << "ÿ��648" << endl;
			people->payByDay(2);
		}

		cout << "��ǰ ��" << people->currentStateDesc() << "�� " << "��� ��" << people->getCurrentGold() << "��" << endl;
		cout << "---------------------------" << endl;
	}

	delete people;
	getchar();

	return 0;
}