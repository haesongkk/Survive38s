#include "Header.h"
#include "Over.h"

#include "Game.h"
#include "Render.h"
#include "Input.h"
#include "Scene.h"
#include "Time.h"

void InitOver()
{
}

void UpdateOver()
{
    wstring playTime = to_wstring(PlayTime());
    playTime.erase(playTime.length() - 3, 3);
    Draw(L"게임 오버", { 40, 10 }, Purple);
    Draw(L"time : " + playTime, { 40, 15 });
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalOver()
{
}
