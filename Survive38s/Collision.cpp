#include "Header.h"
#include "Collision.h"

#include "Player.h"
#include "Obstacle.h"
#include "Game.h"

// obs�� �÷��̾� �浹 ����
void CollisionCheck(int i)
{
    if (!m_isCrash)
    {
        for (int k = 0; k < strlen(m_obs[i].scale); k++)
        {
            if (m_obs[i].curPos.X + k == m_pos.X && m_obs[i].curPos.Y == m_pos.Y)
            {
                m_hpCount--;
                m_isCrash = true;
            }
        }
    }
}