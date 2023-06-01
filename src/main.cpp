#include "raylib.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");


    Texture2D fbf_tx = LoadTexture("../src/resources/flappy-bird-flaps.png");// fbf_tx = flappy bird flaps texture

    SetTargetFPS(60);               

    while (!WindowShouldClose())    
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(fbf_tx,0,0,WHITE);

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}