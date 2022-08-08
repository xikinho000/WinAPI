#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

int main()
{
    printf("Show the mouse coordinated based on screen and the context.\n");
    HWND hwnd = GetConsoleWindow();

    // Mouse location relative to the screen
    LPPOINT pPnt;
    pPnt = malloc(sizeof(*pPnt));

    // Mouse location relative to the context screen
    LPRECT rct;
    rct = malloc(sizeof(*rct));
    GetClientRect(hwnd, rct);

    // Screen Size
    LPRECT rctScr;
    rctScr = malloc(sizeof(*rctScr));
    GetClientRect(GetDesktopWindow(), rctScr);

    do{
        system("cls");
        GetCursorPos(pPnt);
        // mouse location in the monitor screen.
        printf("\nGlobal Cursor position: %d, %d", pPnt[0].x, pPnt[0].y);
        ScreenToClient(hwnd, pPnt);
        printf("\nLocal Cursor position: %d, %d", pPnt[0].x, pPnt[0].y);

        printf("\nClient Size: %d, %d", rct[0].right, rct[0].bottom);

        printf("\Screen Size: %d, %d", rctScr[0].right, rctScr[0].bottom);

        if( GetKeyState(VK_LBUTTON)>=0 ){
            printf("\nLeft Mouse Button click!\n");
        }
        Sleep(100);
    }while(GetKeyState(VK_ESCAPE)>=0);
    return 0;
}
