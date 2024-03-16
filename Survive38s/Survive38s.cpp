#include "Header.h"

#include "Time.h"
#include "Key.h"
#include "Render.h"
#include "Scene.h"
#include "Game.h"
#include "Title.h"


// 창크기 120 * 30

int main()
{
    ClearConsole();
    while (true)
    {
        Title();
        if (isStart) InitGame();
        if (isCtrl) showCtrl();
        if (isCredit) showCredit();
        if (isQuit && quitGame()) break;
    }
}

