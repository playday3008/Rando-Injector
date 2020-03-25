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
__asm _emit 0xD4 \
__asm _emit 0xB3 \
__asm _emit 0x39 \
__asm _emit 0x88 \
__asm _emit 0x4A \
__asm _emit 0xAF \
__asm _emit 0xED \
__asm _emit 0xF6 \
__asm _emit 0xB1 \
__asm _emit 0x92 \
__asm _emit 0x92 \
__asm _emit 0x78 \
__asm _emit 0x9B \
__asm _emit 0x60 \
__asm _emit 0x5C \
__asm _emit 0x67 \
__asm _emit 0x5C \
__asm _emit 0x14 \
__asm _emit 0x30 \
__asm _emit 0xAD \
__asm _emit 0xEC \
__asm _emit 0x3B \
__asm _emit 0xC9 \
__asm _emit 0x2C \
__asm _emit 0x48 \
__asm _emit 0x47 \
__asm _emit 0xB6 \
__asm _emit 0x15 \
__asm _emit 0xC1 \
__asm _emit 0x3E \
__asm _emit 0xDA \
__asm _emit 0x21 \
__asm _emit 0x0B \
__asm _emit 0x19 \
__asm _emit 0x8B \
__asm _emit 0xFC \
__asm _emit 0xD0 \
__asm _emit 0x65 \
__asm _emit 0x14 \
__asm _emit 0x85 \
__asm _emit 0x3B \
__asm _emit 0xB5 \
__asm _emit 0x43 \
__asm _emit 0x2F \
__asm _emit 0x9D \
__asm _emit 0xFE \
__asm _emit 0x0B \
__asm _emit 0x53 \
__asm _emit 0x6B \
__asm _emit 0x39 \
__asm _emit 0x83 \
__asm _emit 0xEB \
__asm _emit 0x9D \
__asm _emit 0xD5 \
__asm _emit 0x35 \
__asm _emit 0xB9 \
__asm _emit 0x10 \
__asm _emit 0x83 \
__asm _emit 0xD0 \
__asm _emit 0x1E \
__asm _emit 0x66 \
__asm _emit 0x28 \
__asm _emit 0x47 \
__asm _emit 0x93 \
__asm _emit 0xF1 \
__asm _emit 0xDE \
__asm _emit 0xCF \
__asm _emit 0xF4 \
__asm _emit 0x9C \
__asm _emit 0xF3 \
__asm _emit 0xC5 \
__asm _emit 0x20 \
__asm _emit 0x62 \
__asm _emit 0x29 \
__asm _emit 0xE6 \
__asm _emit 0x7A \
__asm _emit 0xC4 \
__asm _emit 0x54 \
__asm _emit 0x25 \
__asm _emit 0x6B \
__asm _emit 0x27 \
__asm _emit 0x9F \
__asm _emit 0xC8 \
__asm _emit 0xAE \
__asm _emit 0x64 \
__asm _emit 0x57 \
__asm _emit 0x2B \
__asm _emit 0x52 \
__asm _emit 0xA7 \
__asm _emit 0x2F \
__asm _emit 0xFC \
__asm _emit 0xBC \
__asm _emit 0x20 \
__asm _emit 0xFA \
__asm _emit 0x2D \
__asm _emit 0x22 \
__asm _emit 0x85 \
__asm _emit 0xE4 \
__asm _emit 0x06 \
__asm _emit 0x81 \
__asm _emit 0x9E \
__asm _emit 0x5A \
__asm _emit 0xD0 \
__asm _emit 0xD7 \
__asm _emit 0x57 \
__asm _emit 0xFD \
__asm _emit 0x7B \
__asm _emit 0x5A \
__asm _emit 0x22 \
__asm _emit 0x82 \
__asm _emit 0xC9 \
__asm _emit 0x70 \
__asm _emit 0x92 \
__asm _emit 0x55 \
__asm _emit 0xF0 \
__asm _emit 0x14 \
__asm _emit 0x81 \
__asm _emit 0x92 \
__asm _emit 0x7C \
__asm _emit 0x18 \
__asm _emit 0xEB \
__asm _emit 0x1B \
__asm _emit 0x0A \
__asm _emit 0xDD \
__asm _emit 0x31 \
__asm _emit 0x95 \
__asm _emit 0x8E \
__asm _emit 0xCD \
__asm _emit 0xD7 \
__asm _emit 0x4A \
__asm _emit 0x2F \
__asm _emit 0xB1 \
__asm _emit 0xC6 \
__asm _emit 0x98 \
__asm _emit 0x76 \
__asm _emit 0xAB \
__asm _emit 0xFB \
__asm _emit 0x01 \
__asm _emit 0x02 \
__asm _emit 0xCE \
__asm _emit 0xC6 \
__asm _emit 0x99 \
__asm _emit 0xD7 \
__asm _emit 0xA0 \
__asm _emit 0xCC \
__asm _emit 0x6B \
__asm _emit 0x1A \
__asm _emit 0x0F \
__asm _emit 0xC5 \
__asm _emit 0xC5 \
__asm _emit 0x46 \
__asm _emit 0xEA \
__asm _emit 0xEE \
__asm _emit 0x57 \
__asm _emit 0x0B \
__asm _emit 0x93 \
__asm _emit 0x68 \
__asm _emit 0x18 \
__asm _emit 0x4A \
__asm _emit 0x83 \
__asm _emit 0xD8 \
__asm _emit 0x00 \
__asm _emit 0x4A \
__asm _emit 0x76 \
__asm _emit 0x25 \
__asm _emit 0xAF \
__asm _emit 0x75 \
__asm _emit 0x7B \
__asm _emit 0x4D \
__asm _emit 0x75 \
__asm _emit 0x8C \
__asm _emit 0xC6 \
__asm _emit 0x90 \
__asm _emit 0x78 \
__asm _emit 0x5F \
__asm _emit 0xEE \
__asm _emit 0xA3 \
__asm _emit 0xC2 \
__asm _emit 0x36 \
__asm _emit 0x9E \
__asm _emit 0x4F \
__asm _emit 0xB0 \
__asm _emit 0x8B \
__asm _emit 0xD8 \
__asm _emit 0x80 \
__asm _emit 0xF3 \
__asm _emit 0xFD \
__asm _emit 0xED \
__asm _emit 0xC6 \
__asm _emit 0x53 \
__asm _emit 0x8F \
__asm _emit 0x47 \
__asm _emit 0x97 \
__asm _emit 0x17 \
__asm _emit 0x67 \
__asm _emit 0xCF \
__asm _emit 0xBA \
__asm _emit 0x8E \
__asm _emit 0xFF \
__asm _emit 0x67 \
__asm _emit 0x4D \
__asm _emit 0x3A \
__asm _emit 0xF8 \
__asm _emit 0x62 \
__asm _emit 0x91 \
__asm _emit 0x3F \
__asm _emit 0x52 \
__asm _emit 0x37 \
__asm _emit 0x39 \
__asm _emit 0x78 \
__asm _emit 0x44 \
__asm _emit 0xA2 \
__asm _emit 0xFF \
__asm _emit 0x73 \


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
				strcpy(arg4, arg3.c_str());


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