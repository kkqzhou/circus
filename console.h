#ifndef _CONSOLE_H_
#define _CONSOLE_H_

// Console commands for Windows OS

#include <windows.h>
#include <stdio.h>
#include <string>
#include <wchar.h>

char readkey() {
    HANDLE hIn;
    bool Continue = TRUE;
    char input;
    INPUT_RECORD InRec;
    DWORD NumRead;

    hIn = GetStdHandle(STD_INPUT_HANDLE);

    while (Continue) {
        ReadConsoleInput(hIn,&InRec,1,&NumRead);
        // each key press counts as TWO events - pressing down and release
        if ((InRec.EventType == KEY_EVENT) && (InRec.Event.KeyEvent.bKeyDown)) {
            input = InRec.Event.KeyEvent.uChar.AsciiChar;
            Continue = FALSE;
        }
    }
    FlushConsoleInputBuffer(hIn);
    return input;
}

void clrscr() {
    COORD topLeft = {0,0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console,' ',screen.dwSize.X*screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                                screen.dwSize.X*screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void setcoords(int x, int y) {
    HANDLE hOut;
    COORD Dest;
    
    Dest.X = x;
    Dest.Y = y;
    
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, Dest);
}

void changefont(std::string fontname, int size) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;          // Index of the font in the system's console font table.
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = size;                // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wstring fn = std::wstring(fontname.begin(), fontname.end());
    wcscpy(cfi.FaceName, fn.c_str()); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

#endif