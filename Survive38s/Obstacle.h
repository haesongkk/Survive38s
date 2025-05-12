#pragma once

struct Obstacle
{
    double time;
    Vector2 pos;
    Vector2 dir;

    Vector2 size;
    wstring wstr;

    bool bGenerate = false;
    bool bDestroy = false;
};

void InitObstacle();
void FixedUpdateObstacle();
void RenderObstacle();
void FinalObstacle();

vector<Obstacle> GetObstacles();
