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
    Draw(L"Å¬¸®¾î!", { 40, 10 }, Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalClear()
{
}
