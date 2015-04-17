/*
*	A simple program testing Windows global hotkey usage. Using the keybind 'alt + 5' will print a message in the program console
*	Largely taken from MSDN topic on RegisterHotkey here:
*	https://msdn.microsoft.com/en-us/library/windows/desktop/ms646309%28v=vs.85%29.aspx
*/

#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

#define HOTKEY_ID 0x53C8

int main()
{

	// register 'alt + 5' key press
	if (RegisterHotKey(NULL, HOTKEY_ID, MOD_ALT | MOD_NOREPEAT, 0x35))
	{
		cout << "Successfully registered alt + 5 global hotkey" << endl;
	}

	MSG winMessage = { 0 };

	// perpetually wait until a message is received
	while (GetMessage(&winMessage, NULL, 0, 0))
	{
		if (winMessage.message == WM_HOTKEY)
		{
			cout << "Received hotkey message" << endl;
		}
	}

	// unregister the hotkey
	if (UnregisterHotKey(NULL, HOTKEY_ID))
	{
		cout << "Successfully unregistered hotkey" << endl;
	}

	return 0;
}