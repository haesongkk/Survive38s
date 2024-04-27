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

double velocity;
int jumpCount;
const double gravity = 1500.f;
const double moveSpeed = 150.f;
const double jumpVelocity[2] = { -200.f,-150.f };

void InitPlayer()
{
    pos.x = WIDTH / 2;
    pos.y = HEIGHT - 3;

    color = Purple;

    velocity = 0.f;
    jumpCount = 0;

    isCrash = false;
    crashTimer = 0.f;
    life = 3;
}

void UpdatePlayer()
{
    // 좌우 이동
    if (GetKey(RIGHT, DOWN)) pos.x += moveSpeed * GetDeltaTime();
    if (GetKey(LEFT, DOWN)) pos.x -= moveSpeed * GetDeltaTime();


    // 점프
    if (GetKey(SPACE, TAP) && jumpCount < 2)
        velocity = jumpVelocity[jumpCount++];

    pos.y += velocity * GetDeltaTime();
    velocity += gravity * GetDeltaTime();

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

        if ((crashTimer += GetDeltaTime()) > 1)
        {
            isCrash = false;
            crashTimer = 0;
            color = Purple;
        }

    }

    // 그리기
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
