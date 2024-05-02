#include "Header.h"
#include "Collision.h"

#include "Player.h"
#include "Obstacle.h"

void InitCollision()
{
}

void FixedUpdateCollision()
{
    Vector2 player = PlayerPos();
    for (auto obs : GetObstacles())
        if (obs.bGenerate && !obs.bDestroy
            && player.x >= obs.pos.x
            && player.x < obs.pos.x + obs.size.x
            && player.y >= obs.pos.y
            && player.y < obs.pos.y + obs.size.y)
            IsCrash();
}

void FinalCollision()
{
}
