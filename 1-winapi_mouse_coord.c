#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00

#include <windows.h>

int main()
{
    HWND hwnd = GetConsoleWindow();

    LPPOINT pPnt;
    pPnt = malloc(sizeof(*pPnt));

    do{
        system("cls");
        GetCursorPos(pPnt);
        printf("\nGlobal Cursor position: %d, %d", pPnt[1].x, pPnt[0].y);
        sleep(100);
    }while(GetKeyState(VK_ESCAPE)>=0);
    return 0;
}
