#include "Header.h"
#include "Ctrl.h"

#include "Render.h"
#include "Input.h"
#include "Scene.h"

void InitCtrl()
{
}

void UpdateCtrl()
{
    Draw(L"�� ��", Coord6x5(2, 1));
    Draw(L"�� ��  :  �� ��  �� �� Ű", Coord6x5(2, 2));
    Draw(L"�� ��  :  �� �� �� �� ��", Coord6x5(2, 3));
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCtrl()
{
}