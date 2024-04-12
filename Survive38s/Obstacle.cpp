#include "Header.h"
#include "Obstacle.h"

#include "Render.h"
#include "Game.h"
#include "Resource.h"

vector<Obstacle> obstacles;

void InitObstacle()
{
    assert(obstacles.empty());
    LoadTxt();
    wstring txt = GetTxt(L"obstacles");
    while (true)
    {
        wstring delimiter1(L"\n"), delimiter2(L"/");
        int pos = txt.find(L"\n");
        wstring obsInfo = txt.substr(0, pos);

        Obstacle obstacle;

        pos = obsInfo.find(L"/");
        obstacle.time = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L",");
        obstacle.pos.x = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L"/");
        obstacle.pos.y = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L",");
        obstacle.dir.x = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L"/");
        obstacle.dir.y = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L",");
        obstacle.size.x = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

        pos = obsInfo.find(L"\n");
        obstacle.size.y = stof(obsInfo.substr(0, pos));
        obsInfo.erase(0, pos + 1);

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
        if (obs.pos.x <= 0 ||
            obs.pos.y <= 0 ||
            obs.pos.x >= WIDTH ||
            obs.pos.y >= HEIGHT)
            obs.bDestroy = true;

        // 생성이 된 후 소멸되지 않은 애들만 업데이트
        if (obs.bGenerate && !obs.bDestroy)
        {
            // 이동
            obs.pos.x += obs.dir.x * 2;
            obs.pos.y += obs.dir.y;

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