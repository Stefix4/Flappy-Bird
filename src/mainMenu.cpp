#include "mainMenu.hpp"
#include "movement.hpp"
#include "game.hpp"
#include "textures.hpp"

#include <raylib.h>
#include <iostream>
#include <math.h>

int game = 1;

int menuStateSelected = 0;
const int backgroundWidth = 1280;
const int backgroundHeight = 780;
bool textureloaded = false;
int skinSelected = 0;
int cadran = 1;


Rectangle StartButton_hb = {backgroundWidth / 2 - 80, backgroundHeight / 2 + 133, 156, 50};
Rectangle ExitButton_hb = {backgroundWidth - 180, backgroundHeight - 127, 156, 50};
Rectangle RestartButton_hb = {backgroundWidth / 2 - 80, backgroundHeight / 2 + 133, 156, 50};
Rectangle SkinButton_hb = {backgroundWidth / 2 - 80, backgroundHeight / 2 + 10, 156, 50};

float A = 0, B = 0, speed = 0.0f;

void animation_button(Texture2D button, float x, float y, float scale, Texture2D buttonA, int menuState, float radius, int direction = 1, float up_speed = 0.01f, Rectangle hitbox = {0, 0, 0, 0}){
    speed += up_speed;
    if(A==0 && B==0){
        A = x ;
        B = y ;
    }
    if(direction == 1){
        A =  (x + cosf(speed) * radius);
        B =  (y + sinf(speed) * cosf(speed) * radius);
    }
    else if(direction == -1){
        A =  (x + sinf(speed) * cosf(speed) * radius);
        B =  (y + cosf(speed) * radius);
    }

    DrawTextureEx(button, Vector2{A, B}, 0, scale, WHITE);
    if(hitbox.width != 0 && hitbox.height != 0){
        hitbox.x = A;
        hitbox.y = B + 50;
        if(CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(buttonA, Vector2{A, B}, 0, scale, WHITE);
            
        if(CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = menuState;
    }
}

void mainMenu(){
    if(!textureloaded && game == 1){
        loadTextures();
        textureloaded = true;
    }
    if(IsKeyPressed(KEY_ESCAPE) && menuStateSelected == 1)
        menuStateSelected = 4;
    
    if(menuStateSelected == 0){
        DrawTextureEx(resources.bg, Vector2{0, 0}, 0, 1.6f, WHITE);
        animation_button(resources.Title_Screen,backgroundWidth / 2 - 265, 0, 5.0f, resources.Title_Screen, 0, 30.0f, 1, 0.0055f);
        //Start Button animation
        animation_button(resources.Start_Button,backgroundWidth / 2 - 80, backgroundHeight / 2 + 80, 1.6f, resources.Start_ButtonA, 1, 5.0f, -1, 0.005f, StartButton_hb);
        //Exit Button animation
        animation_button(resources.Exit_Button,backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, 5.0f, -1, 0.005f, ExitButton_hb);
    }

    else if(menuStateSelected == 1){
        drawing(resources.fb, resources.fb_flap, resources.bg_game);
        birdJump();
        update_hb();
        pipe_movement(resources.pill1, resources.pill2);
        counter();
        collision();
        
    }
    else if(menuStateSelected == 3){
        const char* title = "GAME OVER";
        const char* line1 = TextFormat("Your Score:%d", final_score);
        const char* line2 = TextFormat("Highest Score is:%d", highest_score);

        DrawTextureEx(resources.bg, Vector2{0, 0}, 0, 1.6f, WHITE);
        
        Vector2 sizeTitle = MeasureTextEx(resources.novencento, title, 90, -5);
        DrawTextEx(resources.novencento, title, Vector2{(backgroundWidth - sizeTitle.x) / 2, 45}, 90, -5, WHITE);
        
        Vector2 sizeLine1 = MeasureTextEx(resources.novencento, line1, 50, -3);
        DrawTextEx(resources.novencento, line1, Vector2{(backgroundWidth - sizeLine1.x) / 2, 245}, 50, -3, WHITE);
        
        Vector2 sizeLine2 = MeasureTextEx(resources.novencento, line2, 50, -3);
        DrawTextEx(resources.novencento, line2, Vector2{(backgroundWidth - sizeLine2.x) / 2, 320}, 50, -3, WHITE);
        
        //Restart Button animation
        animation_button(resources.Restart_Button,backgroundWidth / 2 - 80, backgroundHeight / 2 + 80, 1.6f, resources.Restart_ButtonA, 0, 5.0f, -1, 0.005f, RestartButton_hb);

        //Exit Button animation
        animation_button(resources.Exit_Button,backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, 5.0f, -1, 0.005f, ExitButton_hb);
    }
    else if(menuStateSelected == 4){
        const char* title = "GAME PAUSED";
        const char* line1 = "Are you sure";
        const char* line2 = "you want to exit?";

        DrawTextureEx(resources.bg,Vector2{0,0},0,1.6f,WHITE);

        Vector2 sizeTitle = MeasureTextEx(resources.novencento, title, 80, -5);
        DrawTextEx(resources.novencento, title, Vector2{(backgroundWidth - sizeTitle.x) / 2, 45}, 80, -5, WHITE);      

        Vector2 sizeLine1 = MeasureTextEx(resources.novencento, line1, 50, -4);
        DrawTextEx(resources.novencento, line1, Vector2{(backgroundWidth - sizeLine1.x) / 2, 245}, 50, -4, WHITE);

        Vector2 sizeLine2 = MeasureTextEx(resources.novencento, line2, 50, -4);
        DrawTextEx(resources.novencento, line2, Vector2{(backgroundWidth - sizeLine2.x) / 2, 320}, 50, -4, WHITE);

        //Restart Button animation
        animation_button(resources.Restart_Button,backgroundWidth / 2 - 80, backgroundHeight / 2 + 80, 1.6f, resources.Restart_ButtonA, 0, 5.0f, -1, 0.005f, RestartButton_hb);

        //Exit Button animation
        animation_button(resources.Exit_Button,backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, 5.0f, -1, 0.005f, ExitButton_hb);
    }
    else if(menuStateSelected == 2){
        game = 0;
        EndDrawing();
    }
    else if(menuStateSelected == 5){
        // DrawText("Loading...", 500, 350, 50, BLACK);
        // loadTextures();
        // menuStateSelected = 0;
    }
    }
