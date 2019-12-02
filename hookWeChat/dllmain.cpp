// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "My.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)getAllInfo, hModule, 0, NULL);
		MessageBox(NULL, L"我已成功打入敌人内部", L"报告首长", NULL);
		getAllInfo();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

