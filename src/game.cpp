#include <raylib.h>
#include <fstream>

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
    Texture2D pill2 =LoadTexture("./resources/pillar-1.png");
    Texture2D bg = LoadTexture("./resources/background2.png");
    Texture2D bg_game = LoadTexture("./resources/background.png");
    Texture2D Start_ButtonA = LoadTexture("./resources//Start_ButtonA.png");
    Texture2D Exit_Button = LoadTexture("./resources//Exit_Button.png");
    Texture2D Exit_ButtonA = LoadTexture("./resources//Exit_ButtonA.png");
    Texture2D Title_Screen = LoadTexture("./resources//Title_Screen.png");
    Texture2D Restart_Button = LoadTexture("./resources//Restart_Button.png");
    Texture2D Restart_ButtonA = LoadTexture("./resources//Restart_ButtonA.png");
    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        draw_hb();
        ClearBackground(WHITE);
        
        mainMenu(pill1, fb, fb_flap, pill2, Start_Button, bg, bg_game, Start_ButtonA, Exit_Button, Exit_ButtonA, Title_Screen, Restart_Button, Restart_ButtonA);

        if(game_over){
            game_over=false;
            reset_game();
        }

        if (menuStateSelected==1)
            currentMenuState = MenuState::PLAY;
         
        if (menuStateSelected==2)
            currentMenuState = MenuState::EXIT;
        if (menuStateSelected==3)
             currentMenuState = MenuState::GAME_OVER;
    
    
        EndDrawing();
    }

    UnloadTexture(fb_flap);
    UnloadImage(logo);
    UnloadTexture(fb);
    UnloadTexture(pill1);
    UnloadTexture(Start_Button);
    UnloadTexture(Start_ButtonA);
    UnloadTexture(bg);
    UnloadTexture(bg_game);
    UnloadTexture(Start_Button);
    UnloadTexture(Start_ButtonA);
    UnloadTexture(Exit_Button);
    UnloadTexture(Exit_ButtonA);
    UnloadTexture(Title_Screen);
    UnloadTexture(Restart_Button);
    UnloadTexture(Restart_ButtonA);

    CloseWindow();        

    return 0;
}
