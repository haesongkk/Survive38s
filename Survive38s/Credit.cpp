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
    Draw(L"�� ��", { 30, 9 }, Green);
    Draw(L"�� ��  2 ��", { 30, 14 }, Green);
    Draw(L"�� �� ��", { 30, 19 }, Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCredit()
{
}
