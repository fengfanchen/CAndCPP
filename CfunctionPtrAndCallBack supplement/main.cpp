#include "stdef.h"
#include "FirstModule.h"
#include "SecondModule.h"

DWORD WINAPI MyThread(){

	while(1){
		printf(">");
		ExcuteAllModule();
		Sleep(1000);
	}
}

DWORD WINAPI MyThreadEx(){
	
	while(1){
		printf("#");
		ExcuteWriteModule();
		Sleep(1000);
	}
}

int TestFunPtr(){

	InitFirstModule();

	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MyThread, NULL, 0, NULL);
	HANDLE hThreadEx = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MyThreadEx, NULL, 0, NULL);

	Sleep(3000);
	InitSecondModule();
	Sleep(3000);

	TerminateThread(hThread, 0);
	CloseHandle(hThread);

	TerminateThread(hThreadEx, 0);
	CloseHandle(hThreadEx);

	return OK;
}

int main(int argc, int *argv[]){

	TestFunPtr();

	getchar();
	return 0;
}
