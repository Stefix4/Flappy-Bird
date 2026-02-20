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
int skinSelected = 1;
float game_music = 0.2f;
int seed = 5;
float button_speed = 0.0025f;
float button_radius = 2.5f;
int button_direction = -1;

Rectangle StartButton_hb = {0, 0, 156, 50};
Rectangle ExitButton_hb = {0, 0, 156, 50};
Rectangle RestartButton_hb = {0, 0, 156, 50};
Rectangle Options_hb = {0, 0, 156, 50};
Rectangle Skins_hb = {0, 0, 184, 130};
Rectangle Menu_Button_hb = {0, 0, 156, 50};

float A = 0, B = 0, speed = 0.0f;

void animation_button(Texture2D button, float x, float y, float scale, Texture2D buttonA, int menuState, float radius, int direction = 1, float up_speed = 0.01f, Rectangle hitbox = {0, 0, 0, 0}, int skin = 0){
    srand(seed);
    int a = rand() % 300;
    float diff = rand() %360 + a;
    speed += up_speed ; 
    speed += diff;
    if(A == 0 && B == 0){
        A = x;
        B = y;
    }
    if(direction == 1){
        A =  (x + cosf(speed) * radius);
        B =  (y + sinf(speed) * cosf(speed) * radius);
    }
    else if(direction == -1){
        A =  (x + sinf(speed) * cosf(speed) * radius);
        B =  (y + cosf(speed) * radius);
    }
    else if(direction == 2){
        speed += 90.0f;
        A =  (x + cosf(speed) * radius);
        B =  (y + sinf(speed) * cosf(speed) * radius);
        speed -= 90.0f;
    }
    else if(direction == -2){
        speed += 90.0f;
        A =  (x - sinf(speed) * cosf(speed) * radius);
        B =  (y - cosf(speed) * radius);
        speed -= 90.0f;
    }
    else if(direction == 0){
        A = x;
        B = y;
    }
     
    if(hitbox.width != 0 && hitbox.height != 0){
        hitbox.x = A;
        hitbox.y = B + 50;
        if(CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            DrawTextureEx(buttonA, Vector2{A, B}, 0, scale, WHITE);
        else
            DrawTextureEx(button, Vector2{A, B}, 0, scale, WHITE);
            
        if(CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            menuStateSelected = menuState;
    }
    else
        DrawTextureEx(button, Vector2{A, B}, 0, scale, WHITE);

    speed -= diff;
    
    button_direction= (-1) * GetRandomValue(0, 2) ;
    if(button_direction == 0)
        button_direction = -1;
    seed++;
    if(skin != 0)
        if(CheckCollisionPointRec(GetMousePosition(), hitbox) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && skinSelected != skin){
            skinSelected = skin;
            //unloadTextures();
            loadTextures();
        }
}

void mainMenu(){
    seed = 5;
    if(!textureloaded && game == 1){
        loadTextures();
        loadSounds();
        set_sounds_volume();
        textureloaded = true;
    }
    
    if(!IsMusicStreamPlaying(resources.music))
        PlayMusicStream(resources.music);
    UpdateMusicStream(resources.music);

    if(IsKeyPressed(KEY_ESCAPE) && menuStateSelected == 1)
        menuStateSelected = 4;
    if(IsKeyPressed(KEY_ESCAPE) && menuStateSelected == 0)
        menuStateSelected = 2;
    
    if(menuStateSelected == 0){
        DrawTextureEx(resources.bg, Vector2{0, 0}, 0, 1.6f, WHITE);
        animation_button(resources.Title_Screen,backgroundWidth / 2 - 230, 0, 5.0f, resources.Title_Screen, 0, 25.0f, 1, 0.0035f);
        //Start Button animation
        animation_button(resources.Start_Button,backgroundWidth / 2 - 80, backgroundHeight / 2 + 100, 1.6f, resources.Start_ButtonA, 1, button_radius, button_direction, button_speed, StartButton_hb);
        //Exit Button animation
        animation_button(resources.Exit_Button,backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, button_radius, button_direction, button_speed, ExitButton_hb);
        //Options Button animation
        animation_button(resources.Options_Button,backgroundWidth / 2 + 20, backgroundHeight - 200, 1.6f, resources.Options_ButtonA, 5, button_radius, button_direction, button_speed, Options_hb);
        //Skins Button animation
        animation_button(resources.Skins_Button,backgroundWidth / 2 - 180, backgroundHeight - 200, 1.6f, resources.Skins_ButtonA, 6, button_radius, button_direction, button_speed, Skins_hb);
    }

    else if(menuStateSelected == 1){
        SetMusicVolume(resources.music, game_music);
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
        animation_button(resources.Restart_Button, backgroundWidth / 2 - 80, backgroundHeight / 2 + 80, 1.6f, resources.Restart_ButtonA, 1, button_radius, -1, button_speed, RestartButton_hb);

        // Menu Button animation
        animation_button(resources.Menu_Button,backgroundWidth / 2 - 80, backgroundHeight - 190, 1.6f, resources.Menu_ButtonA, 0, button_radius + 2.0f, 1, button_speed + 0.015f, Menu_Button_hb);

        //Exit Button animation
        animation_button(resources.Exit_Button, backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, button_radius, -1, button_speed, ExitButton_hb);
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
        animation_button(resources.Resume_Button,backgroundWidth / 2 - 80, backgroundHeight / 2 + 80, 1.6f, resources.Resume_ButtonA, 1, button_radius, button_direction, button_speed, RestartButton_hb);

        //Options Button animation
        animation_button(resources.Options_Button,backgroundWidth / 2 + 20, backgroundHeight - 200, 1.6f, resources.Options_ButtonA, 5, button_radius, button_direction, button_speed, RestartButton_hb);

        //Exit Button animation
        animation_button(resources.Exit_Button,backgroundWidth - 180, backgroundHeight - 180, 1.6f, resources.Exit_ButtonA, 2, button_radius, button_direction, button_speed, ExitButton_hb);
    }
    
    else if(menuStateSelected == 2){
        game = 0;
        EndDrawing();
    }
    
    else if(menuStateSelected == 5){
        DrawTextureEx(resources.bg, Vector2{0, 0}, 0, 1.6f, WHITE);
    
        //Skins Button animation
        animation_button(resources.Options_Button,backgroundWidth / 2 - 215, -50, 4.5f, resources.Options_ButtonA, 5, button_radius, button_direction, button_speed);

        // Menu Button animation
        animation_button(resources.Menu_Button,backgroundWidth - 180, backgroundHeight - 190, 1.6f, resources.Menu_ButtonA, 0, button_radius + 2.0f, 1, button_speed + 0.015f, Menu_Button_hb);
    }

    else if(menuStateSelected == 6){
        DrawTextureEx(resources.bg, Vector2{0, 0}, 0, 1.6f, WHITE);
        // DrawTextEx(resources.novencento, "Skins", Vector2{backgroundWidth / 2 - 180, 45}, 80, -5, WHITE);

        //Skins Button animation
        animation_button(resources.Skins_Button,backgroundWidth / 2 - 225, -50, 4.5f, resources.Skins_ButtonA, 6, button_radius, button_direction, button_speed);
        
        //Bee Skin Button animation
        animation_button(resources.bee,backgroundWidth /2 - 300, backgroundHeight / 2 - 40, 1.0f, resources.bee_flap, 6, button_radius + 2.0f, 1, button_speed + 0.015f, Skins_hb, 2);
        
        //Flappy Bird Skin Button animation
        animation_button(resources.flappy_bird,backgroundWidth /2 + 100, backgroundHeight / 2 - 40, 1.0f, resources.flappy_bird_flap, 6, button_radius + 2.0f, 1, button_speed + 0.015f, Skins_hb, 1);
        
        // Menu Button animation
        animation_button(resources.Menu_Button,backgroundWidth - 180, backgroundHeight - 190, 1.6f, resources.Menu_ButtonA, 0, button_radius + 2.0f, 1, button_speed + 0.015f, Menu_Button_hb);
        
        
    }
}
/*

struct skins{

    int id;
    Rectangle hb {0, 0, };

}

*/