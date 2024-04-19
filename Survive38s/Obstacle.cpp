#include "Header.h"
#include "Obstacle.h"

#include "Render.h"
#include "Game.h"
#include "Resource.h"
#include "Time.h"

vector<Obstacle> obstacles;

void InitObstacle()
{
    assert(obstacles.empty());
    LoadTxt();
    wstring txt = GetTxt(L"obstacles");
    int pos;
    while (true)
    {
        Obstacle obstacle;

        pos = txt.find(L"/");
        obstacle.time = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L",");
        obstacle.pos.x = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L"/");
        obstacle.pos.y = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L",");
        obstacle.dir.x = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L"/");
        obstacle.dir.y = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L",");
        obstacle.size.x = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        pos = txt.find(L"\n");
        obstacle.size.y = stof(txt.substr(0, pos));
        txt.erase(0, pos + 1);

        for (int i = 0; i < obstacle.size.y; i++)
        {
            obstacle.wstr += wstring(obstacle.size.x, L' ') + L"\n";
        }

        obstacles.push_back(obstacle);

        if (pos == std::string::npos) break;
    }

}

void UpdateObstacle()
{
    double playTime = PlayTime();
    for (auto& obs : obstacles)
    {
        // 생성 조건 : 시간
        if (playTime >= obs.time)
            obs.bGenerate = true;

        // 소멸 조건 : 화면 나가면
        if (obs.pos.x < 0 ||
            obs.pos.y < 0 ||
            obs.pos.x >= WIDTH ||
            obs.pos.y >= HEIGHT)
            obs.bDestroy = true;

        // 생성이 된 후 소멸되지 않은 애들만 업데이트
        if (obs.bGenerate && !obs.bDestroy)
        {
            // 이동
            obs.pos.x += obs.dir.x * GetDeltaTime() * 100;
            obs.pos.y += obs.dir.y * GetDeltaTime() * 100;

            // 그리기
            Draw(obs.wstr, to_coord(obs.pos), White, White);
        }
    }
}

void FinalObstacle()
{
    obstacles.clear();
}

vector<Obstacle> GetObstacles()
{
    return obstacles;
}