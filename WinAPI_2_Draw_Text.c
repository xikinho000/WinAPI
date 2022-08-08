#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00

#include <windows.h>

void DrawOnWindow_1()
{
    HWND hwnd = GetDesktopWindow();
    HDC dc = GetDC(hwnd);
    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(255, 0, 255));
    Rectangle(dc, 1000, 110, 1100, 210);
}

void DrawOnWindow_2()
{
    HWND hwnd = GetConsoleWindow();
    HDC dc = GetDC(hwnd);
    do{
        SelectObject(dc, GetStockObject(DC_BRUSH));
        SetDCBrushColor(dc, RGB(255, 0, 255));

        SelectObject(dc, GetStockObject(DC_PEN));
        SetDCBrushColor(dc, RGB(255, 255, 255));

        Rectangle(dc, 0, 0, 640, 320);
        //Ellipse(dc, 100, 100, 300, 200);
    }while(GetKeyState(VK_ESCAPE) >= 0);
}

void Animation_1()
{
    int i = 0;
    char c[1024];
    HWND hwnd = GetConsoleWindow();
    HDC dc = GetDC(hwnd);
    do{
        ++i;
        SelectObject(dc, GetStockObject(DC_BRUSH));
        SetDCBrushColor(dc, RGB(255, 0, 255));
        SelectObject(dc, GetStockObject(DC_PEN));
        SetDCBrushColor(dc, RGB(255, 0, 0));
        Rectangle(dc, 0, 0, 640, 300);

        SelectObject(dc, GetStockObject(DC_BRUSH));
        SetDCBrushColor(dc, RGB(101, 255, 25));
        Rectangle(dc, 0+i, 0, 100+i, 100);

        SelectObject(dc, GetStockObject(DC_PEN));
        SetDCBrushColor(dc, RGB(10, 10, 255));
        sprintf(c, "Windows Programming!");
        TextOutA(dc, 520, 550, c, strlen(c)+1);
    }while(GetKeyState(VK_ESCAPE) >= 0);
}

void DrawSomewhereElseWindow()
{
    HWND hwnd = FindWindow(NULL, "Calculator");
    HDC dc = GetDC(hwnd);

    do{
        SelectObject(dc, GetStockObject(DC_BRUSH));
        SetDCBrushColor(dc, RGB(255, 0, 255));
        Rectangle(dc, 0, 0, 640, 300);
    } while(GetKeyState(VK_ESCAPE) >= 0);
}

int main()
{
    //DrawOnWindow();
    //DrawSomewhereElseWindow();
    Animation_1();
    return 0;
}
