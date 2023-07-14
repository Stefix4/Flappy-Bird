#pragma once

#include <raylib.h>
struct bird;
void birdJump();
struct pipe;
void pipe_movement();
void drawing(Texture2D fb, Texture2D fb_flap, Texture2D pill1);
void collision();
void update_hb();
