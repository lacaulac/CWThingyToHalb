#include <Windows.h>

void listenAndSimulate(int vKey, WORD outputChar) {
	while (true) {
		if (GetAsyncKeyState(vKey) & 0x8000) {
			//Send outputChar key press
			INPUT ip;
			memset(&ip, 0, sizeof(INPUT));
			ip.type = INPUT_KEYBOARD;

			ip.ki.wVk = outputChar;
			SendInput(1, &ip, sizeof(INPUT));

			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			//Wait until the key is released
			while (GetAsyncKeyState(vKey) & 0x8000) {
				Sleep(1);
			}
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}

//Nah can't be bothered to create a struct that I'd pass through CreateThread
void simulateDit() {
	listenAndSimulate(VK_LCONTROL, 'Z');
}
void simulateDah() {
	listenAndSimulate(VK_RCONTROL, 'X');
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