#include "Header.h"
#include "Render.h"

#include "Player.h"

HANDLE hConsole = {};
COORD m_screenPoint[5][6] = {};

COORD screenPoint[30];

void Draw(string _object, COORD _pos, Color _textColor, Color _backColor)
{
    SetConsoleTextAttribute(hConsole, _textColor | _backColor << 4);
    COORD pos = _pos;
    for (int i = 0; i < _object.size(); i++)
    {
        if (_object[i] == '\n')
        {
            pos.X = _pos.X;
            pos.Y++;
            continue;
        }

        SetConsoleCursorPosition(hConsole, pos);
        cout << _object[i];
        pos.X++;
    }

    return;
}

void Draw(wstring _object, COORD _pos, Color _textColor, Color _backColor)
{
    if (_pos.X < 0 || _pos.X >= WIDTH || _pos.Y < 0 || _pos.Y >= HEIGHT) return;

    SetConsoleTextAttribute(hConsole, _textColor | _backColor << 4);
    COORD pos = _pos;
    for (int i = 0; i < _object.size(); i++)
    {
        if (_object[i] == '\n')
        {
            pos.X = _pos.X;
            pos.Y++;
            continue;
        }
        SetConsoleCursorPosition(hConsole, pos);

        wcout << _object[i];
        pos.X++;
    }

    return;
}
void Draw(Object _obj)
{
}
void RemoveCursor()
{
    CONSOLE_CURSOR_INFO consoleCursor;
    consoleCursor.bVisible = 0;
    consoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &consoleCursor);
}

void ClearScreen()
{
    system("cls");
    //COORD coordScreen = { 0, 0 }; 
    //DWORD cCharsWritten;
    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //DWORD dwConSize;

    //// 현재 콘솔 창 크기와 속성
    //GetConsoleScreenBufferInfo(hConsole, &csbi);
    //dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    //// 콘솔 화면을 공백으로 채웁니다.
    //FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);

    //// 콘솔 화면의 속성을 기본값으로 설정합니다.
    //FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
}

void SetScreenSize(int _width, int _height)
{
    // 콘솔 창 크기 설정
    SMALL_RECT screenRect = { 1,1,_width,_height };
    SetConsoleWindowInfo(hConsole, TRUE, &screenRect);

    // 화면 버퍼 크기 설정
    COORD bufferSize = { _width,_height };
    SetConsoleScreenBufferSize(hConsole, { (short)_width, (short)_height });

    // 창 크기 고정
    HWND hWnd = GetConsoleWindow();
    LONG style = GetWindowLong(hWnd, GWL_STYLE);
    style &= ~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX);
    SetWindowLong(hWnd, GWL_STYLE, style);
}

void SetScreenTitle(wstring _title)
{
    SetConsoleTitle(_title.c_str());
}

void InitConsole()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetScreenSize(WIDTH, HEIGHT);
    SetScreenTitle(L"38초 버티기");

    RemoveCursor();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            short x = WIDTH / 5 * j;
            short y = HEIGHT / 4 * i;
            m_screenPoint[i][j] = { x,y };
        }
    }
}
