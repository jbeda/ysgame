#include "notif.h"
#include <stdio.h>
#include <Windows.h>
void DebugMessage(const char* text) {
#ifdef DEBUGENABLED
	printf("[DEBUG] %s\n", text);
#endif
}
void OoO() {
#ifdef DEBUGENABLED
	MessageBox(NULL, "Sorry, this is out of order", NULL, MB_ICONERROR | MB_OK);
#endif
}