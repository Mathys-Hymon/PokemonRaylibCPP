#include "startDialogue.h"
#include "entityRef.h"

int startDialogue = 0;
int explorationDialogue = 0;
int fightDialogue = 0;

void startDialogue::Load(Font font)
{
    ft = font;
    name = "";
    index = 0;
    LoadPokeSprites();
    dialogues = {
        {"Bienvenue dans le monde magique des POKEMON !"},
        {"Je suis le Professeur Chen."},
        {" "}, // question
        {" "}, // question
        {"et voici mon petit-fils."},
        {"Vous êtes rivaux depuis votre tendre enfance."},
        {" "}, // question 
        {" "}, // question
        {"Aujourd'hui est un grand jour,"},
        {" le jour ou vous allez choisir votre premier pokemon !"},
        {" "},
        {" stylé en vrai"},
    };
}

void startDialogue::Unload()
{

}

void startDialogue::Update()
{
    dialogue();
}

void startDialogue::dialogue()
{

    DrawTextEx(ft, TextFormat("player name : %s_", name.c_str()), Vector2{ 10, 10 }, 20, 1, Color(RED));

    if (IsKeyPressed(KEY_ENTER) && index != dialogues.size() - 1 && dialogues[index] != " ") {
        index++;
    }
    switch (index)
    {

    default:
        DrawTextEx(ft, dialogues[index].c_str(), Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        break;

    case 2:
        DrawTextEx(ft, " Comment devrais-je t'appeler ?", Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        setName(name);
        DrawTextEx(ft, TextFormat("Nom du joueur : %s", name.c_str()), Vector2{ 50, 180 }, 20, 1, Color(BLACK));

        break;

    case 3:
        DrawTextEx(ft, TextFormat("d'accord, tu t'appelle %s", name.c_str()), Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        DrawTextEx(ft, " c'est bien ca ?" , Vector2{ 50, 180 }, 20, 1, Color(BLACK));
        switch (choice({"oui", "non"}, 1))
        {
        case 0:
            getTrainer(0).setName(name);
            cout << getTrainer(0).getName();
            name = "";
            index++;
            break;
        case 1:
            index = 2;
            name = "";
            break;
        }
        break;

    case 6:
        DrawTextEx(ft,"... Heu... C'est quoi son nom déjà ?", Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        setName(name);
        DrawTextEx(ft, TextFormat("Nom du rival : %s", name.c_str()), Vector2{ 50, 180 }, 20, 1, Color(BLACK));
        break;

    case 7:
        DrawTextEx(ft, TextFormat("Ah oui je crois me souvenir, c'est  %s ", name.c_str()), Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        DrawTextEx(ft, " c'est bien ca ?", Vector2{ 50, 180 }, 20, 1, Color(BLACK));
        switch (choice({ "oui", "non" }, 1))
        {
        case 0:
            getTrainer(1).setName(name);
            cout << getTrainer(1).getName();
            name = "";
            index++;
            break;
        case 1:
            index = 6;
            name = "";
            break;
        }
        break;

    case 10:
        DrawTextEx(ft, TextFormat("Vas y %s prend le pokemon qui te plait", getTrainer(0).getName().c_str()), Vector2{50, 100}, 20, 1, Color(BLACK));
        DrawTextureEx(getPokemon(0).GetSprite(), Vector2{ 50, 150 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(6).GetSprite(), Vector2{ 193, 150 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(3).GetSprite(), Vector2{ 336, 150 }, 0, 2.5, Color(WHITE));
        switch (choice({ "Bulbizarre", "Carapuce", "Salamèche"}, 3))
        {
        case 0:
            getTrainer(0).AddPokemon(getPokemon(0));
            index++;
            break;
        case 1:
            getTrainer(0).AddPokemon(getPokemon(6));
            index++;
            break;
        case 2:
            getTrainer(0).AddPokemon(getPokemon(3));
            index++;
            break;
        }
        break;
    }
}

void startDialogue::setName(std::string& name)
{
    int key = GetKeyPressed();

    if (key != 0) {
        size_t len = name.length();

        if (key == KEY_BACKSPACE) {
            if (len > 0) {
                name.pop_back();
            }
        }
        else if (len < 8 && key != KEY_ENTER) {
            name.push_back(static_cast<char>(key));
        }

        else if (len > 0 && key == KEY_ENTER) {
            index++;
        }
    }
}

int startDialogue::choice(const std::vector<std::string>& options, int spacing)
{
    int selectedOption = -1;
        for (size_t i = 0; i < options.size(); ++i) {
            DrawTextEx(ft, options[i].c_str(), Vector2{ static_cast < float>(50 + i * 50 * spacing), 300 }, 20, 1, Color(BLACK));

            if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { static_cast<float>(50 + i * 50* spacing), 300, static_cast<float>(MeasureText(options[i].c_str(), 20)), 30 })) {
                DrawRectangleLines(45 + i*50*spacing, 300, MeasureText(options[i].c_str(), 20) + 5, 30, BLACK);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    selectedOption = i;
                }
            }
        }

        return selectedOption;
}
