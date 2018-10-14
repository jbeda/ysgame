#include "notif.h"
#include <Windows.h>
void DebugMessage(const char* text) {
	MessageBox(NULL, text, "Debug", MB_OK | MB_ICONINFORMATION);
}