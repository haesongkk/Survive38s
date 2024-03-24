#include "Header.h"
#include "Player.h"

#include "Util.h"
#include "Key.h"
#include "Time.h"
#include "Render.h"
#include "Game.h"

COORD m_pos;
COORD m_prePos;

const int playerMoveSpeed = 9;
const int playerJumpSpeed = 10;

const double gravity = 0.02;
const double jumpVelocity = -0.3; // 2단 구현되면 0.08
const double doubleJumpVelocity = -0.2;

double velocity;

bool onGround = true;
bool onJump;
bool isCrash;

Color g_playerState = White;

void updatePlayerMove()
{
    static ULONGLONG time = 0;
    time += GetDeltaTime();

    while (time >= playerMoveSpeed)
    {
        updatePlayerPos();
        time -= playerMoveSpeed;
    }
}

void InitPlayer()
{
    m_pos.X = WIDTH / 2;
    m_pos.Y = HEIGHT - 2;
}

void updatePlayerPos()
{
    // 공중에 떠있으면 내려오게 만든다.
    m_prePos = m_pos;

    m_pos.Y += velocity;
    velocity += gravity;
    if (m_pos.Y <= 12)
    {
        velocity -= jumpVelocity;
    }

    if (m_pos.Y <= 0)
    {
        m_pos.Y = 0;
    }
    if (m_pos.Y >= HEIGHT-2)
    {
        m_pos.Y = HEIGHT - 2;
        velocity = 0;
        onGround = true;
        onJump = false;
    }

    if (GetKey(SPACE, TAP))
    {
        if (onGround)
        {
            velocity += jumpVelocity;
            onGround = false;
        }
    }

    if (GetKey(RIGHT, TAP))
    {
        m_pos.X++;
        Limit(m_pos.X, (short)0, (short)WIDTH);
    }

    if (GetKey(LEFT,TAP))
    {
        m_pos.X--;
        Limit(m_pos.X, (short)0, (short)HEIGHT);
    }



}
