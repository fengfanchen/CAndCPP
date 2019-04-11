#pragma once

#include "stdef.h"

typedef enum tagMODULE_SETS	//SETS表示这是枚举集合
{
	MY_ALL_MODULE = 0,
	MY_READ_MODULE = 1,
	MY_WRITE_MODULE = 2,

	MY_INVALID_MODULE = 0xffff

}MODULE_SETS_E;	//E表示enum

typedef int(*pProcFun)();

typedef struct tagMoudleData	//一般带有管理的结构体在C语言中都是tagXXXX
{
	int iModule;		//每个模块唯一ID
	pProcFun pFun;
}MOUDLE_DATA_S;		//一般在结构体结尾都加S，代表struct;


int RegisterProc(int iModule, pProcFun pFun);
int ExcuteAllModule();
