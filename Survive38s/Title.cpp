#include "Header.h"
#include "Title.h"
#include "Render.h"
#include "Time.h"
#include "Key.h"
#include "Scene.h"
#include "Sound.h"

void Title()
{
    ClearConsole();
    InitTime();
    PlayBGM(L"BGM.wav", 100);

    //const int xStart = 10, xControl = 20, xQuit = 30;
    int x = screenPoint[19].X, y = screenPoint[19].Y; // 메뉴 시작 위치

    Draw("3 8 초  버 티 기", m_screenPoint[1][2], White, Black);
    Draw(" 시 작 ", m_screenPoint[3][1], Purple, Black);
    Draw(" 조 작 ", m_screenPoint[3][2], White, Black);
    Draw(" 정 보 ", m_screenPoint[3][3], White, Black);
    Draw(" 종 료 ", m_screenPoint[3][4], White, Black);

    while (true)
    {
        UpdateInput();
        enum CASE
        {
            START, CTRL, INFO, QUIT, END
        } caseNum = START;

        switch (caseNum)
        {
            case START:
                if (GetKey(SPACE, TAP))
                {
                    isStart = true;
                    return;
                }
                if (GetKey(RIGHT, TAP))
                {
                    caseNum = CTRL;
                    Draw(" 시 작 ", m_screenPoint[3][1], White, Black);
                    Draw(" 조 작 ", m_screenPoint[3][2], Purple, Black);
                }
            case CTRL:
                if (GetKey(SPACE, TAP))
                {
                    isCtrl = true;
                    return;
                }
                if (GetKey(LEFT, TAP))
                {
                    caseNum = START;
                    Draw(" 조 작 ", m_screenPoint[3][2], White, Black);
                    Draw(" 시 작 ", m_screenPoint[3][1], Purple, Black);
                }
                if (GetKey(RIGHT, TAP))
                {
                    caseNum = INFO;
                    Draw(" 조 작 ", m_screenPoint[3][2], White, Black);
                    Draw(" 정 보 ", m_screenPoint[3][3], Purple, Black);


                }
            case INFO:
                if (GetKey(SPACE, TAP))
                {
                    isCredit = true;
                    return;
                }
                if (GetKey(LEFT, TAP))
                {
                    caseNum = CTRL;
                    Draw(" 정 보 ", m_screenPoint[3][3], White, Black);
                    Draw(" 조 작 ", m_screenPoint[3][2], Purple, Black);

                }
                if (GetKey(RIGHT, TAP))
                {
                    caseNum = QUIT;
                    Draw(" 정 보 ", m_screenPoint[3][3], White, Black);
                    Draw(" 종 료 ", m_screenPoint[3][4], Purple, Black);

                }
            case QUIT:
                if (GetKey(SPACE, TAP))
                {
                    isQuit = true;
                    return;
                }
                if (GetKey(LEFT, TAP))
                {
                    caseNum = INFO;
                    Draw(" 종 료 ", m_screenPoint[3][4], White, Black);
                    Draw(" 정 보 ", m_screenPoint[3][3], Purple, Black);
                }
        }
            



    }
}