#include "Header.h"
#include "Clear.h"

#include "Render.h"
#include "Input.h"
#include "Scene.h"

void InitClear()
{
}

void UpdateClear()
{
    Draw(L"Ŭ����!", Coord6x5(2, 1));
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalClear()
{
}