#include "choice.h"
#include "raylib.h"


int choice = 0;

int makeChoice()
{


    // Définissez vos options ici
    const char* options[] = { "Option 1", "Option 2", "Option 3" };

    // Affichez les options à l'écran
    for (int i = 0; i < 3; ++i) {
        DrawText(options[i], 50, 100 + i * 30, 20, DARKGRAY);
    }

    // Attendez que l'utilisateur fasse un choix
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    int mouseY = GetMouseY();

    choice = mouseY;

    //if (mouseY >= 100 && mouseY <= 160) {
    //    choice = 1;
    //}
    //else if (mouseY > 160 && mouseY <= 190) {
    //    choice = 2;
    //}
    //else if (mouseY > 190 && mouseY <= 220) {
    //    choice = 3;
    //}

    return choice;
    }
}
