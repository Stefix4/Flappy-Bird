#include <raylib.h>
#include "movement.hpp"
#include "mainMenu.hpp"
#include "game.hpp"


MenuState currentMenuState = MenuState::MENU;

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 780;

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetTargetFPS(144);
    SetWindowMinSize(screenWidth,screenHeight);

    //declaring images/textures
    Image logo = LoadImage("./resources/flappy-bird-logo.png");
    SetWindowIcon(logo);
    Texture2D fb_flap=LoadTexture("./resources//flappy-bird-flaps.png");
    Texture2D pill1 =LoadTexture("./resources/pillar-2.1.png");
    Texture2D fb = LoadTexture("./resources/flappy-bird.png");// fb = flappy bird

    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(WHITE);
        
        mainMenu();
        if (menuStateSelected==1)
            currentMenuState = MenuState::PLAY;
        if (currentMenuState == MenuState::PLAY){
            drawing(fb, fb_flap, pill1);
    }
    
        EndDrawing();
    }

    UnloadTexture(fb_flap);
    UnloadImage(logo);
    UnloadTexture(fb);
    UnloadTexture(pill1);

    CloseWindow();        

    return 0;
}
