#include "Header.h"
#include "Render.h"

#include "Player.h"

RECT consoleScreenSize;
RECT playerMovableRect;
COORD screenPoint[30];

COORD m_screenPoint[5][6] = {};

void SetColor(Color _textColor, Color _backColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (_backColor << 4) + _textColor);
}

void GoToXY(COORD _pos)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
}

void Draw(string _object, COORD _pos, Color _textColor, Color _backColor)
{
    SetColor(_textColor, _backColor);
    COORD pos = _pos;
    const char* obj = _object.c_str();
    for (int i = 0; i < _object.size(); i++)
    {
        if (obj[i] == '\n')
        {
            pos.X = _pos.X;
            pos.Y++;
            continue;
        }
        GoToXY(pos);
        cout << _object.c_str()[i];
        pos.X++;
    }

    return;
}

void ClearConsole()
{
    // 화면 
    system("cls");
    SetColor(White, Black);

    // 커서 숨기기
    HANDLE consonleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO consoleCursor;
    consoleCursor.bVisible = 0;
    consoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consonleHandle, &consoleCursor);

    // 편하게 사용하기 위한 수치들 저장
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    consoleScreenSize.left = csbi.srWindow.Left;
    consoleScreenSize.right = csbi.srWindow.Right;
    consoleScreenSize.bottom = csbi.srWindow.Bottom;
    consoleScreenSize.top = csbi.srWindow.Top;

    playerMovableRect.left = consoleScreenSize.left + 2;
    playerMovableRect.right = consoleScreenSize.right - 2;
    playerMovableRect.bottom = consoleScreenSize.bottom - 2;
    playerMovableRect.top = consoleScreenSize.top + 2;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            short x = (playerMovableRect.left + playerMovableRect.right) / 5 * j;
            short y = (playerMovableRect.top + playerMovableRect.bottom) / 4 * i;
            m_screenPoint[i][j] = { x,y };
        }
    }
}
