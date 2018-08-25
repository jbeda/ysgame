@echo off
g++ -o bin\game.exe src\*.cpp -Link SDL2.dll -I"Z:\c++lib\SDL2\include\SDL2" -w
bin\game