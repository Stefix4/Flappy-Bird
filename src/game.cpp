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
    Texture2D Start_Button=LoadTexture("./resources//Start_Button.png");
    Texture2D fb_flap=LoadTexture("./resources//flappy-bird-flaps.png");
    Texture2D pill1 =LoadTexture("./resources/pillar-2.png");
    Texture2D fb = LoadTexture("./resources/flappy-bird.png");// fb = flappy bird
    Texture2D pill2 =LoadTexture("./resources/pillar-2.2.png");
    Texture2D bg = LoadTexture("./resources/background2.png");
    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        draw_hb();
        ClearBackground(WHITE);
        
        mainMenu(pill1, fb, fb_flap, pill2, Start_Button, bg);

        if(game_over){
            game_over=false;
            reset_game();
        }

        if (menuStateSelected==1)
            currentMenuState = MenuState::PLAY;
        if (menuStateSelected==2)
            currentMenuState = MenuState::CONTRLOS;
        if (menuStateSelected==3)
            currentMenuState = MenuState::EXIT;

    
    
        EndDrawing();
    }

    UnloadTexture(fb_flap);
    UnloadImage(logo);
    UnloadTexture(fb);
    UnloadTexture(pill1);
    UnloadTexture(Start_Button);

    CloseWindow();        

    return 0;
}
