#include <conio.h>
#include "CMenu.h"
using namespace std;
using namespace System;
int main() {
	setlocale(LC_ALL, "Spanish");
	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::Black;
	CMenu* nuevo = new CMenu();

	_getch();
	return 0;
}