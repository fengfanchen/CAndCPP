#include "FirstModule.h"

//模块一想加一个处理，输出I am fine， fuck you！

int iFlag = 2;

int FirstModuleEx(){
	
	printf("I am fine, fuck you!\n");
	return OK;
}


int FirstModuleProc(){

	printf("Hello I am First Module\n");
	if(iFlag <= 0){
		
		FirstModuleEx();
	}
	iFlag--;
	return OK;
}

int InitFirstModule(){

	RegisterProc(MY_WRITE_MODULE, FirstModuleProc);
	return OK;
}