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
const double jumpVelocity = -0.3; // 2�� �����Ǹ� 0.08
const double doubleJumpVelocity = -0.2;

double velocity;

bool onGround = true;
bool onJump;
bool isCrash;

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
    m_pos.X = (playerMovableRect.right + playerMovableRect.left) / 2;
    m_pos.Y = playerMovableRect.bottom;
}

void updatePlayerPos()
{
    // ���߿� �������� �������� �����.
    m_prePos = m_pos;

    m_pos.Y += velocity;
    velocity += gravity;
    if (m_pos.Y <= 12)
    {
        velocity -= jumpVelocity;
    }

    if (m_pos.Y <= playerMovableRect.top)
    {
        m_pos.Y = playerMovableRect.top;
    }
    if (m_pos.Y >= playerMovableRect.bottom)
    {
        m_pos.Y = playerMovableRect.bottom;
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
        limit(m_pos.X, playerMovableRect.left, playerMovableRect.right);
    }

    if (GetKey(LEFT,TAP))
    {
        m_pos.X--;
        limit(m_pos.X, playerMovableRect.left, playerMovableRect.right);
    }



}