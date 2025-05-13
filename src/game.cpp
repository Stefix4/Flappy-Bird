#include <raylib.h>
#include <fstream>

#include "movement.hpp"
#include "mainMenu.hpp"
#include "game.hpp"
#include "textures.hpp"

int FPS;

MenuState currentMenuState = MenuState::MENU;

Resources resources;

void loadTextures(){
    resources.logo = LoadImage("./resources/images/flappy-bird-logo.png");
    resources.Start_Button=LoadTexture("./resources/images/Start_Button.png");
    resources.fb_flap=LoadTexture("./resources/images/flappy-bird-flaps.png");
    resources.pill1 =LoadTexture("./resources/images/pillar-2.png");
    resources.fb = LoadTexture("./resources/images/flappy-bird.png");// fb = flappy bird
    resources.pill2 =LoadTexture("./resources/images/pillar-1.png");
    resources.bg = LoadTexture("./resources/images/background2.png");
    resources.bg_game = LoadTexture("./resources/images/background.png");
    resources.Start_ButtonA = LoadTexture("./resources/images/Start_ButtonA.png");
    resources.Exit_Button = LoadTexture("./resources/images/Exit_Button.png");
    resources.Exit_ButtonA = LoadTexture("./resources/images/Exit_ButtonA.png");
    resources.Title_Screen = LoadTexture("./resources/images/Title_Screen.png");
    resources.Restart_Button = LoadTexture("./resources/images/Restart_Button.png");
    resources.Restart_ButtonA = LoadTexture("./resources/images/Restart_ButtonA.png");
    resources.novencento = LoadFontFromMemory(".ttf", fileData, fileSize, 40, 0, 0);
}

void unloadTextures(){
    TraceLog(LOG_INFO, "Unloading resources...");
    UnloadTexture(resources.fb_flap);
    UnloadImage(resources.logo);
    UnloadTexture(resources.fb);
    UnloadTexture(resources.pill1);
    UnloadTexture(resources.pill2);
    UnloadTexture(resources.Start_Button);
    UnloadTexture(resources.Start_ButtonA);
    UnloadTexture(resources.bg);
    UnloadTexture(resources.bg_game);
    UnloadTexture(resources.Exit_Button);
    UnloadTexture(resources.Exit_ButtonA);
    UnloadTexture(resources.Title_Screen);
    UnloadTexture(resources.Restart_Button);
    UnloadTexture(resources.Restart_ButtonA);
    UnloadFont(resources.novencento);
    TraceLog(LOG_INFO, "Unloaded resources succesfully");
}

unsigned int fileSize = 0;
unsigned char* fileData = LoadFileData("./resources/font/PressStart2P-Regular.ttf", &fileSize);

int main(void)
{
    SetTargetFPS(144);
    
    const int screenWidth = 1280;
    const int screenHeight = 720;
    bool texture_logo = false;
    

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetExitKey(KEY_NULL);
    SetWindowMinSize(screenWidth,screenHeight);

    //declaring images/textures/font
    

    //game loop
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        draw_hb();
        ClearBackground(WHITE);

        mainMenu(resources.pill1, resources.fb, resources.fb_flap, resources.pill2, resources.Start_Button, resources.bg, resources.bg_game, resources.Start_ButtonA, resources.Exit_Button, resources.Exit_ButtonA, resources.Title_Screen, resources.Restart_Button, resources.Restart_ButtonA);
        if(!texture_logo){
            SetWindowIcon(resources.logo);
            texture_logo = true;
        }

        if(game == 1){
            if(game_over){
                game_over = false;
                reset_game();
            }
            if (menuStateSelected == 1)
                currentMenuState = MenuState::PLAY;
            if (menuStateSelected == 2)
                currentMenuState = MenuState::EXIT;
            if (menuStateSelected == 3)
                currentMenuState = MenuState::GAME_OVER;
        }
        else{
            break;
        }
    
        EndDrawing();
    }
    
    unloadTextures();
    
    TraceLog(LOG_INFO, "Closing window...");

    CloseWindow();

    TraceLog(LOG_INFO, "Exited succesfully");

    

    return 0;
}
