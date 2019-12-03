#include <iostream>
#include <windows.h>
#include <string>
#include <Psapi.h>
using namespace std;

int main(int argc, int *argv[]){

	
	HWND hwnd = FindWindowA(nullptr, "Hello");
	if(!hwnd){

		getchar();
		return 0;
	}

	DWORD pid = 0;
	GetWindowThreadProcessId(hwnd, &pid);	//获取进程标识
	if (pid == 0){

		cout << "GetWindowThreadProcessId failed" << endl;
		getchar();
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if(hProcess == NULL){

		cout << "OpenProcess failed" << endl;
		getchar();
		return 0;
	}


	DWORD offset = 0x0041CC7C;
	BYTE value[5] = {0};
	DWORD dwSize;
	DWORD title = 0x0;

	//if(ReadProcessMemory(hProcess, (LPVOID)offset, &value, sizeof(value) / sizeof(value[0]), &dwSize) == 0){

	//	cout << "modify failed" << endl;
	//	cout << value << endl;
	//}
	//else{
	//	cout << "read : " << value << endl;
	//}
	DWORD dwPrev;
	if(!VirtualProtectEx(hProcess, (LPVOID)(offset - 0x1), 10, PAGE_EXECUTE_READWRITE, &dwPrev)){
			
		cout << "VirtualProtectEx failed " << GetLastError() << " " << dwPrev << endl;
		getchar();
		return 0;
	}


	if(WriteProcessMemory(hProcess, (LPVOID)offset, &title, DWORD(sizeof(title)), nullptr) == 0){

		cout << "failed" << endl;
		cout << GetLastError() << endl;
		getchar();
		return 0;
	}
	else{

			cout << "Finished" << endl;
			cout << value << endl;
	}


	if(!VirtualProtectEx(hProcess, (LPVOID)(offset), DWORD(sizeof(title)), dwPrev, &dwPrev)){

		cout << "VirtualProtectEx failed 2" << GetLastError() << " " << dwPrev << endl;
		getchar();
		return 0;
	}

	CloseHandle(hProcess);

	getchar();
	return 0;
}