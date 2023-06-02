#include "raylib.h"

int main(void)
{

    const int screenWidth = 900;
    const int screenHeight = 500;
    bool isFullscreen = false;

    InitWindow(screenWidth,screenHeight, "Flappy Bird");

    Image logo = LoadImage("../resources/flappy-bird-logo.png");
    Texture2D fbf_tx = LoadTexture("../resources/flappy-bird-flaps.png");// fbf_tx = flappy bird flaps texture
    Texture2D background = LoadTexture("../resources/background.png");
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    
    SetTargetFPS(144);               

    while (!WindowShouldClose())    
    {
        if (IsKeyPressed(KEY_F11)){
            isFullscreen = !isFullscreen;
        
        if(isFullscreen)
            ToggleFullscreen();
        else{
            SetWindowSize(screenWidth, screenHeight);
            ToggleFullscreen();
        }
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(background,0,0,WHITE);
            DrawTexture(fbf_tx,0,0,WHITE);
            

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}