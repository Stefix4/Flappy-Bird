#include "raylib.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth,screenHeight, "Flappy Bird");


    Texture2D fbf_tx = LoadTexture("../resources/flappy-bird-flaps.png");// fbf_tx = flappy bird flaps texture
    Texture2D background = LoadTexture("../resources/background.png");
    
    SetTargetFPS(144);               

    while (!WindowShouldClose())    
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(background,0,0,WHITE);
            DrawTexture(fbf_tx,0,0,WHITE);
            

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}