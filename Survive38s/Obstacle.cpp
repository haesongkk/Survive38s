#include "Header.h"
#include "Obstacle.h"

#include "Render.h"
#include "Time.h"
#include "Collision.h"
const int obsMoveSpeed = 1;

Obstacle m_obs[171];



// obs 이동 방향 적용 : 오른쪽 0 왼쪽 1 아래 2 위 3
void UpdateObstacle(int i)
{
    m_obs[i].prePos = m_obs[i].curPos;

    switch (m_obs[i].direction)
    {
        case(0):
            m_obs[i].curPos.X++;
            break;
        case(1):
            m_obs[i].curPos.X--;
            break;
        case(2):
            m_obs[i].curPos.Y++;
            break;
        case(3):
            m_obs[i].curPos.Y--;
            break;
        case(4):
            m_obs[i].curPos.X++;
            m_obs[i].curPos.Y++;
            break;
        case(5):
            m_obs[i].curPos.X++;
            m_obs[i].curPos.Y--;
            break;
        case(6):
            m_obs[i].curPos.X--;
            m_obs[i].curPos.Y++;
            break;
        case(7):
            m_obs[i].curPos.X--;
            m_obs[i].curPos.Y--;
            break;
    }
}


// obs 생성 위치 적용 & draw 
void updateObsDraw(int i)
{
    // 이전 위치 삭제

    if (m_obs[i].prePos.Y > playerMovableRect.bottom)
    {
        m_obs[i].prePos.Y = playerMovableRect.top;
    }

    Draw(m_obs[i].scale, m_obs[i].prePos, Black, Black);


    // 화면 벗어나면 끝
    if (m_obs[i].curPos.X >= playerMovableRect.right)
    {
        m_obs[i].curPos.X = playerMovableRect.right;
        return;
    }
    if (m_obs[i].curPos.X <= playerMovableRect.left)
    {
        m_obs[i].curPos.X = playerMovableRect.left;
        return;
    }
    if (m_obs[i].curPos.Y > playerMovableRect.bottom)
    {
        //obs[i].prePos.Y = playerMovableRect.Bottom + 1;
        m_obs[i].curPos.Y = playerMovableRect.bottom + 1;

    }
    if (m_obs[i].curPos.Y <= playerMovableRect.top)
    {
        m_obs[i].curPos.Y = playerMovableRect.top;
        return;
    }



    // 현재 위치 표시
    Draw(m_obs[i].scale, m_obs[i].curPos, White, Black);



}

// obs 이동 속도 적용 &  & 다른 obs 함수들 호출
void updateObsMove(int i)
{
    static ULONGLONG time;
    time += GetDeltaTime();

    if (time >= m_obs[i].speed)
    {
        UpdateObstacle(i);
        updateObsDraw(i);
        CollisionCheck(i);
        time -= m_obs[i].speed;
    }

}

// obs 생성 시간 적용
void generateObs()
{
    static ULONGLONG time = 0;
    time += GetDeltaTime();

    for (int i = 0; i < 171; i++)
    {
        if (time >= m_obs[i].time)
        {
            updateObsMove(i);
        }
    }

}

