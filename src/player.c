#include "player.h"
#include "map.h"
#include <math.h>

void InitPlayer(Player* player, float startX, float startY) {
    player->x = startX;
    player->y = startY;
    player->currentDir = DIR_NONE;
    player->nextDir = DIR_NONE;
    player->speed = 2.0f;
    player->animTimer = 0.0f;
    player->mouthAngle = 0.0f;
}

void UpdatePlayer(Player* player) {
   
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        player->nextDir = DIR_UP;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        player->nextDir = DIR_DOWN;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        player->nextDir = DIR_LEFT;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        player->nextDir = DIR_RIGHT;
    }
    
    int deltaX = 0, deltaY = 0;
    switch (player->nextDir) {
        case DIR_UP:
            deltaY = -TILE_SIZE;
            break;
        case DIR_DOWN:
            deltaY = TILE_SIZE;
            break;
        case DIR_LEFT:
            deltaX = -TILE_SIZE;
            break;
        case DIR_RIGHT:
            deltaX = TILE_SIZE;
            break;
        case DIR_NONE:
            break;
    }
    
    int nextGridX = (int)((player->x + deltaX) / TILE_SIZE);
    int nextGridY = (int)((player->y + deltaY) / TILE_SIZE);
    
    if (!IsWall(nextGridX, nextGridY)) {
        player->currentDir = player->nextDir;
    }
    
    switch (player->currentDir) {
        case DIR_UP:
            player->y -= player->speed;
            break;
        case DIR_DOWN:
            player->y += player->speed;
            break;
        case DIR_LEFT:
            player->x -= player->speed;
            break;
        case DIR_RIGHT:
            player->x += player->speed;
            break;
        case DIR_NONE:
            player->x += 0;
            break;
    }
    
    player->animTimer += 0.15f;
    player->mouthAngle = 25.0f + sinf(player->animTimer) * 20.0f;
}

void RenderPlayer(Player* player) {
    float rotation = 0.0f;
    switch (player->currentDir) {
        case DIR_UP:
            rotation = 270.0f;
            break;
        case DIR_DOWN:
            rotation = 90.0f;
            break;
        case DIR_LEFT:
            rotation = 180.0f;
            break;
        case DIR_RIGHT:
            rotation = 0.0f;
            break;
        default: rotation = 0.0f;
    }
    
    DrawCircle((int)player->x, (int)player->y, 9.0f, YELLOW);
}