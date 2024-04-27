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
    Draw(L"조 작", Coord6x5(2, 1), Green);
    Draw(L"이 동  :  좌 우  방 향 키", Coord6x5(2, 2), Green);
    Draw(L"점 프  :  스 페 이 스 바", Coord6x5(2, 3), Green);
    if (GetKey(SPACE, TAP)) SetScene(TITLE);
}

void FinalCtrl()
{
}
