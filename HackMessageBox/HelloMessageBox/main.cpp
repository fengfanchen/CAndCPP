#include <windows.h>
#include <iostream>
#include <string>
using namespace std;


int WINAPI WinMain (HINSTANCE hinstance,HINSTANCE hPrevInstance,LPSTR  lpCmdLine,int  iCmdShow) {

	while(1){

		MessageBoxA(NULL, "World", "Hello", 0);
	}
	return 0;
}