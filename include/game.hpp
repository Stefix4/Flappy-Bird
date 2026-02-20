#pragma once

#include <raylib.h>

extern int FPS;
extern float volume_music;
extern float volume_sfx;
extern float master_volume;

void loadTextures();
void unloadTextures();
void loadSounds();
void unloadSounds();
void set_sounds_volume();

extern int dev_mode;
extern int cheats;