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
    Draw(L"�� ��", Coord6x5(2, 1));
    Draw(L"�� ��  2 ��", Coord6x5(2, 2));
    Draw(L"�� �� ��", Coord6x5(2, 3));
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCredit()
{
}