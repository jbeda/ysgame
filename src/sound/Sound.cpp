#include "Sound.hpp"
Music* Music::LoadMP3(std::string audioFP) {
	return new Music(Mix_LoadMUS(audioFP.c_str()));
}
void Music::UnloadMP3(Music* music) {
	Mix_FreeMusic(music->mp3);
	delete music;
}
void Music::PlayMP3(Music* music, int loops) {
	Mix_PlayMusic(music->mp3, loops);
}
void Music::StopMP3() {
	Mix_HaltMusic();
}
namespace SFX {
	SoundEffect* ThrowKnife = NULL;
}
SoundEffect* SoundEffect::LoadOGG(std::string audioFP) {
	return new SoundEffect(Mix_LoadWAV(audioFP.c_str()));
}
void SoundEffect::UnloadOGG(SoundEffect* sfx) {
	Mix_FreeChunk(sfx->ogg);
	delete sfx;
}
void SoundEffect::PlayOGG(SoundEffect* sfx) {
	Mix_PlayChannel(-1, sfx->ogg, 0);
}
void SoundEffect::LoadSFX() {
	using namespace SFX;
	ThrowKnife = LoadOGG("assets/sfx/throwknife.ogg");
}
void SoundEffect::UnloadSFX() {
	using namespace SFX;
	UnloadOGG(ThrowKnife);
}