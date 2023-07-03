#include <raylib.h>
#include "movement.hpp"
#include "mainMenu.hpp"

MenuState currentMenuState = MenuState::PLAY;

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 780;

    //declaring images/textures
    Image logo = LoadImage("./resources/flappy-bird-logo.png");
    //Texture2D pill1 = LoadTexture("./resources/pillar-1.png");

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    //SetTargetFPS(144); 
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetWindowIcon(logo);
    SetWindowMinSize(screenWidth,screenHeight);
    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(WHITE);
        mainMenu();
        EndDrawing();
    }
    CloseWindow();        

    return 0;
}
