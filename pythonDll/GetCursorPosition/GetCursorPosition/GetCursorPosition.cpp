// GetCursorPosition.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "CursorPy.h"
#include "GetCursorPosition.h"

 POINT getCursorPos() {

	POINT result;
	result.x = getCursorPosX();
	result.y = getCursorPosY();
	return result;
}

 int getTest() {

	 int ret = test();
	 return ret;
 }

 int getTest2() {

	 int ret = test2();
	 return ret;
 }