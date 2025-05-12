#include "Header.h"
#include "Credit.h"

#include "Render.h"
#include "Input.h"
#include "Scene.h"

void InitCredit()
{
}

void UpdateCredit()
{
    Draw(L"정 보", { 30, 9 }, Green);
    Draw(L"플 밍  2 반", { 30, 14 }, Green);
    Draw(L"신 해 성", { 30, 19 }, Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCredit()
{
}
