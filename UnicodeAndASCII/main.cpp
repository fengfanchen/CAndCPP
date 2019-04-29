#include <stdio.h>
#include <Windows.h>

bool UnicodeToAnsi(const char *pAnsi, wchar_t **pUnicode){		//const CHAR *pAnsi, WCHAR *pUnicode

	if(nullptr == pAnsi){
	
		return false;
	}

	//如果有一个size变量，那么会让人知道这是一个size
	int nSize = sizeof(pAnsi);
	size_t szAnsi = MultiByteToWideChar(CP_ACP, 0, pAnsi, -1, nullptr, 0);
	*pUnicode = new wchar_t[szAnsi];
	if(szAnsi == MultiByteToWideChar(CP_ACP, 0, pAnsi, szAnsi, *pUnicode, szAnsi)){
	
		return true;
	}

	return false;

}

int main(int *argc, int *argv[]){

	char *szDemo = "abcd";			//单字节 窄字节 ASCII字节
	wchar_t *wszDemo = L"abcd";		//多字节 宽字节 Unicode字节

	wchar_t szOut[MAXBYTE] = {0};	//这种写法有一定的危险，溢出攻击

	int c = 100;
	int *a = new int[c];

	//窄字符转宽字符
	MultiByteToWideChar(CP_ACP, 0, szDemo, strlen(szDemo), szOut, strlen(szDemo));
	printf("szDemo: %s\n", szDemo);		//窄字符 区别字符串为	\0
	printf("szOut: %ws\n", szOut);		//宽字符 区分字符串为	0000

	//可以先获取长度在进行分配，现在来封装一下
	wchar_t *szOut2 = nullptr;
	UnicodeToAnsi(szDemo, &szOut2);

	printf("szDemo: %s\n", szDemo);
	printf("szOut2: %ws\n", szOut2);

	delete szOut2;
	getchar();
	return 0;
}