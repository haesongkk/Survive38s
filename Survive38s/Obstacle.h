#pragma once

void InitObstacle();

void UpdateObstacle(int);
void updateObsDraw(int);

void generateObs();

struct Obstacle
{
    COORD curPos; // ������ġ
    COORD prePos;
    ULONGLONG time;
    double speed; // �̵��ӵ�
    int direction; // �̵�����
    const char* scale = "  ";

    Vector2 pos;
    Vector2 move;

};

extern Obstacle m_obs[171];