#include "mainMenu.hpp"
#include "movement.hpp"

#include <raylib.h>
#include <iostream>

int menuStateSelected = 0;

Rectangle fullscreenButton = { 10, 10, 120, 40 };

void mainMenu(){
    if(menuStateSelected == 0){
        DrawText( "Asta e meniu ba", 0, 0 ,20 ,BLACK );
        if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected++;
    }
    else if(menuStateSelected == 1){
        birdJump();
        drawing();
        if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected++;
        //DrawTexture(pill1,screenWidth/2,screenHeight/2,WHITE);
    }
    else if(menuStateSelected == 2){
        DrawText( "Controls", 0, 0 ,20 ,BLACK );
        if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected++;
    }
    else if(menuStateSelected == 3)
        CloseWindow();
    
}