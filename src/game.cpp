#include <raylib.h>
#include "movement.hpp"
#include "mainMenu.hpp"

MenuState currentMenuState = MenuState::PLAY;

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 780;
    const int backgroundWidth = 1280;
    const int backgroundHeight = 780;

    //declaring images/textures
    Image bg = LoadImage("./resources/background.png");
    ImageResize(&bg, backgroundWidth, backgroundHeight);
    Texture2D background = LoadTextureFromImage(bg);
    Image logo = LoadImage("./resources/flappy-bird-logo.png");
    //Texture2D pill1 = LoadTexture("./resources/pillar-1.png");

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144); 
    SetWindowIcon(logo);

    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(WHITE);
        mainMenu();
        DrawTexture(background, 0 , 0 , WHITE);
        EndDrawing();
    }
    CloseWindow();        

    return 0;
}
