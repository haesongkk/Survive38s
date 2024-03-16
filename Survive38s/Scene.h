#pragma once

void showCtrl();

void gameOver();
void gameClear();
void showCredit();
bool quitGame();

void InitScene();
void UpdateScene();

extern bool isStart;
extern bool isCtrl;
extern bool isQuit;
extern bool isCredit;