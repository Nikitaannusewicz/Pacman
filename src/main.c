#include <stdio.h>
#include "raylib.h"
#include "map.h"

int main(void)
{
   InitWindow(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Pac-Man - Milestone 1");
   SetTargetFPS(60);

   while (!WindowShouldClose())
   {
      // UpdateGame();
      BeginDrawing();
         ClearBackground(BLACK);
         RenderMap();
      EndDrawing();
   }
   
   CloseWindow();

   return 0;
}