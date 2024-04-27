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
    Draw(L"3 8 초  버 티 기", Coord6x5(2, 1), Green);
    Draw(L"시 작", Coord6x5(1, 3));
    Draw(L"조 작", Coord6x5(2, 3));
    Draw(L"정 보", Coord6x5(3, 3));
    Draw(L"종 료", Coord6x5(4, 3));

    if (selectTitle == 1) Draw(L"시 작", Coord6x5(1, 3), Purple);
    if (selectTitle == 2) Draw(L"조 작", Coord6x5(2, 3), Purple);
    if (selectTitle == 3) Draw(L"정 보", Coord6x5(3, 3), Purple);
    if (selectTitle == 4) Draw(L"종 료", Coord6x5(4, 3), Purple);

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