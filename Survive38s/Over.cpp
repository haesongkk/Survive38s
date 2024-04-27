#include "Header.h"
#include "Over.h"

#include "Game.h"
#include "Render.h"
#include "Input.h"
#include "Scene.h"

void InitOver()
{
}

void UpdateOver()
{
    wstring playTime = to_wstring(PlayTime());
    playTime.erase(playTime.length() - 3, 3);
    Draw(L"게임 오버", Coord6x5(2, 1), Green);
    Draw(L"time : " + playTime, Coord6x5(2, 2));
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalOver()
{
}
