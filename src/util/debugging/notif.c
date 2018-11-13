#include "notif.h"
#include <stdio.h>
#include <Windows.h>
void DebugMessage(const char* text) {
	printf("[DEBUG] %s\n", text);
}
void OoO() {
	MessageBox(NULL, "Sorry, this is out of order", NULL, MB_ICONERROR | MB_OK);
}