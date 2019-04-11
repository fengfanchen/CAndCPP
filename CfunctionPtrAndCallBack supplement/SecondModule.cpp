#include "SecondModule.h"

int SecondModuleProc(){

	printf("Hello I am Second Module\n");
	return OK;
}

int InitSecondModule(){

	RegisterProc(MY_READ_MODULE, SecondModuleProc);
	return OK;
}