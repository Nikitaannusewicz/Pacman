#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef enum {
    DIR_NONE = 0,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

typedef struct {
    float x;
    float y;
    Direction currentDir;
    Direction nextDir;
    float speed;
    float animTimer;
    float mouthAngle;
} Player;

void InitPlayer(Player* player, float startX, float startY);
void UpdatePlayer(Player* player);
void RenderPlayer(Player* player);

#endif