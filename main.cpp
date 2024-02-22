#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    Font ft = LoadFont(TextFormat("%s%s", GetWorkingDirectory(), "/ressources/fonts/pokemon_pixel_font.ttf"));
    Texture2D pokemonTest = LoadTexture(TextFormat("%s%s", GetWorkingDirectory(), "/ressources/pokemonsImages/Image.png"));
    InitWindow(500, 500, "Pokemon RAYLIB");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawTextEx(ft, "Test", Vector2{ 50, 400 }, 25, 1, Color(BLACK));
        ClearBackground(RAYWHITE);
        DrawTexture(pokemonTest, 100, 100, WHITE);
        EndDrawing();
    }
    UnloadTexture(pokemonTest);
    CloseWindow();
    return 0;
}