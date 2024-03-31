#include "Header.h"
#include "Player.h"

#include "Util.h"
#include "Key.h"
#include "Time.h"
#include "Render.h"
#include "Game.h"

Object player;
Vector2 playerPos;
int lifeCount = 3;

const double gravity = 0.0001f;
const double playerMoveSpeed = 0.05f;
const double jumpVelocity[2] = {-0.05f,-0.075f};

double velocity;

int jumpCount = 0;
bool isCrash;

Color g_playerState = White;

void InitPlayer()
{
    player.pos.X = playerPos.x = WIDTH / 2;
    player.pos.Y = playerPos.y = HEIGHT - 3;
    player.backColor = White;
}

void UpdatePlayer()
{
    velocity += gravity;
    playerPos.y += velocity;

    if (playerPos.y >= HEIGHT - 3)
    {
        playerPos.y = HEIGHT - 3;
        velocity = 0;
        jumpCount = 0;
    }
    if (GetKey(SPACE, TAP) && jumpCount < 2)
    {
        velocity += jumpVelocity[jumpCount++];
    }

    if (GetKey(RIGHT, DOWN)) playerPos.x += playerMoveSpeed;
    if (GetKey(LEFT, DOWN)) playerPos.x -= playerMoveSpeed;

    Limit<double>(playerPos.y, 0, HEIGHT - 1);
    Limit<double>(playerPos.x, 0, WIDTH - 1);

    player.pos.X = playerPos.x;
    player.pos.Y = playerPos.y;
}

void RenderPlayer()
{
    RenderObject(player);
}
