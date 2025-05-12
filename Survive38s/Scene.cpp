#include "Header.h"
#include "Scene.h"

#include "Title.h"

#include "Game.h"
#include "Ctrl.h"
#include "Credit.h"
#include "Quit.h"

#include "Clear.h"
#include "Over.h"

SCENE curScene = TITLE;

void(*InitFunc[END])(void) = {
    InitTitle, 

    InitGame, 
    InitCtrl, 
    InitCredit, 
    InitQuit, 

    InitClear, 
    InitOver
};

void(*UpdateFunc[END])(void) = {
    UpdateTitle, 

    UpdateGame, 
    UpdateCtrl,
    UpdateCredit,
    UpdateQuit, 

    UpdateClear,
    UpdateOver
};

void UpdateScene()
{
    UpdateFunc[curScene]();
}

void(*FinalFunc[END])(void) = {
    FinalTitle,

    FinalGame,
    FinalCtrl,
    FinalCredit,
    FinalQuit,

    FinalClear,
    FinalOver
};

void InitScene()
{
    InitFunc[curScene]();
}


void FinalScene()
{
    FinalFunc[curScene]();
}

void SetScene(SCENE _scene)
{
    FinalFunc[curScene]();
    curScene = _scene;
    InitFunc[curScene]();
}
