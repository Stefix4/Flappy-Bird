#include "mainMenu.hpp"
#include "movement.hpp"
#include "game.hpp"

#include <raylib.h>
#include <iostream>

int menuStateSelected = 0;
const int backgroundWidth = 1280;
const int backgroundHeight = 780;


Rectangle StartButton_hb = { backgroundWidth/2-97,backgroundHeight/2+133, 156, 50};
Rectangle ExitButton_hb = { backgroundWidth/2-97,backgroundHeight/2+203, 156, 50};
Rectangle RestartButton_hb = { backgroundWidth/2-97,backgroundHeight/2+133, 156, 50};

void mainMenu(Texture2D pill1,Texture2D fb,Texture2D fb_flap,Texture2D pill2,Texture2D Start_Button,Texture2D bg,Texture2D bg_game, Texture2D Start_ButtonA, Texture2D Exit_Button, Texture2D Exit_ButtonA, Texture2D Title_Screen, Texture2D Restart_Button, Texture2D Restart_ButtonA){
    if(menuStateSelected == 0){
        DrawTextureEx(bg,Vector2{0,0},0,1.6f,WHITE);
        DrawTextureEx(Start_Button,Vector2{backgroundWidth/2-100,backgroundHeight/2+80},0,1.6f,WHITE);
        DrawTextureEx(Exit_Button,Vector2{backgroundWidth/2-100,backgroundHeight/2+150},0,1.6f,WHITE);
        DrawTextureEx(Title_Screen,Vector2{backgroundWidth/2-265, 0},0,5.0f,WHITE);
        
        //Start Button animation
        if(CheckCollisionPointRec(GetMousePosition(), StartButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Start_ButtonA,Vector2{backgroundWidth/2-100,backgroundHeight/2+80},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), StartButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected=1;

        //Exit Button animation
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Exit_ButtonA,Vector2{backgroundWidth/2-100,backgroundHeight/2+150},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected=2;
    }

    else if(menuStateSelected == 1){
        drawing(fb,fb_flap,bg_game);
        birdJump();
        update_hb();
        pipe_movement(pill1,pill2);
        counter();
        collision();
        
    }
    else if(menuStateSelected == 2)
        CloseWindow();

    else if(menuStateSelected == 3){
        DrawTextureEx(bg,Vector2{0,0},0,1.6f,WHITE);
        DrawText("GAME OVER", backgroundWidth/6-35, 0, 150, BLACK);
        DrawText(TextFormat("Your Score: %d", final_score),backgroundWidth/3-30,backgroundHeight/3,65,BLACK);
        DrawText(TextFormat("Highest Score is: %d", highest_score),backgroundWidth/3-110,backgroundHeight/3+75,65,BLACK);
        DrawTextureEx(Restart_Button,Vector2{backgroundWidth/2-100,backgroundHeight/2+80},0,1.6f,WHITE);
        DrawTextureEx(Exit_Button,Vector2{backgroundWidth/2-100,backgroundHeight/2+150},0,1.6f,WHITE);

        //Restart Button animation
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Restart_ButtonA,Vector2{backgroundWidth/2-100,backgroundHeight/2+80},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), RestartButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected=1;

        //Exit Button animation
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(Exit_ButtonA,Vector2{backgroundWidth/2-100,backgroundHeight/2+150},0,1.6f,WHITE);
        
        if(CheckCollisionPointRec(GetMousePosition(), ExitButton_hb) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected=2;
        
    }
    
}