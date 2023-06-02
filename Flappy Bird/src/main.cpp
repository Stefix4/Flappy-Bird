#include "raylib.h"

int main(void)
{

    const int screenWidth = 900;
    const int screenHeight = 500;
    bool isFullscreen = false;
    Rectangle screen = {0,0,900,500};

    //set up the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144); 

    Image logo = LoadImage("../resources/flappy-bird-logo.png");
    Texture2D fbf = LoadTexture("../resources/flappy-bird-flaps.png");// fbf = flappy bird flaps
    Texture2D background = LoadTexture("../resources/background.png");
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    HideCursor();

    //game loop
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
            DrawTexture(fbf,screenWidth/2,screenHeight/2,WHITE);
            

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}