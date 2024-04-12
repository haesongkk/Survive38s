#include "Header.h"
#include "Title.h"

#include "Input.h"
#include "Scene.h"
#include "Util.h"
#include "Render.h"

int selectTitle;

void InitTitle()
{
    selectTitle = 1;
}

void UpdateTitle()
{
    Draw(L"3 8 ��  �� Ƽ ��", Coord6x5(2, 1));
    Draw(L"�� ��", Coord6x5(1, 3));
    Draw(L"�� ��", Coord6x5(2, 3));
    Draw(L"�� ��", Coord6x5(3, 3));
    Draw(L"�� ��", Coord6x5(4, 3));

    if (selectTitle == 1) Draw(L"�� ��", Coord6x5(1, 3), Purple);
    if (selectTitle == 2) Draw(L"�� ��", Coord6x5(2, 3), Purple);
    if (selectTitle == 3) Draw(L"�� ��", Coord6x5(3, 3), Purple);
    if (selectTitle == 4) Draw(L"�� ��", Coord6x5(4, 3), Purple);

    if (GetKey(RIGHT, TAP)) selectTitle++;
    if (GetKey(LEFT, TAP)) selectTitle--;

    if (GetKey(SPACE, TAP))
    {
        if (selectTitle == 1) SetScene(GAME);
        if (selectTitle == 2) SetScene(CTRL);
        if (selectTitle == 3) SetScene(CREDIT);
        if (selectTitle == 4) SetScene(QUIT);
    }

    Limit(selectTitle, 1, 4);
}

void FinalTitle()
{
}