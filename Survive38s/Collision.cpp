#include "Header.h"
#include "Collision.h"

#include "Player.h"
#include "Obstacle.h"

void InitCollision()
{
}

void UpdateCollision()
{
    Vector2 player = PlayerPos();
    for (auto obs : GetObstacles())
        if (player.x >= obs.pos.x
            && player.x < obs.pos.x + obs.size.x
            && player.x >= obs.pos.y
            && player.y < obs.pos.y + obs.size.y)
            IsCrash();
}

void FinalCollision()
{
}
