#include <Windows.h>

void simulateDit() {
	while (true) {
		if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) {
			//Send 'Z' key press
			INPUT ip;
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0;
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			ip.ki.wVk = 'Z';
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(10); // Short delay

			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			//Wait until Left Shift key is released
			while (GetAsyncKeyState(VK_LSHIFT) & 0x8000) {
				Sleep(1);
			}
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}

void simulateDah() {
	while (true) {
		if (GetAsyncKeyState(VK_RCONTROL) & 0x8000) {
			//Send 'X' key press
			INPUT ip;
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0;
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			ip.ki.wVk = 'X';
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(10); // Short delay

			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			//Wait until Left Shift key is released
			while (GetAsyncKeyState(VK_LSHIFT) & 0x8000) {
				Sleep(1);
			}
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}

int main(int argc, char** argv) {
	//MessageBoxA(NULL, "Hello, World!", "CWShiftsToLetters", MB_OK);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)simulateDit, NULL, 0, NULL);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)simulateDah, NULL, 0, NULL);
	while (true) {
		Sleep(100);
	}
	return (int)0;
}