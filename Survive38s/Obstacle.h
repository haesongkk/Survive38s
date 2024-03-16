#pragma once

void InitObstacle();

void UpdateObstacle(int);
void updateObsDraw(int);

void generateObs();

struct Obstacle
{
    COORD curPos; // 생성위치
    COORD prePos;
    ULONGLONG time;
    double speed; // 이동속도
    int direction; // 이동방향
    const char* scale = "  ";

    Vector2 pos;
    Vector2 move;

};

extern Obstacle m_obs[171];