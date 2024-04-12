#include "Header.h"
#include "Quit.h"

#include "Input.h"
#include "Util.h"

#include "Scene.h"
#include "Render.h"
#include "Framework.h"

int selectQuit;

void InitQuit()
{
    selectQuit = 0;
}

void UpdateQuit()
{
    Draw(L"게 임 을  종 료 하 시 겠 습 니 까 ?", Coord6x5(1, 1));
    Draw(L"메 인 으 로", Coord6x5(1, 3));
    Draw(L"나 가 기", Coord6x5(3, 3));

    if (selectQuit == 0) Draw(L"메 인 으 로", Coord6x5(1, 3), Purple);
    if (selectQuit == 1) Draw(L"나 가 기", Coord6x5(3, 3), Purple);

    if (GetKey(RIGHT, TAP)) selectQuit++;
    if (GetKey(LEFT, TAP)) selectQuit--;

    if (GetKey(SPACE, TAP))
    {
        if (selectQuit == 0) SetScene(TITLE);
        if (selectQuit == 1) Quit();
    }

    Limit(selectQuit, 0, 1);
}

void FinalQuit()
{
}
