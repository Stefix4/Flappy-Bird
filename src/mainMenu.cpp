#include "mainMenu.hpp"
#include "movement.hpp"
#include "game.hpp"
#include "textures.hpp"

#include <raylib.h>
#include <iostream>

int game = 1;

int menuStateSelected = 0;
const int backgroundWidth = 1280;
const int backgroundHeight = 780;
bool textureloaded = false;

Rectangle StartButton_hb = { backgroundWidth/2-80,backgroundHeight/2+133, 156, 50};
Rectangle ExitButton_hb = { backgroundWidth/2-80,backgroundHeight/2+203, 156, 50};
Rectangle RestartButton_hb = { backgroundWidth/2-80,backgroundHeight/2+133, 156, 50};


void mainMenu(Texture2D pill1,Texture2D fb,Texture2D fb_flap,Texture2D pill2,Texture2D Start_Button,Texture2D bg,Texture2D bg_game, Texture2D Start_ButtonA, Texture2D Exit_Button, Texture2D Exit_ButtonA, Texture2D Title_Screen, Texture2D Restart_Button, Texture2D Restart_ButtonA){
    if(!textureloaded && game == 1){
        loadTextures();
        textureloaded = true;
    }
    if(IsKeyPressed(KEY_ESCAPE) && menuStateSelected == 1)
        menuStateSelected = 4;
    
    if(menuStateSelected == 0){
        DrawTextureEx(bg,Vector2{0,0},0,1.6f,WHITE);
        DrawTextureEx(Start_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        DrawTextureEx(Exit_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);
        DrawTextureEx(Title_Screen,Vector2{backgroundWidth/2-265, 0},0,5.0f,WHITE);
        
        //Start Button animation
        if(CheckCollisionPointRec(GetMousePosition(), StartButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Start_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), StartButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 1;

        //Exit Button animation
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Exit_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 2;
    }

    else if(menuStateSelected == 1){
        drawing(fb,fb_flap,bg_game);
        birdJump();
        update_hb();
        pipe_movement(pill1,pill2);
        counter();
        collision();
        
    }
    else if(menuStateSelected == 3){
        const char* title = "GAME OVER";
        const char* line1 = TextFormat("Your Score:%d", final_score);
        const char* line2 = TextFormat("Highest Score is:%d", highest_score);
        DrawTextureEx(bg,Vector2{0,0},0,1.6f,WHITE);
        Vector2 sizeTitle = MeasureTextEx(resources.novencento, title, 90, -5);
        DrawTextEx(resources.novencento, title, Vector2{(backgroundWidth - sizeTitle.x) / 2, 45}, 90, -5, WHITE);
        Vector2 sizeLine1 = MeasureTextEx(resources.novencento, line1, 50, -3);
        DrawTextEx(resources.novencento, line1, Vector2{(backgroundWidth - sizeLine1.x) / 2, 245}, 50, -3, WHITE);
        Vector2 sizeLine2 = MeasureTextEx(resources.novencento, line2, 50, -3);
        DrawTextEx(resources.novencento, line2, Vector2{(backgroundWidth - sizeLine2.x) / 2, 320}, 50, -3, WHITE);
        DrawTextureEx(Restart_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        DrawTextureEx(Exit_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);

        //Restart Button animation
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Restart_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 1;

        //Exit Button animation
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Exit_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 2;
    }
    else if(menuStateSelected == 4){
        const char* title = "GAME PAUSED";
        const char* line1 = "Are you sure";
        const char* line2 = "you want to exit?";
        DrawTextureEx(bg,Vector2{0,0},0,1.6f,WHITE);
        Vector2 sizeTitle = MeasureTextEx(resources.novencento, title, 80, -5);
        DrawTextEx(resources.novencento, title, Vector2{(backgroundWidth - sizeTitle.x) / 2, 45}, 80, -5, WHITE);       
        Vector2 sizeLine1 = MeasureTextEx(resources.novencento, line1, 50, -4);
        DrawTextEx(resources.novencento, line1, Vector2{(backgroundWidth - sizeLine1.x) / 2, 245}, 50, -4, WHITE);
        Vector2 sizeLine2 = MeasureTextEx(resources.novencento, line2, 50, -4);
        DrawTextEx(resources.novencento, line2, Vector2{(backgroundWidth - sizeLine2.x) / 2, 320}, 50, -4, WHITE);
        DrawTextureEx(Restart_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        DrawTextureEx(Exit_Button,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);

        //Restart Button animation
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Restart_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+80},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 1;

        //Exit Button animation
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Exit_ButtonA,Vector2{backgroundWidth/2-80,backgroundHeight/2+150},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = 2;
    }
    else if(menuStateSelected == 2){
        game = 0;
        EndDrawing();
    }
    }
