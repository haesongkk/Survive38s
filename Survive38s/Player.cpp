#include "Header.h"
#include "Player.h"

#include "Util.h"
#include "Input.h"
#include "Time.h"
#include "Render.h"
#include "Game.h"
#include "Scene.h"

const wstring player = L"  ";
Vector2 pos;
Color color;

bool isCrash;
double crashTimer;
int life;

bool onJump;
double velocity;
int jumpCount;
const double gravity = 0.75f;
const double moveSpeed = 3.f;
const double jumpVelocity[2] = { -4.f, -3.f };

void InitPlayer()
{
    pos.x = WIDTH / 2;
    pos.y = HEIGHT - 3;

    color = Purple;

    onJump = false;
    velocity = 0.f;
    jumpCount = 0;

    isCrash = false;
    crashTimer = 0.f;
    life = 3;
}

void FixedUpdatePlayer()
{
    double dt = GetDeltaTime();
    // 좌우 이동
    if (GetKey(RIGHT, DOWN)) pos.x += moveSpeed;
    if (GetKey(LEFT, DOWN)) pos.x -= moveSpeed;


    // 점프
    if (onJump)
    {
        onJump = false;
        if (jumpCount < 2) velocity = jumpVelocity[jumpCount++];
    }
   

    pos.y += velocity;
    velocity += gravity;

    if (pos.y > HEIGHT - 3)
    {
        pos.y = HEIGHT - 3;
        velocity = 0;
        jumpCount = 0;
    }

    // 이동 반경 제한
    Limit<double>(pos.y, 0, HEIGHT - 3);
    Limit<double>(pos.x, 0, WIDTH - 2);


    // 충돌 무적 시간
    if (isCrash) 
    {
        if ((int)(crashTimer * 10) / 2 % 2 == 0)
            color = Green;
        if ((int)(crashTimer * 10) / 2 % 2 == 1)
            color = Purple;

        if ((crashTimer += dt) > 1)
        {
            isCrash = false;
            crashTimer = 0;
            color = Purple;
        }

    }
    
}

void RenderPlayer()
{
    if (GetKey(SPACE, TAP)) onJump = true;
    Draw(L"  ", to_coord(pos), White, color);
}

void FinalPlayer()
{
}

void IsCrash()
{
    if (isCrash) return;
    isCrash = true;
    if (--life == 0) SetScene(OVER);
}

int LifeCount()
{
    return life;
}

Vector2 PlayerPos()
{
    return pos;
}
