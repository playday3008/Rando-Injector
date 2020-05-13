#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

#include "junk.h"

// Change "MY_DLL_NAME.dll" to your dll name
#define DLL_NAME "Osiris.dll"

//Change "csgo.exe" to your process name here
#define injproc "csgo.exe"

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

//   ____    ___                      ____                                                      
//  /\  _`\ /\_ \                    /\  _`\                                                    
//  \ \ \L\ \//\ \      __     __  __\ \ \/\ \     __     __  __                                
//   \ \ ,__/ \ \ \   /'__`\  /\ \/\ \\ \ \ \ \  /'__`\  /\ \/\ \                               
//    \ \ \/   \_\ \_/\ \L\.\_\ \ \_\ \\ \ \_\ \/\ \L\.\_\ \ \_\ \                              
//     \ \_\   /\____\ \__/.\_\\/`____ \\ \____/\ \__/.\_\\/`____ \                             
//      \/_/   \/____/\/__/\/_/ `/___/> \\/___/  \/__/\/_/ `/___/> \                            
//                                 /\___/                     /\___/                            
//                                 \/__/                      \/__/   

int main(int argc, const char* argv[])
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
	std::cout << "              /____/            /____/                           " << std::endl << std::endl;
	std::cout << "(Based on Rando-Injector)" << std::endl;

	if (argc >= 2)
	{
		std::string arg;
		arg += argv[1];
		if ((argc == 2 && arg == "A") || (argc == 2 && arg == "a") || (argc == 4 && arg == "M") || (argc == 4 && arg == "m"))
		{
			goto A;
		}
	}

	char s;

	std::cout << "Auto(A) or manual(M) inject: ";
	std::cin >> s;
	std::cout << std::endl;

	if (s == 'A' || s == 'M' || s == 'a' || s == 'm')
	{
		if (s == 'M' || s == 'm')
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
		A:
			std::string arg;
			arg += argv[1];
			if ((argc == 4 && arg == "M") || (argc == 4 && arg == "m"))
			{

				std::string arg2;
				arg2 += argv[2];

				std::string arg3;
				arg3 += argv[3];

				char* arg4 = new char[arg3.length() + 1];
				strcpy_s(arg4, 150, arg3.c_str());


				_JUNK_BLOCK(jmp_label22)
					DWORD dwProcess;

				_JUNK_BLOCK(jmp_label23)
					char myDLL[MAX_PATH];

				_JUNK_BLOCK(jmp_label24)
					GetFullPathName(arg2.c_str(), MAX_PATH, myDLL, 0);

				_JUNK_BLOCK(jmp_label25)
					dwProcess = Process(arg4);

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
			if ((argc == 2 && arg == "A") || (argc == 2 && arg == "a") || s == 'a' || s == 'A')
			{
				_JUNK_BLOCK(jmp_label33)
					DWORD dwProcess;

				_JUNK_BLOCK(jmp_label34)
					char myDLL[MAX_PATH];

				_JUNK_BLOCK(jmp_label35)
					GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);

				_JUNK_BLOCK(jmp_label36)
					dwProcess = Process(injproc);

				_JUNK_BLOCK(jmp_label37)
					HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

				_JUNK_BLOCK(jmp_label38)
					LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

				_JUNK_BLOCK(jmp_label39)
					WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

				_JUNK_BLOCK(jmp_label40)
					CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

				_JUNK_BLOCK(jmp_label41)
					CloseHandle(hProcess);

				_JUNK_BLOCK(jmp_label42)
					return 0;

				_JUNK_BLOCK(jmp_label43)
			}
		}
	}
	else
	{
		std::cout << "A or M" << std::endl;
		system("pause");
	}
}
