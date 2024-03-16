#include "Header.h"

#include "Time.h"

ULONGLONG m_previousTime = 0;
ULONGLONG m_currentTime = 0;
ULONGLONG m_deltaTime = 0;

void InitTime()
{
    m_currentTime = m_previousTime = GetTickCount64();
    m_deltaTime = 0;
}

void UpdateTime()
{
    m_previousTime = m_currentTime;
    m_currentTime = GetTickCount64();
    m_deltaTime = m_currentTime - m_previousTime;
}

ULONGLONG GetDeltaTime()
{
    return m_deltaTime;
}
