#include "Header.h"
#include "Game.h"

#include "Render.h"
#include "Player.h"
#include "Time.h"
#include "Sound.h"
#include "Obstacle.h"
#include "Sound.h"
#include "Key.h"
#include "Scene.h"

float m_timerUI = 0;
ULONGLONG m_tempTime = 0;

int m_hpCount = 3;
bool m_isCrash = false;

bool m_isOver;
bool m_isClear;

bool m_isStart = false;
const double clearTime = 38;

void updateUI()
{
    // 경과 시간
    m_timerUI += GetDeltaTime();
    if (m_tempTime >= 10)
    {
        m_timerUI += 0.01;
        m_tempTime -= 10;
    }

    Draw("time : " + to_string(m_timerUI), m_screenPoint[0][0], Black, White);

    if (m_hpCount == 3)
    {
        Draw("O O O", m_screenPoint[0][5], Black, White);
    }
    if (m_hpCount == 2)
    {
        Draw("X O O", m_screenPoint[0][5], Black, White);
    }
    if (m_hpCount == 1)
    {
        Draw("X X O", m_screenPoint[0][5], Black, White);
    }

    if (m_timerUI >= clearTime) m_isClear = true;
    if (m_hpCount == 0) m_isOver = true;

}

void Game()
{
    updateUI();
}

void InitGame()
{
    m_isStart = false;

    m_hpCount = 3;
    m_tempTime = 0;
    m_timerUI = 0;
    m_isCrash = false;

    ClearConsole();
    InitTime();

    InitObstacle();

    StopBgm();
    PlayBGM(L"gameBGM.wav", 100);

    while (true)
    {
        UpdateTime();
        generateObs();
        UpdateInput();
        updatePlayerMove();
        updateUI();

        DrawPlayer();


        if (m_isOver)
        {
            StopBgm();
            PlayBGM(L"BGM.wav", 100);
            gameOver();
            break;
        }
        if (m_isClear)
        {
            StopBgm();
            PlayBGM(L"BGM.wav", 100);
            gameClear();
            break;
        }
    }
    return;
}

void DrawPlayer()
{
    string player = "  ";
    if (m_prePos.X != m_pos.X || m_prePos.Y != m_pos.Y)
        Draw(player, m_pos, Black, White);

    if (m_isCrash)
    {
        static ULONGLONG temp;
        temp += GetDeltaTime();
        if (temp < 200)
        {
            Draw(player, m_pos, Black, Green);
        }
        else if (temp < 400)
        {
            Draw(player, m_pos, Black, Purple);
        }
        else if (temp < 600)
        {
            Draw(player, m_pos, Black, Green);
        }
        else if (temp < 800)
        {
            Draw(player, m_pos, Black, Purple);
        }
        else if (temp < 1000)
        {
            Draw(player, m_pos, Black, Green);
        }
        else
        {
            temp = 0;;
            m_isCrash = false;;
        }
    }
}