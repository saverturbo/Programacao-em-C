#include <conio.h>

#include <stdio.h>
#include <windows.h>
#define done "DONE!!! by Chang xD"

void CURSOR(int x, int y)
{
COORD Z = {x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Z);
}

void main()
{
int PROG;

for (PROG = 0; PROG <= 70; PROG++)
{
if (!PROG)
{
printf ("");
}

printf ("%c", 219);
Sleep(500);
}

CURSOR(30,3);
printf (done);
getch();
}
