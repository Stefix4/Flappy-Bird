#include <raylib.h>
#include "movement.hpp"
#include "fullscreen.hpp"


int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 500;
    bool isFullscreen = false;
    Rectangle screen = {0,0,900,500};

    //set up the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144); 

    Image logo = LoadImage("./resources/flappy-bird-logo.png");
    Texture2D fb = LoadTexture("./resources/flappy-bird-photo-removebg-preview.png");// fb = flappy bird 
    Texture2D background = LoadTexture("./resources/background.png");
    Texture2D pill1 = LoadTexture("./resources/pillar-1.png");
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    HideCursor();
    //game loop
    while (!WindowShouldClose())
    {   
        birdJump();
        if (IsKeyPressed(KEY_F11))
                ToggleFullScreenWindow(screenWidth, screenHeight);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        drawing();
        //DrawTexture(pill1,screenWidth/2,screenHeight/2,WHITE);
        EndDrawing();
    }

    CloseWindow();        

    return 0;
}
