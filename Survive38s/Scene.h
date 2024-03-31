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

void Initialize();
void Loop();

void SetScene(SCENE _scene);
