#pragma once

#include <raylib.h>

enum class MenuState {MENU=0, PLAY=1, EXIT=2, GAME_OVER=3};
extern int menuStateSelected;
void mainMenu();
extern Rectangle StartButton_hb;
extern Rectangle ExitButton_hb;
extern Rectangle RestartButton_hb;

float notify(const char * message, float duration, Vector2 position, int size, Color color, int spacing);

extern int game;
extern int skinSelected;
