#include <stdio.h>
#include "map.h"

static char gameMap[MAP_HEIGHT][MAP_WIDTH] = {
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "W                          W",
    "W WWWWWWWWWWWWWWWWWWWWWWWW W",
    "W W                        W",
    "W W WWWWWWWWWWWWWWWWWWWWWW W",
    "W W W                    W W",
    "W W W WWWWWWWWWWWWWWWWWW W W",
    "W W W W                W W W",
    "W W W W WWWWWWWWWWWWWW W W W",
    "W W W W W            W W W W",
    "W         WWWWWWWWWW W W W W",
    "W W W W W W        W W W W W",
    "W W W W W W WWWWWW W W W W W",
    "W W W W W W W    W W W W W W",
    "W W W W W W W WW W W W W W W",
    "W W W W W W W WW W W W W W W",
    "W W W W W W W    W W W W W W",
    "W W W W W W WWWWWW W W W W W",
    "W W W W W W        W W W W W",
    "W W W W W WWWWWWWWWW W W W W",
    "W W W W W            W W W W",
    "W W W W WWWWWWWWWWWWWW W W W",
    "W W W W                W W W",
    "W W W WWWWWWWWWWWWWWWWWW W W",
    "W W W                    W W",
    "W W WWWWWWWWWWWWWWWWWWWWWW W",
    "W W                        W",
    "W WWWWWWWWWWWWWWWWWWWWWWWW W",
    "W                          W",
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
};

void InitMap(void)
{
    printf("Map initialized %d x %d\n", (MAP_WIDTH - 1), MAP_HEIGHT);
}

void RenderMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            const TileType tile = GetTileAt(x, y);

            if (tile == TILE_WALL)
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
        }
    }
}

bool IsWall(int x, int y) 
{
    if (x < 0 || x >= MAP_WIDTH)
        return true;
    else if (y < 0 || y >= MAP_HEIGHT)
        return true;
    
    if (gameMap[y][x] == 'W') {
        return true;
    }
    return false;
}

TileType GetTileAt(int x, int y)
{
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
        return TILE_WALL;

    return (TileType)gameMap[y][x];
}