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

int lifeCount = 3;
bool m_isCrash = false;

bool m_isOver;
bool m_isClear;

bool m_isStart = false;
const double clearTime = 38;


void InitGame()
{
    m_isStart = false;

    lifeCount = 3;
    m_tempTime = 0;
    m_timerUI = 0;
    m_isCrash = false;

    InitObstacle();

    StopBgm();
    PlayBGM(L"gameBGM.wav", 100);

    
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