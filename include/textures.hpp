# pragma once

#include <raylib.h>

struct Resources{
    Image logo;
    Texture2D Start_Button;
    Texture2D pill2 ;
    Texture2D pill1;
    Texture2D bg;
    Texture2D bg_game;
    Texture2D Start_ButtonA;
    Texture2D Exit_Button;
    Texture2D Exit_ButtonA;
    Texture2D Title_Screen;
    Texture2D Restart_Button;
    Texture2D Restart_ButtonA;
    Texture2D Menu_Button;
    Texture2D Menu_ButtonA;
    Texture2D Resume_Button;
    Texture2D Resume_ButtonA;
    Texture2D Options_Button;
    Texture2D Options_ButtonA;
    Texture2D Skins_Button;
    Texture2D Skins_ButtonA;
    Texture2D flappy_bird;
    Texture2D flappy_bird_flap;
    Texture2D fb_flap;
    Texture2D fb;// fb = flappy bird
    Texture2D flappy_bird_skin;
    Texture2D flappy_bird_skinA;
    Texture2D flappy_bird_skin_selected;
    Texture2D flappy_bird_skin_selectedA;
    Texture2D flappy_bird_skin_locked1;
    Texture2D flappy_bird_skin_locked2;
    Texture2D bee;
    Texture2D bee_flap;
    Texture2D bee_skin;
    Texture2D bee_skinA;
    Texture2D bee_skin_selected;
    Texture2D bee_skin_selectedA;
    Texture2D bee_skin_locked1;
    Texture2D bee_skin_locked2;
    Texture2D bat;
    Texture2D bat_flap;
    Texture2D bat_skin;
    Texture2D bat_skinA;
    Texture2D bat_skin_selected;
    Texture2D bat_skin_selectedA;
    Texture2D bat_skin_locked1;
    Texture2D bat_skin_locked2;
    Font novencento;
    Sound die;
    Sound flap;
    Sound hit;
    Sound point;
    Sound swoosh;
    Music music;
};

extern Image logo;
extern Texture2D Start_Button;
extern Texture2D fb_flap;
extern Texture2D pill1;
extern Texture2D fb;
extern Texture2D pill2;
extern Texture2D bg;
extern Texture2D bg_game;
extern Texture2D Start_ButtonA;
extern Texture2D Exit_Button;
extern Texture2D Exit_ButtonA;
extern Texture2D Title_Screen;
extern Texture2D Restart_Button;
extern Texture2D Restart_ButtonA;
extern Texture2D bee;
extern Texture2D bee_flap;
extern Font novencento;

extern int fileSize ;
extern unsigned char* fileData;

extern Resources resources;
