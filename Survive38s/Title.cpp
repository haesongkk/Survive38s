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
    Draw(L"3 8 ��  �� Ƽ ��", {50, 9}, Green);
    Draw(L"�� ��", {24 - 4, 21});
    Draw(L"�� ��", {48 - 4, 21});
    Draw(L"�� ��", {72 - 4, 21});
    Draw(L"�� ��", {96 - 4, 21});

    if (selectTitle == 1) Draw(L"�� ��", { 24 - 4, 21 }, Purple);
    if (selectTitle == 2) Draw(L"�� ��", { 48 - 4, 21 }, Purple);
    if (selectTitle == 3) Draw(L"�� ��", { 72 - 4, 21 }, Purple);
    if (selectTitle == 4) Draw(L"�� ��", { 96 - 4, 21 }, Purple);

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