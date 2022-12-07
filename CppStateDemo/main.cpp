#include <iostream>
#include <time.h>
#include "People.h"
using namespace std;

//每日一充

int main(int argc, char *argv[]) {

	srand((unsigned int)time(NULL));

	People *people = new People;

	for (int i = 0; i < 14; i++) {

		cout << "第 " << i + 1 << " 天";
		int num = rand() % 10;				//0~9的随机数
		if (num < 3) {						//不充值

			cout << "不充值" << endl;
			people->payByDay(0);
		}
		else if (num >= 3 && num <= 6) {	//充个SVIP

			cout << "每日首充" << endl;
			people->payByDay(1);
		}
		else {								//充个SSSVIP

			cout << "每日648" << endl;
			people->payByDay(2);
		}

		cout << "当前 【" << people->currentStateDesc() << "】 " << "金币 【" << people->getCurrentGold() << "】" << endl;
		cout << "---------------------------" << endl;
	}

	delete people;
	getchar();

	return 0;
}