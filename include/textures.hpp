# pragma once

#include <raylib.h>

struct Resources{
    Image logo;
    Texture2D Start_Button;
    Texture2D fb_flap;
    Texture2D pill1;
    Texture2D fb;// fb = flappy bird
    Texture2D pill2 ;
    Texture2D bg;
    Texture2D bg_game;
    Texture2D Start_ButtonA;
    Texture2D Exit_Button;
    Texture2D Exit_ButtonA;
    Texture2D Title_Screen;
    Texture2D Restart_Button;
    Texture2D Restart_ButtonA;
    Font novencento;
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
extern Font novencento;

extern unsigned int fileSize ;
extern unsigned char* fileData;

extern Resources resources;
