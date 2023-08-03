#pragma once

#include <raylib.h>

enum class MenuState {MENU=0, PLAY=1, EXIT=2, GAME_OVER=3};
extern int menuStateSelected;
void mainMenu(Texture2D pill1,Texture2D fb,Texture2D fb_flap,Texture2D pill2,Texture2D Start_Button, Texture2D bg,Texture2D bg_game, Texture2D Start_ButtonA, Texture2D Exit_Button, Texture2D Exit_ButtonA, Texture2D Title_Screen, Texture2D Restart_Button, Texture2D Restart_ButtonA);
extern Rectangle StartButton_hb;
extern Rectangle ExitButton_hb;
extern Rectangle RestartButton_hb;
