#include "FirstModule.h"

int FirstModuleProc(){

	printf("Hello I am First Module\n");
	return OK;
}

int InitFirstModule(){

	RegisterProc(MY_WRITE_MODULE, FirstModuleProc);
	return OK;
}