#include <raylib.h>
#include <fstream>

#include "movement.hpp"
#include "mainMenu.hpp"
#include "game.hpp"
#include "textures.hpp"

int FPS = 144;
float volume_sfx = 0.3f;
float volume_music = 0.3f;
float master_volume = 1.0f;
float* master_volume_ptr = &master_volume;
int dev_skins = -1;
int dev_mode = -1;
int cheats = -1;
float timedev = 2.0f * FPS / 10.0f;
float timeskins = 2.0f * FPS / 10.0f;
float timecheats = 2.0f * FPS / 10.0f;


MenuState currentMenuState = MenuState::MENU;

Resources resources;

void loadSounds(){

    InitAudioDevice();
    resources.music = LoadMusicStream("./resources/sounds/music.mp3");
    resources.music.looping = true;
    resources.die = LoadSound("./resources/sounds/die.mp3");
    resources.flap = LoadSound("./resources/sounds/flap.mp3");
    resources.hit = LoadSound("./resources/sounds/hit.mp3");
    resources.point = LoadSound("./resources/sounds/point.mp3");    
    resources.swoosh = LoadSound("./resources/sounds/swoosh.mp3");
}

void set_sounds_volume(){
    SetMasterVolume(master_volume);
    SetMusicVolume(resources.music, volume_music); 
    SetSoundVolume(resources.die, volume_sfx);
    SetSoundVolume(resources.flap, volume_sfx);
    SetSoundVolume(resources.hit, volume_sfx);
    SetSoundVolume(resources.point, volume_sfx + 0.1f);
    SetSoundVolume(resources.swoosh, volume_sfx);
}

void unloadSounds(){
    UnloadMusicStream(resources.music);
    UnloadSound(resources.die);
    UnloadSound(resources.flap);
    UnloadSound(resources.hit);
    UnloadSound(resources.point);
    UnloadSound(resources.swoosh);

    CloseAudioDevice();
}

void loadTextures(){
    resources.Title_Screen = LoadTexture("./resources/images/Title_Screen.png");
    resources.logo = LoadImage("./resources/images/flappy-bird-logo.png");
    resources.Start_Button=LoadTexture("./resources/images/buttons/Start_Button.png");
    resources.Start_ButtonA = LoadTexture("./resources/images/buttons/Start_ButtonA.png");
    resources.Exit_Button = LoadTexture("./resources/images/buttons/Exit_Button.png");
    resources.Exit_ButtonA = LoadTexture("./resources/images/buttons/Exit_ButtonA.png");
    resources.Restart_Button = LoadTexture("./resources/images/buttons/Restart_Button.png");
    resources.Restart_ButtonA = LoadTexture("./resources/images/buttons/Restart_ButtonA.png");
    resources.Resume_Button = LoadTexture("./resources/images/buttons/Resume_Button.png");
    resources.Resume_ButtonA = LoadTexture("./resources/images/buttons/Resume_ButtonA.png");
    resources.Menu_Button = LoadTexture("./resources/images/buttons/Menu_Button.png");
    resources.Menu_ButtonA = LoadTexture("./resources/images/buttons/Menu_ButtonA.png");
    resources.Options_Button = LoadTexture("./resources/images/buttons/Options_Button.png");
    resources.Options_ButtonA = LoadTexture("./resources/images/buttons/Options_ButtonA.png");  
    resources.Skins_Button = LoadTexture("./resources/images/buttons/Skins_Button.png");
    resources.Skins_ButtonA = LoadTexture("./resources/images/buttons/Skins_ButtonA.png");
    resources.flappy_bird_skin = LoadTexture("./resources/images/flappy-bird/flappy_bird_skin.png");
    resources.flappy_bird_skinA = LoadTexture("./resources/images/flappy-bird/flappy_birdskinA.png");
    resources.flappy_bird_skin_selected = LoadTexture("./resources/images/flappy-bird/flappy_bird_skin_selected.png");
    resources.flappy_bird_skin_selectedA = LoadTexture("./resources/images/flappy-bird/flappy_bird_skin_selectedA.png");
    resources.flappy_bird_skin_locked1 = LoadTexture("./resources/images/flappy-bird/flappy_bird_skin_locked1.png");
    resources.flappy_bird_skin_locked2 = LoadTexture("./resources/images/flappy-bird/flappy_bird_skin_locked2.png");
    resources.bee = LoadTexture("./resources/images/bee/bee.png");
    resources.bee_flap = LoadTexture("./resources/images/bee/bee_flaps.png");
    resources.bee_skin = LoadTexture("./resources/images/bee/bee_skin.png");
    resources.bee_skinA = LoadTexture("./resources/images/bee/bee_skinA.png");
    resources.bee_skin_selected = LoadTexture("./resources/images/bee/bee_skin_selected.png");
    resources.bee_skin_selectedA = LoadTexture("./resources/images/bee/bee_skin_selectedA.png");
    resources.bee_skin_locked1 = LoadTexture("./resources/images/bee/bee_skin_locked1.png");
    resources.bee_skin_locked2 = LoadTexture("./resources/images/bee/bee_skin_locked2.png");
    resources.bat = LoadTexture("./resources/images/bat/bat.png");
    resources.bat_flap = LoadTexture("./resources/images/bat/batA.png");
    resources.bat_skin = LoadTexture("./resources/images/bat/bat_skin.png");
    resources.bat_skinA = LoadTexture("./resources/images/bat/bat_skinA.png");
    resources.bat_skin_selected = LoadTexture("./resources/images/bat/bat_skin_selected.png");
    resources.bat_skin_selectedA = LoadTexture("./resources/images/bat/bat_skin_selectedA.png");
    resources.bat_skin_locked1 = LoadTexture("./resources/images/bat/bat_skin_locked1.png");
    resources.bat_skin_locked2 = LoadTexture("./resources/images/bat/bat_skin_locked2.png");
    

    if(skinSelected == 1){ // bird skin
    resources.fb_flap = LoadTexture("./resources/images/flappy-bird/flappy-bird-flaps.png");
    resources.pill1 = LoadTexture("./resources/images/flappy-bird/pillar-2.png");
    resources.fb = LoadTexture("./resources/images/flappy-bird/flappy-bird.png");// fb = flappy bird
    resources.pill2 = LoadTexture("./resources/images/flappy-bird/pillar-1.png");
    resources.bg = LoadTexture("./resources/images/background2.png");
    resources.bg_game = LoadTexture("./resources/images/background.png");
    }
    else if(skinSelected == 2){ // bee skin
    resources.fb = resources.bee;
    resources.fb_flap = resources.bee_flap;
    resources.pill1 = LoadTexture("./resources/images/bee/branch-2.png");
    resources.pill2 = LoadTexture("./resources/images/bee/branch-1.png");
    resources.bg = LoadTexture("./resources/images/forest2.png");
    resources.bg_game = LoadTexture("./resources/images/forest.png");
    }
    else if(skinSelected == 3){ // bat skin
    resources.fb = resources.bat;
    resources.fb_flap = resources.bat_flap;
    resources.pill1 = LoadTexture("./resources/images/bat/stalagmite.png");
    resources.pill2 = LoadTexture("./resources/images/bat/stalactite.png");
    resources.bg = LoadTexture("./resources/images/cave2.png");
    resources.bg_game = LoadTexture("./resources/images/cave.png");
    }
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
    UnloadTexture(resources.Menu_Button);
    UnloadTexture(resources.Menu_ButtonA);
    UnloadTexture(resources.Options_Button);
    UnloadTexture(resources.Options_ButtonA);
    UnloadTexture(resources.Skins_Button);
    UnloadTexture(resources.Skins_ButtonA);
    UnloadFont(resources.novencento);
    TraceLog(LOG_INFO, "Unloaded resources succesfully");
}

