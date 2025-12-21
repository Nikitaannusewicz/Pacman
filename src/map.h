#ifndef MAP_H
#define MAP_H
#include <stdbool.h>
#include "raylib.h"

#define TILE_SIZE 20
#define MAP_WIDTH 28
#define MAP_HEIGHT 31

typedef enum {
    TILE_EMPTY = ' ',
    TILE_WALL = 'W',
    TILE_DOT = '.',
    TILE_POWER = 'P'
} TileType;

void InitMap(void);
void RenderMap(void);
bool IsWall(int x, int y);
TileType GetTileAt(int x, int y);

#endif