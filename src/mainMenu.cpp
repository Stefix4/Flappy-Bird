#include "mainMenu.hpp"
#include "movement.hpp"

#include <raylib.h>
#include <iostream>

int menuStateSelected = 0;

void mainMenu(){
    if(menuStateSelected == 0){
        DrawText( "Asta e meniu ba", 0, 0 ,20 ,BLACK );
    }
    else if(menuStateSelected == 1){
        birdJump();
        drawing();
        //DrawTexture(pill1,screenWidth/2,screenHeight/2,WHITE);
    }
    else if(menuStateSelected == 2){
        DrawText( "Optiuni", 0, 0 ,20 ,BLACK );
    }
    else if(menuStateSelected == 3)
        CloseWindow();
    
}