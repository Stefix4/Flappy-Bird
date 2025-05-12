#include <raylib.h>
#include <fstream>

#include "movement.hpp"
#include "mainMenu.hpp"
#include "game.hpp"

MenuState currentMenuState = MenuState::MENU;



int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetExitKey(KEY_NULL);
    SetTargetFPS(144);
    SetWindowMinSize(screenWidth,screenHeight);

    //declaring images/textures/font
    
    Image logo = LoadImage("./resources/images/flappy-bird-logo.png");
    SetWindowIcon(logo);
    Texture2D Start_Button=LoadTexture("./resources/images/Start_Button.png");
    Texture2D fb_flap=LoadTexture("./resources/images/flappy-bird-flaps.png");
    Texture2D pill1 =LoadTexture("./resources/images/pillar-2.png");
    Texture2D fb = LoadTexture("./resources/images/flappy-bird.png");// fb = flappy bird
    Texture2D pill2 =LoadTexture("./resources/images/pillar-1.png");
    Texture2D bg = LoadTexture("./resources/images/background2.png");
    Texture2D bg_game = LoadTexture("./resources/images/background.png");
    Texture2D Start_ButtonA = LoadTexture("./resources/images/Start_ButtonA.png");
    Texture2D Exit_Button = LoadTexture("./resources/images/Exit_Button.png");
    Texture2D Exit_ButtonA = LoadTexture("./resources/images/Exit_ButtonA.png");
    Texture2D Title_Screen = LoadTexture("./resources/images/Title_Screen.png");
    Texture2D Restart_Button = LoadTexture("./resources/images/Restart_Button.png");
    Texture2D Restart_ButtonA = LoadTexture("./resources/images/Restart_ButtonA.png");
    unsigned int fileSize = 0;
    unsigned char* fileData = LoadFileData("./resources/font/PressStart2P-Regular.ttf", &fileSize);
    Font novencento = LoadFontFromMemory(".ttf", fileData, fileSize, 40, 0, 0);
    if(novencento.texture.id == 0)
        TraceLog(LOG_ERROR, "Font not loaded!");

    const char* line1 = "Are you sure";
    const char* line2 = "you want to exit?";
    Vector2 sizeLine1 = MeasureTextEx(novencento, line1, 60, -5);
    Vector2 sizeLine2 = MeasureTextEx(novencento, line2, 60, -5);

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
        if (menuStateSelected == 1)
            currentMenuState = MenuState::PLAY;
        if (menuStateSelected == 2)
            currentMenuState = MenuState::EXIT;
        if (menuStateSelected == 3)
            currentMenuState = MenuState::GAME_OVER;
        if (menuStateSelected == 4){
            DrawTextEx(novencento,  line1, Vector2{(screenWidth - sizeLine1.x) / 2, 185}, 60, -5, WHITE);
            DrawTextEx(novencento, line2, Vector2{(screenWidth - sizeLine2.x) / 2, 250}, 60, -5, WHITE);
        }
    
    
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
    UnloadTexture(Exit_Button);
    UnloadTexture(Exit_ButtonA);
    UnloadTexture(Title_Screen);
    UnloadTexture(Restart_Button);
    UnloadTexture(Restart_ButtonA);

    CloseWindow(); 

    return 0;
}
