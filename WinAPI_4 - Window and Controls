
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*identifiers for gui elements*/
#define btn_2   1
#define edit_1  2
#define label_1 3
#define list_1  4
#define cap_1   5
#define cmb_1   6

HWND btnQuit;
HWND btnMsg;
HWND edit1;
HWND list1;
HWND label1;
HWND caption_1;

HWND comboBox;

// override the built in function
LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if(message == WM_DESTROY)
        PostQuitMessage(0); // message to show after windows close
    else if(message == WM_KEYDOWN)
        printf("code : %d\n", wParam); // show the ascii code of the key pressed
    else if(message == WM_CHAR)
        printf("code : %c\n", wParam); // show the key pressed
    else if(message == WM_MOUSEMOVE){
        int xPos = LOWORD(lParam);
        int yPos = HIWORD(lParam);
        printf("mouse pos: x=%d, y= %d\n", xPos, yPos);
    }
    else if(message == WM_LBUTTONDOWN)
        printf("\nMouse Left Btn\n");

    else if(message == WM_COMMAND)
    {
        if(btnQuit == lParam){
            PostQuitMessage(0);
        }
        //else if( btnMsg == lParam ){
        //    MessageBox(NULL, ("Call to CreateWindow failed!"), ("Win32 Guided Tour"), NULL);
        //}
        else if(LOWORD(wParam) == btn_2){ // loword extracts the identifier.
            MessageBox(NULL, ("Win32"), ("Win32 Guided Tour"), NULL);
        }
        else if(LOWORD(wParam) == edit_1) {
            int nc = HIWORD(wParam);
            char buffer[100];
            GetWindowText(lParam, buffer, 100);
            if(nc== EN_UPDATE)
                SetWindowText(caption_1, buffer);
            //if(nc== EN_CHANGE)
             //   MessageBox(NULL, ("Edit Box Content changed."), ("Win32 Guided Tour"), NULL);
        }
        // combo box get selected index
        else if(LOWORD(wParam) == cmb_1){
            if(HIWORD(wParam) == CBN_SELCHANGE){
                // this will get the selected index.
                int id = SendMessage(lParam, CB_GETCURSEL, 0, 0);
                char buffer[512];
                sprintf(buffer, "%d", id);
                MessageBox(NULL, buffer, "Combo box selected index.", NULL);

                // this will get the selected text.
                /*char buffer[512];
                SendMessage(lParam, CB_GETLBTEXT, id, buffer);
                MessageBox(NULL, id, "Combo box selected index.", NULL);*/
            }
        }
    }

    else return DefWindowProcA(hwnd, message, wParam, lParam);
}

int main()
{
    WNDCLASSA wcl; // structure
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "My Window";
    wcl.lpfnWndProc = WndProc;
    RegisterClassA(&wcl);

    HWND hwnd;
    hwnd = CreateWindow("My Window", "GUI Components", WS_OVERLAPPEDWINDOW,
            10, 10, 640, 480, NULL, NULL, NULL, NULL);
    // Create Windows (Type, Text, VISIBILIT, pos-left, pos-top, w, h, handler, ID, NULL, NULL);
    btnQuit = CreateWindow("Button", "Quit", WS_VISIBLE|WS_CHILD, 10, 10, 100, 50, hwnd, NULL, NULL, NULL);
    btnMsg = CreateWindow("Button", "Test", WS_VISIBLE|WS_CHILD, 110, 10, 100, 50, hwnd, btn_2, NULL, NULL);
    edit1 = CreateWindow("Edit", "0", WS_VISIBLE|WS_CHILD|WS_BORDER|ES_RIGHT | /*masked box, numeric only*/ ES_NUMBER,
                         10, 110, 100, 23, hwnd, edit_1, NULL, NULL);
    label1  = CreateWindow("Label", "First Name", WS_VISIBLE|WS_CHILD, 10, 50, 100, 23, hwnd, label_1, NULL, NULL);
    list1  = CreateWindow("ListBox", "0", WS_VISIBLE|WS_CHILD|WS_BORDER, 10, 300, 100, 50, hwnd, list_1, NULL, NULL);

    caption_1 = CreateWindow("static", "0", WS_VISIBLE|WS_CHILD, 10, 300, 100, 50, hwnd, NULL, NULL, NULL);

    comboBox = CreateWindow("combobox", "", WS_VISIBLE|WS_CHILD|CBS_DROPDOWN, 210, 10, 100, 350, hwnd, cmb_1, NULL, NULL);

    SendMessage(comboBox, CB_ADDSTRING, 0, "a");
    SendMessage(comboBox, CB_ADDSTRING, 0, "b");
    SendMessage(comboBox, CB_ADDSTRING, 0, "c");
    SendMessage(comboBox, CB_ADDSTRING, 0, "d");

    /* Example on how to set an index as selected first.*/
    SendMessage(comboBox, CB_SETCURSEL, 1, 0);



    ShowWindow(hwnd, SW_SHOWNORMAL);
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)){
        // depends the message got from the queue, if that is a close window or not.
        TranslateMessage(&msg);
        // this part closes the program correctly.
        DispatchMessage(&msg);
    }
    return 0;
}
