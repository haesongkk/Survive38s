﻿#include "Header.h"
#include "Render.h"

#include "Player.h"

HANDLE hConsole = {};
HANDLE hBackBuffer[2] = {};
bool bScreenIndex = 0;

COORD m_coord6x5[5][6] = {};

void InitRender()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 백버퍼 생성
    hBackBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    hBackBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서 지우기
    CONSOLE_CURSOR_INFO consoleCursor = { 1,0 };
    SetConsoleCursorInfo(hConsole, &consoleCursor);
    SetConsoleCursorInfo(hBackBuffer[0], &consoleCursor);
    SetConsoleCursorInfo(hBackBuffer[1], &consoleCursor);

    // 콘솔 창 크기 설정
    SMALL_RECT screenRect = { 1,1,WIDTH,HEIGHT };
    SetConsoleWindowInfo(hConsole, TRUE, &screenRect);
    SetConsoleWindowInfo(hBackBuffer[0], TRUE, &screenRect);
    SetConsoleWindowInfo(hBackBuffer[1], TRUE, &screenRect);

    // 화면 버퍼 크기 설정
    COORD bufferSize = { WIDTH,HEIGHT };
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SetConsoleScreenBufferSize(hBackBuffer[0], bufferSize);
    SetConsoleScreenBufferSize(hBackBuffer[1], bufferSize);

    // 창 크기 고정
    HWND hWnd = GetConsoleWindow();
    LONG style = GetWindowLong(hWnd, GWL_STYLE);
    style &= ~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX);
    SetWindowLong(hWnd, GWL_STYLE, style);

    // 창 제목 설정
    SetConsoleTitle(L"38초 버티기");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            short x = WIDTH / 5 * j;
            short y = HEIGHT / 4 * i;
            m_coord6x5[i][j] = { x,y };
        }
    }
}

void UpdateRender()
{
    SetConsoleActiveScreenBuffer(hBackBuffer[bScreenIndex]);

    bScreenIndex = !bScreenIndex;

    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // 현재 콘솔 창 크기와 속성
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // 콘솔 화면을 공백으로 채웁니다.
    FillConsoleOutputCharacterW(hBackBuffer[bScreenIndex], L' ', dwConSize, coordScreen, &cCharsWritten);

    // 콘솔 화면의 속성을 기본값으로 설정합니다.
    FillConsoleOutputAttribute(hBackBuffer[bScreenIndex], csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
}

void FinalRender()
{
    // 백버퍼 삭제?
}

void Draw(wstring _wstr, COORD _pos, Color _textColor, Color _backColor)
{
    if (_pos.X < 0 || _pos.X >= WIDTH || _pos.Y < 0 || _pos.Y >= HEIGHT) return;

    DWORD dw;
    COORD pos = _pos;
    wstring wstr;
    SetConsoleTextAttribute(hBackBuffer[bScreenIndex], _textColor | _backColor << 4);

    for (int i = 0; i < _wstr.size(); i++)
    {
        if (_wstr[i] == L'\n')
        {
            SetConsoleCursorPosition(hBackBuffer[bScreenIndex], pos);
            WriteFile(hBackBuffer[bScreenIndex], wstr.c_str(), wstr.size(), &dw, NULL);
            wstr.clear();
            pos.Y++;
            continue;
        }
        wstr += _wstr[i];
    }
    SetConsoleCursorPosition(hBackBuffer[bScreenIndex], pos);
    WriteConsoleW(hBackBuffer[bScreenIndex], wstr.c_str(), wstr.size(), &dw, NULL);
    return;
}

COORD Coord6x5(int x, int y)
{
    return m_coord6x5[y][x];
}
