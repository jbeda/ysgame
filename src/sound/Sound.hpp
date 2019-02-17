#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
class Music {
public:
	static Music* LoadMP3(std::string audioFP);
	static void UnloadMP3(Music* music);
	static void PlayMP3(Music* music, int loops);
	static void StopMP3();
protected:
	Music(Mix_Music* music) {
		this->mp3 = music;
	}
	Mix_Music* mp3;
};
class SoundEffect {
public:
	static SoundEffect* LoadOGG(std::string audioFP);
	static void UnloadOGG(SoundEffect* sfx);
	static void PlayOGG(SoundEffect* sfx);
	static void LoadSFX();
	static void UnloadSFX();
protected:
	SoundEffect(Mix_Chunk* chunk) {
		this->ogg = chunk;
	}
	Mix_Chunk* ogg;
};
namespace SFX {
	extern SoundEffect* ThrowKnife;
}