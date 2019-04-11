#include "stdef.h"
#include "FirstModule.h"
#include "SecondModule.h"

DWORD WINAPI MyThread(){

	while(1){
		
		ExcuteAllModule();
		Sleep(1000);
	}
}

int TestFunPtr(){

	InitFirstModule();
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MyThread, NULL, 0, NULL);
	Sleep(3000);
	InitSecondModule();
	Sleep(3000);
	TerminateThread(hThread, 0);
	CloseHandle(hThread);
	return OK;
}

int main(int argc, int *argv[]){

	TestFunPtr();

	getchar();
	return 0;
}
