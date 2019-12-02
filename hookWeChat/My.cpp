#include "stdafx.h"
#include "My.h"
#include <stdio.h>
#include <stdlib.h>



void getAllInfo(){

	MessageBoxA(NULL, "开始解析", "报告首长", NULL);
	//WeChatWin.dll的基址
	DWORD weChatWinAddr = (DWORD)GetModuleHandle(L"WeChatWin.dll");

	char wxID[0x1000] = {0};
	DWORD weIDDW = weChatWinAddr + 0x13972DC;
	
	//wxID[0] = (char)(*(DWORD*)weIDDW);

	for(int i = 0; i < 40; i++){

		wxID[i] = (char)(*(DWORD*)weIDDW);
		if(wxID[i] == '0'){
		
			break;
		}

		weIDDW += 0x1;
	}
	
	MessageBoxA(NULL, wxID, "报告首长", NULL);
}