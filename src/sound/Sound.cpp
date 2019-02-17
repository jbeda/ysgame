#include "Sound.hpp"
Mix_Music* LoadMP3(std::string audioFP) {
	return Mix_LoadMUS(audioFP.c_str());
}
void UnloadMP3(Mix_Music* music) {
	Mix_FreeMusic(music);
}
void PlayMP3(Mix_Music* music, int loops) {
	Mix_PlayMusic(music, loops);
}
void StopMP3() {
	Mix_HaltMusic();
}
Mix_Chunk* LoadOGG(std::string audioFP) {
	return Mix_LoadWAV(audioFP.c_str());
}
void UnloadOGG(Mix_Chunk* chunk) {
	Mix_FreeChunk(chunk);
}
void PlayOGG(Mix_Chunk* chunk) {
	Mix_PlayChannel(-1, chunk, 0);
}