#pragma once

enum SCENE
{
    TITLE,

    GAME,
    CTRL,
    CREDIT,
    QUIT,

    CLEAR,
    OVER,

    END,

};

void InitScene();
void UpdateScene();
void FinalScene();

void SetScene(SCENE _scene);
