#include "Header.h"
#include "Game.h"

#include "Player.h"
#include "Obstacle.h"
#include "Collision.h"

#include "Render.h"
#include "Time.h"
#include "Sound.h"
#include "Input.h"
#include "Scene.h"

const double clearTime = 38.f;
double playTime;

const double fixedUpdateTime = 0.02f;
double fixedUpdateTimer;

void InitGame()
{
    InitPlayer();
    InitObstacle();
    InitCollision();

    Stop();
    Play(L"./Resource/gameBGM.wav", 100);

    playTime = 0.f;
    fixedUpdateTimer = 0.f;
}

void UpdateGame()
{
    fixedUpdateTimer += GetDeltaTime();
    if (fixedUpdateTimer >= fixedUpdateTime)
    {
        fixedUpdateTimer -= fixedUpdateTime;
        FixedUpdatePlayer();
        FixedUpdateObstacle();
        FixedUpdateCollision();
    }

    RenderPlayer();
    RenderObstacle();

    // 바닥
    Draw(wstring(120, L' '), { 0,28 }, White, White);

    // 플레이 타임 ui
    playTime += GetDeltaTime();
    wstring timerUI = to_wstring(playTime);
    timerUI.erase(timerUI.length() - 3, 3);
    Draw(L"time : " + timerUI, {0, 0});

    // 남은 생명 ui
    wstring lifeUI;
    int life = LifeCount();
    if (life == 3) lifeUI = L"O O O";
    if (life == 2) lifeUI = L"O O X";
    if (life == 1) lifeUI = L"O X X";
    Draw(lifeUI, { (short)(WIDTH - lifeUI.length()),0 });

    // 게임 클리어
    if (playTime >= clearTime) SetScene(CLEAR);
}

void FinalGame()
{
    FinalPlayer();
    FinalObstacle();
    FinalCollision();

    Stop();
    Play(L"./Resource/BGM.wav", 100);
}

double PlayTime()
{
    return playTime;
}