int fileSize;
unsigned char* fileData = LoadFileData("./resources/font/PressStart2P-Regular.ttf", &fileSize);


int main(void)
{
    SetTargetFPS(FPS);
    
    
    const int screenWidth = 1280;
    const int screenHeight = 720;

    Vector2 notification_position = {screenWidth / 2 - 300, 10};

    bool texture_logo = false;

    //initialling the window
    InitWindow(screenWidth,screenHeight, "Flappy Bird");
    SetExitKey(KEY_NULL);
    SetWindowMinSize(screenWidth,screenHeight);

    //declaring images/textures/font

    //game loop
    while (!WindowShouldClose()){   
        BeginDrawing();
        draw_hb();
        ClearBackground(WHITE);
            
        mainMenu();
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
        ///Dev_mode///
        if(IsKeyDown(KEY_TAB) && IsKeyDown(KEY_D) && dev_mode != 1){
            dev_mode = 1;
            timedev = 2.0f * FPS / 10.0f;
        }
        if(dev_mode == 1 && timedev > 0){
            timedev = notify("Developer Mode Activated", timedev,notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Developer Mode Activated");
        }
        if(IsKeyDown(KEY_LEFT_SHIFT) && IsKeyDown(KEY_D) && dev_mode == 1){
            dev_mode = 0;
            timedev = 2.0f * FPS / 10.0f;
        }
        if(dev_mode == 0 && timedev > 0){
            timedev = notify("Developer Mode Deactivated", timedev,notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Developer Mode Deactivated");
        }
        ///Dev_skins///
        if(IsKeyDown(KEY_TAB) && IsKeyDown(KEY_S) && dev_skins != 1){
            dev_skins = 1;
            timeskins = 2.0f * FPS / 10.0f;
        }
        if(dev_skins == 1 && timeskins > 0){
            timeskins = notify("Developer Skins Activated", timeskins,notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Developer Skins Activated");
        }
        if(IsKeyDown(KEY_LEFT_SHIFT) && IsKeyDown(KEY_S) && dev_skins == 1){
            dev_skins = 0;
            timeskins = 2.0f * FPS / 10.0f;
        }
        if(dev_skins == 0 && timeskins > 0){
            timeskins = notify("Developer Skins Deactivated", timeskins, notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Developer Skins Deactivated");
        }  
        ///Cheats///
        if(IsKeyDown(KEY_TAB) && IsKeyDown(KEY_C) && cheats != 1){
            cheats = 1;
            timecheats = 2.0f * FPS / 10.0f;
        }
        if(cheats == 1 && timecheats > 0){   
            timecheats = notify("Cheats Activated", timecheats,notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Cheats Activated");
        }
        
        if(IsKeyDown(KEY_LEFT_SHIFT) && (IsKeyDown(KEY_C)) && cheats == 1){
            cheats = 0;
            timecheats = 2.0f * FPS / 10.0f;
        }
        if(cheats == 0 && timecheats > 0){
            timecheats = notify("Cheats Deactivated", timecheats, notification_position, 40, WHITE, -3);
            TraceLog(LOG_ERROR, "Cheats Dectivated");
        }
    
        
        EndDrawing();
    }
    
    unloadTextures();
    unloadSounds();
    
    TraceLog(LOG_INFO, "Closing window...");

    CloseWindow();

    TraceLog(LOG_INFO, "Exited succesfully");

    

    return 0;
}
