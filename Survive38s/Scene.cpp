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

bool isQuit = false;

SCENE curScene = TITLE;
vector<Object> uiObjects = {};

int activated = 1;

double playTime = 0.f;
const double clearTime = 38.f;

void InitTitle()
{
    activated = 1;
    uiObjects.resize(5);
    uiObjects[0] = { L"3 8 초  버 티 기", m_screenPoint[1][2] };
    uiObjects[1] = { L"시 작", m_screenPoint[3][1] };
    uiObjects[2] = { L"조 작", m_screenPoint[3][2] };
    uiObjects[3] = { L"정 보", m_screenPoint[3][3] };
    uiObjects[4] = { L"종 료", m_screenPoint[3][4] };
}

void InitQuit()
{
    activated = 1;
    uiObjects.resize(3);
    uiObjects[0] = { L"게 임 을  종 료 하 시 겠 습 니 까 ?", m_screenPoint[1][1] };
    uiObjects[1] = { L"메 인 으 로", m_screenPoint[3][1] };
    uiObjects[2] = { L"나 가 기", m_screenPoint[3][3] };
}


void InitCtrl()
{
    uiObjects.resize(3);
    uiObjects[0] = { L"조 작", m_screenPoint[1][2], Green };
    uiObjects[1] = { L"이 동  :  좌 우  방 향 키", m_screenPoint[2][2], Green };
    uiObjects[2] = { L"점 프  :  스 페 이 스 바", m_screenPoint[3][2], Green };
}

void InitCredit()
{
    uiObjects.resize(3);
    uiObjects[0] = { L"정 보", m_screenPoint[1][2], Green };
    uiObjects[1] = { L"플 밍  2 반", m_screenPoint[2][2], Green };
    uiObjects[2] = { L"신 해 성", m_screenPoint[3][2], Green };
}

void InitClear()
{
    uiObjects.resize(1);
    uiObjects[0] = { L"클리어!", m_screenPoint[1][2], Green };

    StopBgm();
    PlayBGM(L"BGM.wav", 100);
}

void InitOver()
{
    uiObjects.resize(2);
    uiObjects[0] = { L"게임 오버", m_screenPoint[1][2], Green };
    uiObjects[1] = { L"time : " + to_wstring(playTime), m_screenPoint[2][2], Green };

    StopBgm();
    PlayBGM(L"BGM.wav", 100);
}

void InitGame()
{
    InitPlayer();
    //InitObstacle();
    //InitCollision();

    uiObjects.resize(3);
    uiObjects[0] = { L"time : ", m_screenPoint[0][0] };
    uiObjects[1] = { L"O O O" , m_screenPoint[0][5] };
    uiObjects[2] = { wstring(120, L' ') , m_screenPoint[4][0], White,White };

    StopBgm();
    PlayBGM(L"gameBGM.wav", 100);
}

void UpdateTitle()
{
    for (auto& ui : uiObjects)
        ui.textColor = White;
    uiObjects[activated].textColor = Purple;

    if (GetKey(RIGHT, TAP)) activated++;
    if (GetKey(LEFT, TAP)) activated--;

    if (GetKey(SPACE, TAP))
        SetScene((SCENE)activated);

    Limit(activated, 1, 4);
}

void UpdateQuit()
{
    for (auto& ui : uiObjects)
        ui.textColor = White;
    uiObjects[activated].textColor = Purple;

    if (GetKey(RIGHT, TAP)) activated++;
    if (GetKey(LEFT, TAP)) activated--;

    if (GetKey(SPACE, TAP))
    {
        if (activated == 1) SetScene(TITLE);
        if (activated == 2) isQuit = true;
    }

    Limit(activated, 1, 2);

}

void UpdatePage()
{
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void UpdateGame()
{
    UpdatePlayer();
    //UpdateObstacle();
    //UpdateCollision();
    
    playTime += GetDeltaTime();
    wstring tmp = to_wstring(playTime);
    tmp.erase(tmp.length() - 3, 3);
    uiObjects[0].wstr = L"time : " + tmp;

    if (playTime >= clearTime) SetScene(CLEAR);

    // 플레이어로 옮기기
    //if (lifeCount == 0) SetScene(OVER);
}

void(*InitScene[END])(void) = {
    InitTitle, 

    InitGame, 
    InitCtrl, 
    InitCredit, 
    InitQuit, 

    InitClear, 
    InitOver
};

void(*UpdateScene[END])(void) = {
    UpdateTitle, 

    UpdateGame, 
    UpdatePage,
    UpdatePage,
    UpdateQuit, 

    UpdatePage,
    UpdatePage
};


void RenderScene()
{
    for (auto ui : uiObjects)
        RenderObject(ui);

    if (curScene == GAME)
    {
        RenderPlayer();
        //RenderObstacles();
    }
}

void SetScene(SCENE _scene)
{
    curScene = _scene;

    InitScene[curScene]();
}

void Initialize()
{
    InitTime();
    InitKey();
    InitRender();

    SetScene(TITLE);

    PlayBGM(L"BGM.wav", 100);
}

void Loop()
{
    while (!isQuit)
    {
        UpdateTime();
        UpdateKey();
        UpdateRender();

        UpdateScene[curScene]();
        RenderScene();
    }
}