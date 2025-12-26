#include <stdio.h>
#include "raylib.h"
#include "map.h"
#include "player.h"

int main(void)
{
   InitWindow(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Pac-Man - Milestone 1");
   SetTargetFPS(60);
   
   Player pacman;
   InitPlayer(&pacman, 15 * TILE_SIZE, 23 * TILE_SIZE);
   
   while (!WindowShouldClose())
   {
      UpdatePlayer(&pacman);
      BeginDrawing();
         ClearBackground(BLACK);
         RenderMap();
         RenderPlayer(&pacman);
      EndDrawing();
   }
   
   CloseWindow();

   return 0;
}