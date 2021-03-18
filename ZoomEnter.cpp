#include <iostream>
#include <windows.h>
#include <winuser.h>

int main(void)
{
	printf("Waiting for zoom... (Checks every 10 seconds)\n");

	while (1)
	{
		HWND zoomHwnd;

		if ((zoomHwnd = FindWindow(NULL, L"Enter meeting passcode")) != NULL 
			|| (zoomHwnd = FindWindow(NULL, L"회의 암호 입력")) != NULL)
		{
			printf("FindWindow success\n");

			BOOL result = SetForegroundWindow(zoomHwnd);
			if (!result)
			{
				printf("SetForegroundWindow failed, %lu\n", GetLastError());
			}

			printf("SetForegroundWindow success\n");

			Sleep(100);

			INPUT inputs[14];
			memset(inputs, 0, sizeof(inputs));

			inputs[0].type = INPUT_KEYBOARD;
			inputs[0].ki.wVk = 'D';
			inputs[1].type = INPUT_KEYBOARD;
			inputs[1].ki.wVk = 'D';
			inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[2].type = INPUT_KEYBOARD;
			inputs[2].ki.wVk = 'I';
			inputs[3].type = INPUT_KEYBOARD;
			inputs[3].ki.wVk = 'I';
			inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[4].type = INPUT_KEYBOARD;
			inputs[4].ki.wVk = 'M';
			inputs[5].type = INPUT_KEYBOARD;
			inputs[5].ki.wVk = 'M';
			inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[6].type = INPUT_KEYBOARD;
			inputs[6].ki.wVk = 'I';
			inputs[7].type = INPUT_KEYBOARD;
			inputs[7].ki.wVk = 'I';
			inputs[7].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[8].type = INPUT_KEYBOARD;
			inputs[8].ki.wVk = 'G';
			inputs[9].type = INPUT_KEYBOARD;
			inputs[9].ki.wVk = 'G';
			inputs[9].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[10].type = INPUT_KEYBOARD;
			inputs[10].ki.wVk = 'O';
			inputs[11].type = INPUT_KEYBOARD;
			inputs[11].ki.wVk = 'O';
			inputs[11].ki.dwFlags = KEYEVENTF_KEYUP;

			inputs[12].type = INPUT_KEYBOARD;
			inputs[12].ki.wVk = VK_RETURN;
			inputs[13].type = INPUT_KEYBOARD;
			inputs[13].ki.wVk = VK_RETURN;
			inputs[13].ki.dwFlags = KEYEVENTF_KEYUP;

			UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

			if (uSent != ARRAYSIZE(inputs))
			{
				printf("SendInput failed with uSent value %ud\n", uSent);
			}

			printf("SendInput success\n");
		}

		Sleep(10000);
	}

    return 0;
}
