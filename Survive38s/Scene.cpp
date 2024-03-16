#include "Header.h"
#include "Scene.h"

#include "Render.h"
#include "Game.h"
#include "Time.h"
#include "Key.h"
#include "Title.h"

bool isStart;
bool isCtrl;
bool isQuit;
bool isCredit;

const ULONGLONG inputDelay = 100;
const ULONGLONG showDelay = 500;
const ULONGLONG jumpDelay = 10;

ULONGLONG timer = 0;

enum SCENE
{
    TITLE, GAME, CTRL, CREDIT, CLEAR, OVER, QUIT, END
} m_scene;

void InitScene()
{
    m_scene = TITLE;
    InitTime();
    //InitKey();
    ClearConsole();
}

void UpdateScene()
{
    UpdateTime();
    UpdateInput();
    switch (m_scene)
    {
        case TITLE: Title();
        case GAME: updateUI();
        case CTRL: showCtrl();
        case CREDIT: showCredit();
        case CLEAR: gameClear();
        case OVER: gameOver();
        case QUIT: quitGame();
    }
}


bool quitGame()
{
    // bool bySelect ���� ���� �������� ���� ���� �� ������ ȭ�� ����

    isQuit = false;

    ClearConsole();
    InitTime();

    Draw("      �� �� ��  �� �� �� �� �� �� �� �� ?", m_screenPoint[1][1], Black, Green);
    Draw(" �� �� �� �� ", m_screenPoint[3][1], Black, Purple);
    Draw(" �� �� �� ", m_screenPoint[3][3], Black, Purple);
    bool activeLeft = true;

    timer = 0;

    while (true)
    {
        UpdateTime();
        timer += GetDeltaTime();
        if (timer >= showDelay)
        {
            UpdateInput();

            if (activeLeft)
            {
                if (GetKey(SPACE, TAP))
                {
                    return false;
                }
                if (GetKey(RIGHT, TAP))
                {
                    activeLeft = false;
                    Draw(" �� �� �� �� ", m_screenPoint[3][1], Black, White);
                    Draw(" �� �� �� ", m_screenPoint[3][3], Black, Purple);
                }
            }
            else
            {
                if (GetKey(SPACE, TAP))
                {
                    return true;
                }
                if (GetKey(LEFT, TAP))
                {
                    activeLeft = true;
                    Draw(" �� �� �� �� ", m_screenPoint[3][1], Black, Purple);
                    Draw(" �� �� �� ", m_screenPoint[3][3], Black, White);
                }
            }

            
        }
    }
}

void showCredit()
{
    isCredit = false;

    ClearConsole();
    InitTime();

    Draw(" �� �� ", m_screenPoint[1][2], Green, Black);
    Draw("                    �� ��  2 ��", m_screenPoint[2][2], Green, Black);
    Draw("                     �� �� ��", m_screenPoint[3][2], Green, Black);

    timer = 0;
    while (true)
    {
        UpdateTime();
        timer += GetDeltaTime();
        if (timer >= showDelay)
        {
            UpdateInput();
            if (GetKey(SPACE, TAP)) break;
        }

    }
}



void gameClear()
{
    m_isClear = false;
    ClearConsole();

    Draw("Ŭ����!", m_screenPoint[1][2], Green, Black);

    timer = 0;
    while (true)
    {
        UpdateTime();
        timer += GetDeltaTime();
        if (timer >= showDelay)
        {
            UpdateInput();
            if (GetKey(SPACE,TAP))
            {
                isQuit = true;
                break;
            }
        }
    }
}

void gameOver()
{
    ClearConsole();
    m_isOver = false;

    Draw("���� ����", m_screenPoint[1][2], Green, Black);
    Draw("time : " + to_string(timer), m_screenPoint[2][2], Green, Black);

    timer = 0;
    while (true)
    {
        UpdateTime();
        timer += GetDeltaTime();
        if (timer >= showDelay)
        {
            UpdateInput();
            if (GetKey(SPACE,TAP))
            {
                isQuit = true;
                break;
            }
        }
    }
}

void showCtrl()
{
    isCtrl = false;

    ClearConsole();

    Draw("�� ��", m_screenPoint[1][2], Green, Black);
    Draw("         �� ��  :  �� ��  �� �� Ű", m_screenPoint[2][3], Green, Black);
    Draw("         �� ��  :  �� �� �� �� ��", m_screenPoint[3][3], Green, Black);

    timer = 0;
    while (true)
    {
        UpdateTime();
        timer += GetDeltaTime();
        if (timer >= showDelay)
        {
            UpdateInput();
            if (GetKey(SPACE,TAP))
            {
                break;
            }
        }

    }
}