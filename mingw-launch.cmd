@echo off
g++ -o bin\game.exe src\*.cpp -Link SDL2.dll -I"Z:\c++lib\SDL2\include\SDL2" -I"Z:\c++lib\SDL_image\include\SDL2" -Link SDL2_image.dll -w
bin\game