// obs 기본값 설정
void InitObstacle()
{
    // 초코비 원샷하기
    {
        m_obs[0].time = 350;
        m_obs[0].curPos.X = screenPoint[1].X - 10;
        m_obs[0].curPos.Y = screenPoint[1].Y;
        m_obs[0].speed = 30;
        m_obs[0].direction = 2;
        m_obs[0].scale = "                                             ";

        m_obs[1].time = 550;
        m_obs[1].curPos.X = screenPoint[3].X;
        m_obs[1].curPos.Y = screenPoint[1].Y;
        m_obs[1].speed = 20;
        m_obs[1].direction = 2;
        m_obs[1].scale = "                                             ";

        m_obs[2].time = 750;
        m_obs[2].curPos.X = screenPoint[1].X;
        m_obs[2].curPos.Y = screenPoint[1].Y;
        m_obs[2].speed = 20;
        m_obs[2].direction = 2;
        m_obs[2].scale = "                                             ";
    }


    // 상자를 머리위로 높이들어서
    for (int i = 3; i < 11; i++)
    {

        if (i == 8 || i == 9)
        {
            m_obs[i].speed = 1;
        }
        else
        {
            m_obs[i].speed = 10;
        }

        m_obs[i].time = 1500;
        m_obs[i].curPos = screenPoint[13];
        m_obs[i].direction = i % 8;
        m_obs[i].scale = "  ";

    }
    for (int i = 11; i < 19; i++)
    {

        if (i == 16 || i == 17)
        {
            m_obs[i].speed = 1;
        }
        else
        {
            m_obs[i].speed = 10;
        }

        m_obs[i].time = 2100;
        m_obs[i].curPos = screenPoint[20];
        m_obs[i].direction = i % 8;
        m_obs[i].scale = "  ";

    }
    for (int i = 20; i < 28; i++)
    {

        if (i == 24 || i == 25)
        {
            m_obs[i].speed = 1;
        }
        else
        {
            m_obs[i].speed = 10;
        }

        m_obs[i].time = 2700;
        m_obs[i].curPos = screenPoint[16];
        m_obs[i].direction = i % 8;
        m_obs[i].scale = "  ";

    }

    // 전주
    for (int i = 28; i < 56; i++)
    {
        m_obs[i].time = (i - 28) * 720 + 4200;
        m_obs[i].curPos = screenPoint[24];
        m_obs[i].speed = 10;
        m_obs[i].direction = 0;
        m_obs[i].scale = "  ";
    }

    // 마음속의 외침
    for (int i = 56; i < 78; i++)
    {
        m_obs[i].time = (i - 56) * 25 + 9500;
        m_obs[i].curPos.Y = screenPoint[0].Y;
        m_obs[i].speed = 100;
        m_obs[i].direction = 2;
        m_obs[i].scale = "  ";

        m_obs[56].curPos.X = screenPoint[2].X;
        m_obs[57].curPos.X = screenPoint[2].X + 2;
        m_obs[58].curPos.X = screenPoint[2].X + 4;
        m_obs[59].curPos.X = screenPoint[2].X + 6;
        m_obs[60].curPos.X = screenPoint[2].X + 8;

        m_obs[61].curPos.X = screenPoint[4].X;
        m_obs[62].curPos.X = screenPoint[4].X + 2;
        m_obs[63].curPos.X = screenPoint[4].X + 4;
        m_obs[64].curPos.X = screenPoint[4].X + 6;
        m_obs[65].curPos.X = screenPoint[4].X + 8;

        m_obs[66].curPos.X = screenPoint[1].X;
        m_obs[67].curPos.X = screenPoint[1].X + 2;
        m_obs[68].curPos.X = screenPoint[1].X + 4;
        m_obs[69].curPos.X = screenPoint[1].X + 6;
        m_obs[70].curPos.X = screenPoint[1].X + 8;

        m_obs[71].curPos.X = screenPoint[3].X;
        m_obs[72].curPos.X = screenPoint[3].X + 2;
        m_obs[73].curPos.X = screenPoint[3].X + 4;
        m_obs[74].curPos.X = screenPoint[3].X + 6;
        m_obs[75].curPos.X = screenPoint[3].X + 8;

        m_obs[76].curPos.X = screenPoint[2].X + 8;
        m_obs[77].curPos.X = screenPoint[2].X;
    }

    // 짱돌
    for (int i = 78; i < 82; i++)
    {

        m_obs[i].time = (i - 78) * 200 + 15700;
        m_obs[i].curPos.Y = screenPoint[1].Y;
        m_obs[i].speed = 10;
        m_obs[i].direction = 2;
        m_obs[i].scale = "    ";

        m_obs[78].curPos.X = screenPoint[1].X;
        m_obs[79].curPos.X = screenPoint[3].X;
        m_obs[80].curPos.X = screenPoint[2].X;
        m_obs[81].curPos.X = screenPoint[4].X;
    }
    for (int i = 82; i < 86; i++)
    {

        m_obs[i].time = (i - 82) * 200 + 17100;
        m_obs[i].curPos.Y = screenPoint[1].Y;
        m_obs[i].speed = 10;
        m_obs[i].direction = 2;
        m_obs[i].scale = "    ";

        m_obs[82].curPos.X = screenPoint[1].X + 8;
        m_obs[83].curPos.X = screenPoint[3].X + 8;
        m_obs[84].curPos.X = screenPoint[2].X + 8;
        m_obs[85].curPos.X = screenPoint[4].X + 8;
    }
    for (int i = 86; i < 90; i++)
    {

        m_obs[i].time = (i - 86) * 200 + 18500;
        m_obs[i].curPos.Y = screenPoint[1].Y;
        m_obs[i].speed = 10;
        m_obs[i].direction = 2;
        m_obs[i].scale = "    ";

        m_obs[86].curPos.X = screenPoint[1].X;
        m_obs[87].curPos.X = screenPoint[3].X + 4;
        m_obs[88].curPos.X = screenPoint[2].X + 4;
        m_obs[89].curPos.X = screenPoint[4].X + 8;
    }

    // 맷돌
    for (int i = 90; i < 98; i += 2)
    {
        m_obs[i].time = (i - 90) * 100 + 21500;
        m_obs[i + 1].time = (i - 90) * 100 + 21500;

        m_obs[i].curPos.X = screenPoint[18].X;
        m_obs[i + 1].curPos.X = screenPoint[18].X;

        m_obs[i].speed = 10;
        m_obs[i + 1].speed = 10;

        m_obs[i].direction = 0;
        m_obs[i + 1].direction = 0;

        m_obs[i].scale = "    ";
        m_obs[i + 1].scale = "    ";

        m_obs[90].curPos.Y = screenPoint[18].Y;
        m_obs[91].curPos.Y = screenPoint[18].Y + 1;

        m_obs[92].curPos.Y = screenPoint[6].Y;
        m_obs[93].curPos.Y = screenPoint[6].Y + 1;

        m_obs[94].curPos.Y = screenPoint[18].Y;
        m_obs[95].curPos.Y = screenPoint[18].Y + 1;

        m_obs[96].curPos.Y = screenPoint[6].Y;
        m_obs[97].curPos.Y = screenPoint[6].Y + 1;
    }
    for (int i = 98; i < 105; i += 2)
    {
        m_obs[i].time = (i - 98) * 100 + 22900;
        m_obs[i + 1].time = (i - 98) * 100 + 22900;

        m_obs[i].curPos.X = screenPoint[18].X;
        m_obs[i + 1].curPos.X = screenPoint[18].X;

        m_obs[i].speed = 10;
        m_obs[i + 1].speed = 10;

        m_obs[i].direction = 0;
        m_obs[i + 1].direction = 0;

        m_obs[i].scale = "    ";
        m_obs[i + 1].scale = "    ";

        m_obs[98].curPos.Y = screenPoint[18].Y + 2;
        m_obs[99].curPos.Y = screenPoint[18].Y + 3;

        m_obs[100].curPos.Y = screenPoint[12].Y + 2;
        m_obs[101].curPos.Y = screenPoint[12].Y + 3;

        m_obs[102].curPos.Y = screenPoint[18].Y + 2;
        m_obs[103].curPos.Y = screenPoint[18].Y + 3;

        m_obs[104].curPos.Y = screenPoint[12].Y + 2;
        m_obs[105].curPos.Y = screenPoint[12].Y + 3;
    }
    for (int i = 106; i < 120; i++)
    {
        m_obs[i].time = 25000;
        m_obs[i].curPos.X = screenPoint[23].X - 40;
        m_obs[i].speed = 10;
        m_obs[i].direction = 1;
        m_obs[i].scale = "                                       ";

        m_obs[i].curPos.Y = screenPoint[23].Y - i + 106;
    }

    // 초코비 2트
    {
        m_obs[120].time = 25200;
        m_obs[120].curPos.X = screenPoint[1].X;
        m_obs[120].curPos.Y = screenPoint[1].Y;
        m_obs[120].speed = 20;
        m_obs[120].direction = 2;
        m_obs[120].scale = "                                             ";

        m_obs[121].time = 25400;
        m_obs[121].curPos.X = screenPoint[3].X;
        m_obs[121].curPos.Y = screenPoint[1].Y;
        m_obs[121].speed = 20;
        m_obs[121].direction = 2;
        m_obs[121].scale = "                                             ";

        m_obs[122].time = 25600;
        m_obs[122].curPos.X = screenPoint[1].X;
        m_obs[122].curPos.Y = screenPoint[1].Y;
        m_obs[122].speed = 20;
        m_obs[122].direction = 2;
        m_obs[122].scale = "                                             ";
    }

    // 아원츄베이베
    for (int i = 123; i < 131; i++)
    {
        m_obs[i].time = (i - 123) * 100 + 27000;
        m_obs[i].speed = 10;
        m_obs[i].direction = 4;
        m_obs[i].scale = "  ";

        m_obs[123].curPos = screenPoint[12];
        m_obs[124].curPos = screenPoint[6];
        m_obs[125].curPos = screenPoint[1];
        m_obs[126].curPos = screenPoint[2];
        m_obs[127].curPos = screenPoint[6];
        m_obs[128].curPos = screenPoint[12];
        m_obs[129].curPos = screenPoint[2];
        m_obs[130].curPos = screenPoint[1];
    }

    // 아니쥬베이베
    for (int i = 131; i < 139; i++)
    {
        m_obs[i].time = (i - 131) * 100 + 28500;
        m_obs[i].speed = 10;
        m_obs[i].direction = 6;
        m_obs[i].scale = "  ";

        m_obs[131].curPos = screenPoint[3];
        m_obs[132].curPos = screenPoint[4];
        m_obs[133].curPos = screenPoint[11];
        m_obs[134].curPos = screenPoint[17];
        m_obs[135].curPos = screenPoint[4];
        m_obs[136].curPos = screenPoint[3];
        m_obs[137].curPos = screenPoint[17];
        m_obs[138].curPos = screenPoint[11];
    }

    // 알러뷰베이베
    for (int i = 139; i < 171; i += 2)
    {
        m_obs[i].time = (i - 139) * 100 + 30000;
        m_obs[i + 1].time = (i + 1 - 139) * 100 + 30000;
        m_obs[i].speed = 10;
        m_obs[i + 1].speed = 10;

        m_obs[i].direction = 6;
        m_obs[i + 1].direction = 4;

        m_obs[i].scale = "  ";
        m_obs[i + 1].scale = "  ";

        m_obs[139].curPos = screenPoint[3];
        m_obs[141].curPos = screenPoint[4];
        m_obs[143].curPos = screenPoint[11];
        m_obs[145].curPos = screenPoint[17];
        m_obs[147].curPos = screenPoint[4];
        m_obs[149].curPos = screenPoint[3];
        m_obs[151].curPos = screenPoint[17];
        m_obs[153].curPos = screenPoint[11];
        m_obs[155].curPos = screenPoint[3];
        m_obs[157].curPos = screenPoint[4];
        m_obs[159].curPos = screenPoint[11];
        m_obs[161].curPos = screenPoint[17];
        m_obs[163].curPos = screenPoint[4];
        m_obs[165].curPos = screenPoint[3];
        m_obs[167].curPos = screenPoint[17];
        m_obs[169].curPos = screenPoint[11];

        m_obs[140].curPos = screenPoint[12];
        m_obs[142].curPos = screenPoint[6];
        m_obs[144].curPos = screenPoint[1];
        m_obs[146].curPos = screenPoint[2];
        m_obs[148].curPos = screenPoint[6];
        m_obs[150].curPos = screenPoint[12];
        m_obs[152].curPos = screenPoint[2];
        m_obs[154].curPos = screenPoint[1];
        m_obs[156].curPos = screenPoint[12];
        m_obs[158].curPos = screenPoint[6];
        m_obs[160].curPos = screenPoint[1];
        m_obs[162].curPos = screenPoint[2];
        m_obs[164].curPos = screenPoint[6];
        m_obs[166].curPos = screenPoint[12];
        m_obs[168].curPos = screenPoint[2];
        m_obs[170].curPos = screenPoint[1];
    }


    for (int i = 0; i < 171; i++)
    {
        m_obs[i].prePos = m_obs[i].curPos;
    }
}