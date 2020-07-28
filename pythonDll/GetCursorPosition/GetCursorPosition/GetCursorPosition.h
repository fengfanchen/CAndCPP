#pragma once


#include "stdafx.h"
#include <Windows.h>

#define ExportFunc _declspec(dllexport)

extern "C" ExportFunc POINT getCursorPos();
extern "C" ExportFunc int getTest();
extern "C" ExportFunc int getTest2();