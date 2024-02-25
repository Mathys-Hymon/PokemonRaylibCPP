#include <iostream>
#include "raylib.h"
#include "fight.h"
#include "startDialogue.h"
#include <locale>

void Update();
void Start();
void Unload();



startDialogue dialogue = startDialogue();

using namespace std;

int main() {
    Start();
    while (!WindowShouldClose()) {
        Update();
    }
    Unload();
    return 0;
}

void Start() 
{
    InitWindow(500, 500, "Pokemon RAYLIB");
    SetTargetFPS(60);
    Font ft = LoadFont("resources/fonts/pokemon_pixel_font.ttf");
    dialogue.Load(ft);
}
        

void Update()
{
    BeginDrawing();
    ClearBackground(WHITE);
    dialogue.Update();
    EndDrawing();
}

void Unload() {
    dialogue.Unload();
    CloseWindow();
}


