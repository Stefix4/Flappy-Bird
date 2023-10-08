#pragma once

#include <raylib.h>
struct bird;
void birdJump();
struct pipe;

void create(Texture2D pill1,Texture2D pill2);
void movement(Texture2D pill1,Texture2D pill2);
void pipe_movement(Texture2D pill1,Texture2D pill2);
void drawing(Texture2D fb, Texture2D fb_flap,Texture2D bg_game);

void collision();
void counter();
void update_hb();
void draw_hb();
void reset_game();
extern bool game_over;
extern int final_score;
extern long long highest_score;
extern long long high_score;
