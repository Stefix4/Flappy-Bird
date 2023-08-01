#pragma once

#include <raylib.h>

enum class MenuState {MENU=0, PLAY=1, CONTRLOS=2, EXIT=3};
extern int menuStateSelected;
void mainMenu(Texture2D pill1,Texture2D fb,Texture2D fb_flap,Texture2D pill2,Texture2D Start_Button);

