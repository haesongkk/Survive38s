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
    Draw(L"�� ��", { 30, 9 }, Green);
    Draw(L"�� ��  :  �� ��  �� �� Ű", { 30, 14 }, Green);
    Draw(L"�� ��  :  �� �� �� �� ��", { 30, 19 }, Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCtrl()
{
}
