#include "Header.h"
#include "Scene.h"

#include "Render.h"
#include "Game.h"
#include "Time.h"
#include "Key.h"
#include "Sound.h"
#include "Util.h"
#include "Obstacle.h"
#include "Player.h"

double playTime = 0;

SCENE curScene;
SCENE selected = GAME;

vector<pair<wstring, COORD>> ui[END] = {};

vector<Object> objects[END] = {};

void DrawUI()
{
    for (auto obj : objects[curScene])
        Draw(obj);
}

void Title()
{
    for (int i = 0; i < ui[TITLE].size(); i++)
    {
        if (selected == i)
            Draw(ui[TITLE][i].first , ui[TITLE][i].second, Purple, Black);
        else
            Draw(ui[TITLE][i].first, ui[TITLE][i].second, White, Black);
    }

    if (GetKey(SPACE, TAP))
        SetScene(selected);
    if (GetKey(RIGHT, TAP))
        selected = (SCENE)(selected + 1);
    if (GetKey(LEFT, TAP))
        selected = (SCENE)(selected - 1);

    Limit(selected, GAME, QUIT);
}

bool isQuit = false;
int selectedNum = 1;
void Quit()
{
    const wstring wstr[] = {
       L"게 임 을  종 료 하 시 겠 습 니 까 ?",
       L"메 인 으 로",
       L"나 가 기",
    };
    const COORD pos[] = {
      m_screenPoint[1][1],
      m_screenPoint[3][1],
      m_screenPoint[3][3],
    };

    for (int i = 0; i < 3; i++)
    {
        if (selectedNum == i)
            Draw(wstr[i], pos[i], Purple, Black);
        else
            Draw(wstr[i], pos[i], White, Black);
    }

    if (GetKey(SPACE, TAP))
    {
        if (selectedNum == 1) SetScene(TITLE);
        else isQuit = true;
    }
    if (GetKey(RIGHT, TAP)) selectedNum++;
    if (GetKey(LEFT, TAP)) selectedNum--;
}

void Game()
{
    playTime += GetDeltaTime();

    //UpdatePlayer();
    //UpdateObstacle();

    wstring wstr[4] = {
        L"time : ",
        L"X X O"
        L"X O O",
        L"O O O",
    };
    Draw(wstr[0] + to_wstring(playTime), m_screenPoint[0][0], White, Black);
    Draw(wstr[lifeCount], m_screenPoint[0][5], White, Black);

    Draw(L"  ", m_pos, g_playerState, g_playerState);
    for (int i = 0; i < 171; i++)
        Draw(m_obs[i].shape, m_obs[i].curPos, White, White);

   
    if (playTime >= clearTime) SetScene(CLEAR);
    if (lifeCount == 0) SetScene(OVER);
}

void Ctrl()
{
    Draw("조 작", m_screenPoint[1][2], Green, Black);
    Draw("이 동  :  좌 우  방 향 키", m_screenPoint[2][2], Green, Black);
    Draw("점 프  :  스 페 이 스 바", m_screenPoint[3][2], Green, Black);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void Credit()
{
    Draw("정 보", m_screenPoint[1][2], Green, Black);
    Draw("플 밍  2 반", m_screenPoint[2][2], Green, Black);
    Draw("신 해 성", m_screenPoint[3][2], Green, Black);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void Clear()
{
    Draw("클리어!", m_screenPoint[1][2], Green, Black);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void Over()
{
    Draw("게임 오버", m_screenPoint[1][2], Green, Black);
    Draw("time : " + to_string(playTime), m_screenPoint[2][2], Green, Black);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void SetScene(SCENE _scene)
{
    ClearScreen();
    curScene = _scene;
    if (curScene == GAME) InitGame();
    else
    {
        StopBgm();
        PlayBGM(L"BGM.wav", 100);
    }
}

void Initialize()
{
    InitTime();
    InitKey();
    InitConsole();

    ui[TITLE].push_back(make_pair(L"3 8 초  버 티 기", m_screenPoint[1][2]));
    ui[TITLE].push_back(make_pair(L"시 작", m_screenPoint[3][1]));
    ui[TITLE].push_back(make_pair(L"조 작", m_screenPoint[3][2]));
    ui[TITLE].push_back(make_pair(L"정 보", m_screenPoint[3][3]));
    ui[TITLE].push_back(make_pair(L"종 료", m_screenPoint[3][4]));

    objects[TITLE].resize(5);
    objects[GAME].resize(5);
    objects[CTRL].resize(5);
    objects[CREDIT].resize(5);
    objects[QUIT].resize(5);
    objects[CLEAR].resize(5);
    objects[OVER].resize(5);


    SetScene(TITLE);
}

void(*sceneMap[END])(void)  = {
    Title, Game, Ctrl, Credit, Quit, Clear, Over
};
void Loop()
{
    while (!isQuit)
    {
        UpdateTime();
        UpdateKey();
        // 더블버퍼링

        sceneMap[curScene]();
    }
}