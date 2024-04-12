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
    Draw(L"�� �� ��  �� �� �� �� �� �� �� �� ?", Coord6x5(1, 1));
    Draw(L"�� �� �� ��", Coord6x5(1, 3));
    Draw(L"�� �� ��", Coord6x5(3, 3));

    if (selectQuit == 0) Draw(L"�� �� �� ��", Coord6x5(1, 3), Purple);
    if (selectQuit == 1) Draw(L"�� �� ��", Coord6x5(3, 3), Purple);

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