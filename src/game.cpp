#include <raylib.h>
#include "movement.hpp"
#include "mainMenu.hpp"

MenuState currentMenuState = MenuState::PLAY;

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 500;

    //set up the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144); 

    Image logo = LoadImage("./resources/flappy-bird-logo.png");
    Texture2D fb = LoadTexture("./resources/flappy-bird-photo-removebg-preview.png");// fb = flappy bird 
    Texture2D background = LoadTexture("./resources/background.png");
    Texture2D pill1 = LoadTexture("./resources/pillar-1.png");
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(RAYWHITE);
        mainMenu();
        EndDrawing();
    }
    UnloadTexture(fb);
    UnloadTexture(background);
    CloseWindow();        

    return 0;
}
