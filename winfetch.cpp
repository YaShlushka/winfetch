#include <iostream>
#include <Windows.h>
#include <lmcons.h>
#include <sysinfoapi.h>

#include "art.h"

void enableANSI() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

std::wstring GetWindowsUserName() {
	wchar_t username[UNLEN + 1]; //unlen = 256, добавляем один для символа окончания строки
	DWORD size = UNLEN + 1;

	if(GetUserNameW(username, &size)) {
		return std::wstring(username);
	}

	return std::wstring(L"unknown user");
}

std::wstring GetWindowsHostName() {
	wchar_t hostname[MAX_COMPUTERNAME_LENGTH + 1]; //63 + 1 символ окончания строки
	DWORD size = MAX_COMPUTERNAME_LENGTH + 1;

	if(GetComputerNameW(hostname, &size)) {
		return std::wstring(hostname);
	}

	return std::wstring(L"unknown host name");
}

int main() {
	std::wstring username = GetWindowsUserName();
	std::wstring hostname = GetWindowsHostName();

	std::wcout << win_11_1 << "   " << username << std::endl;
	std::wcout << win_11_2 << "   " << std::wstring(username.size(), wchar_t('-')) << std::endl;
	std::wcout << win_11_3 << "   " << "Host: " << hostname << std::endl;
	std::wcout << win_11_4 << "   " << "Version: " << std::endl;
	std::wcout << win_11_5 << "   " << "Uptime: " << std::endl;
	std::wcout << win_11_6 << "   " << "Resolution: " << std::endl;
	std::wcout << win_11_7 << "   " << "Terminal: " << std::endl;
	std::wcout << win_11_8 << "   " << "CPU: " << std::endl;
	std::wcout << win_11_9 << "   " << "GPU: " << std::endl;
	std::wcout << win_11_10 << "   " << "Memory: " << std::endl;
	std::wcout << win_11_11 << "   ";
	enableANSI();

	const char* colors[] = {
					"\033[48;5;16m  \033[0m",  // черный
					"\033[48;5;1m  \033[0m",   // красный
					"\033[48;5;2m  \033[0m",   // зеленый
					"\033[48;5;3m  \033[0m",   // желтый
					"\033[48;5;4m  \033[0m",   // синий
					"\033[48;5;5m  \033[0m",   // пурпурный
					"\033[48;5;6m  \033[0m",   // голубой
					"\033[48;5;7m  \033[0m",   // белый
					"\033[48;5;8m  \033[0m",   // ярко-черный
					"\033[48;5;9m  \033[0m",   // ярко-красный
					"\033[48;5;10m  \033[0m",  // ярко-зеленый
					"\033[48;5;11m  \033[0m",  // ярко-желтый
					"\033[48;5;12m  \033[0m",  // ярко-синий
					"\033[48;5;13m  \033[0m",  // ярко-пурпурный
					"\033[48;5;14m  \033[0m",  // ярко-голубой
					"\033[48;5;15m  \033[0m"   // ярко-белый
				};

	for (int i = 0; i < 16; i++) {
		std::wcout << colors[i];
		if(i == 7) {
			std::cout << "\n                        ";
		}
	}

	return 0;
}