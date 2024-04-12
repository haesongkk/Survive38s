#include "Header.h"

#include "Time.h"

ULONGLONG previousTime = 0;
ULONGLONG currentTime = 0;
ULONGLONG deltaTime = 0;

void InitTime()
{
    currentTime = previousTime = GetTickCount64();
    deltaTime = 0;
}

void UpdateTime()
{
    previousTime = currentTime;
    currentTime = GetTickCount64();
    deltaTime = currentTime - previousTime;
}

void FinalTime()
{
}

double GetDeltaTime()
{
    return deltaTime * 0.001;
}
