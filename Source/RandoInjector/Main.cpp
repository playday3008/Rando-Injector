#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

// Change "MY_DLL_NAME.dll" to your dll name
#define DLL_NAME "Osiris.dll"

//Change "csgo.exe" to your process name here
#define injproc "csgo.exe"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by add new bytes
#define JUNKS \
__asm _emit 0x50 \
__asm _emit 0x76 \
__asm _emit 0x47 \
__asm _emit 0x50 \
__asm _emit 0x87 \
__asm _emit 0x69 \
__asm _emit 0x88 \
__asm _emit 0x22 \
__asm _emit 0x51 \
__asm _emit 0x85 \
__asm _emit 0x72 \
__asm _emit 0x26 \
__asm _emit 0x59 \
__asm _emit 0x33 \
__asm _emit 0x10 \
__asm _emit 0x44 \
__asm _emit 0x80 \
__asm _emit 0x37 \
__asm _emit 0x14 \
__asm _emit 0x07 \
__asm _emit 0x74 \
__asm _emit 0x06 \
__asm _emit 0x99 \
__asm _emit 0x21 \
__asm _emit 0x72 \
__asm _emit 0x23 \
__asm _emit 0x63 \
__asm _emit 0x91 \
__asm _emit 0x83 \
__asm _emit 0x02 \
__asm _emit 0x79 \
__asm _emit 0x89 \
__asm _emit 0x23 \
__asm _emit 0x44 \
__asm _emit 0x16 \
__asm _emit 0x73 \
__asm _emit 0x03 \
__asm _emit 0x60 \
__asm _emit 0x53 \
__asm _emit 0x64 \
__asm _emit 0x49 \
__asm _emit 0x90 \
__asm _emit 0x12 \
__asm _emit 0x22 \
__asm _emit 0x12 \
__asm _emit 0x35 \
__asm _emit 0x60 \
__asm _emit 0x53 \
__asm _emit 0x67 \
__asm _emit 0x64 \
__asm _emit 0x64 \
__asm _emit 0x64 \
__asm _emit 0x96 \
__asm _emit 0x74 \
__asm _emit 0x74 \
__asm _emit 0x22 \
__asm _emit 0x96 \
__asm _emit 0x95 \


// Don't change this!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:


/////////////////////////////////////////////////////////////////////////////////////
//                                 INJECTOR CODE                                   //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	std::cout << "   ____       _      _         __   __________  ___________ ____ " << std::endl;
	std::cout << "  / __ \\_____(_)____(_)____   / /  / ____/ __ \\/ ____/ ___// __ \\" << std::endl;
	std::cout << " / / / / ___/ / ___/ / ___/  / /  / / __/ / / / __/  \\__ \\/ /_/ /" << std::endl;
	std::cout << "/ /_/ (__  ) / /  / (__  )  / /  / /_/ / /_/ / /___ ___/ / ____/ " << std::endl;
	std::cout << "\\____/____/_/_/  /_/____/  / /   \\____/\\____/_____//____/_/      " << std::endl;
	std::cout << "    ____  __            __///                                    " << std::endl;
	std::cout << "   / __ \\/ /___ ___  __/ __ \\____ ___  __                        " << std::endl;
	std::cout << "  / /_/ / / __ `/ / / / / / / __ `/ / / /                        " << std::endl;
	std::cout << " / ____/ / /_/ / /_/ / /_/ / /_/ / /_/ /                         " << std::endl;
	std::cout << "/_/   /_/\\__,_/\\__, /_____/\\__,_/\\__, /                          " << std::endl;
	std::cout << "              /____/            /____/                           \n" << std::endl;
	std::cout << "(Based on Rando-Injector)" << std::endl;

	char s;

	std::cout << "Auto(A) or manual(M) inject: ";
	std::cin >> s;

	if (s == 'A' || s == 'M')
	{
		if (s == 'M')
		{
			std::string DLL_NAMEM;
			std::string injprocM;
			std::cout << "Enter dll fullname here: ";
			std::cin >> DLL_NAMEM;
			std::cout << "Enter process name here: ";
			std::cin >> injprocM;

			// Convert string to char
			char* injprocMM = const_cast<char*>(injprocM.c_str());

			_JUNK_BLOCK(jmp_label11)
				DWORD dwProcess;

			_JUNK_BLOCK(jmp_label12)
				char myDLL[MAX_PATH];

			_JUNK_BLOCK(jmp_label13)
				GetFullPathName(DLL_NAMEM.c_str(), MAX_PATH, myDLL, 0);

			_JUNK_BLOCK(jmp_label4)
				dwProcess = Process(injprocMM);

			_JUNK_BLOCK(jmp_label15)
				HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

			_JUNK_BLOCK(jmp_label16)
				LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

			_JUNK_BLOCK(jmp_label17)
				WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

			_JUNK_BLOCK(jmp_label18)
				CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

			_JUNK_BLOCK(jmp_label19)
				CloseHandle(hProcess);

			_JUNK_BLOCK(jmp_label20)
				return 0;

			_JUNK_BLOCK(jmp_label21)
		}
		else
		{
			_JUNK_BLOCK(jmp_label22)
				DWORD dwProcess;

			_JUNK_BLOCK(jmp_label23)
				char myDLL[MAX_PATH];

			_JUNK_BLOCK(jmp_label24)
				GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);

			_JUNK_BLOCK(jmp_label25)
				dwProcess = Process(injproc);

			_JUNK_BLOCK(jmp_label26)
				HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

			_JUNK_BLOCK(jmp_label27)
				LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

			_JUNK_BLOCK(jmp_label28)
				WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

			_JUNK_BLOCK(jmp_label29)
				CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

			_JUNK_BLOCK(jmp_label30)
				CloseHandle(hProcess);

			_JUNK_BLOCK(jmp_label31)
				return 0;

			_JUNK_BLOCK(jmp_label32)
		}
	}
	else
	{
		std::cout << "A or M";
		system("pause");
	}
}