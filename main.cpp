#include "raylib.h"
#include "entityRef.h"
#include "choice.h"
#include <iostream>

using namespace std;

int main() {
    InitWindow(500, 500, "Pokemon RAYLIB");
    SetTargetFPS(60);

    Font ft = LoadFont("resources/fonts/pokemon_pixel_font.ttf");
    Texture2D texture = LoadTexture("resources/pokemonsImages/pokemon_1.png");

    // Demander le nom du joueur
    char playerName[64] = "";
    playerName[0] = '\0';  // Assurez-vous que la chaîne est vide au début

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);


        DrawTextEx(ft, "Bonjour dresseur ! Comment t'appelles-tu ?", Vector2{ 50, 100 }, 20, 1, Color(BLACK));
        DrawTextEx(ft, TextFormat("Nom du joueur : %s_", playerName), Vector2{ 50, 150 }, 20, 1, Color(BLACK));

        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }

        int key = GetKeyPressed();
        if (key != 0) {
            int len = strlen(playerName);

            if (key == KEY_BACKSPACE) {
                if (len > 0) {
                    playerName[len - 1] = '\0';
                }
            }
            else if (len < 63) {
                playerName[len] = static_cast<char>(key);
                playerName[len + 1] = '\0';
            }
        }


        EndDrawing();
    }


    UnloadTexture(texture);
    UnloadFont(ft);
    CloseWindow();
    return 0;
}