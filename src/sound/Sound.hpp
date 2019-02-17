#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
Mix_Music* LoadMP3(std::string audioFP);
void UnloadMP3(Mix_Music* music);
void PlayMP3(Mix_Music* music, int loops);
void StopMP3();
Mix_Chunk* LoadOGG(std::string audioFP);
void UnloadOGG(Mix_Chunk* chunk);
void PlayOGG(Mix_Chunk* chunk);