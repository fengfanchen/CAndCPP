#include <iostream>
#include <Windows.h>

using namespace std;

typedef POINT(*CursorPos)();
typedef int(*Test)();
typedef int(*Test2)();

int main() {

	HMODULE hMoudle = LoadLibrary("D:\\vsproject\\GetCursorPosition\\x64\\Release\\GetCursorPosition.dll");
	if (!hMoudle) {

		cout << "loadLibrary failed!" << endl;
		getchar();
		return 0;
	}

	CursorPos cursorPos;
	cursorPos = (CursorPos)GetProcAddress(hMoudle, "getCursorPos");
	Test test = (Test)GetProcAddress(hMoudle, "getTest");
	Test2 test2 = (Test2)GetProcAddress(hMoudle, "getTest2");

	while (1) {

		//POINT point = cursorPos();
		//cout << "x:" << point.x << " y:" << point.y << endl;
		cout << test() << endl;
		//cout << test2() << endl;

		Sleep(500);
	}

	return 0;
}