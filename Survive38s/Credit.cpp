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
    Draw(L"정 보", Coord6x5(2, 1), Green);
    Draw(L"플 밍  2 반", Coord6x5(2, 2), Green);
    Draw(L"신 해 성", Coord6x5(2, 3), Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCredit()
{
}
