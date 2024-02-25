#include "startDialogue.h"
#include "entityRef.h"
#include "fight.h"

int startDialogue = 0;
int explorationDialogue = 0;
int fightDialogue = 0;

fight combat = fight();

void startDialogue::Load(Font font)
{
    
    ft = font;
    name = "";
    index = 0;
    LoadPokeSprites();
    combat.Load(ft);
    dialogues = {
        {"Bienvenue dans le monde magique des POKEMON !"},
        {"Je suis le Professeur Chen."},
        {" "}, // question
        {" "}, // question
        {"et voici mon petit-fils."},
  /*5*/      {"Vous êtes rivaux depuis votre tendre enfance."},
        {" "}, // question 
        {" "}, // question
        {"Aujourd'hui est un grand jour,"},
        {" le jour ou vous allez choisir votre premier pokemon !"},
 /*10*/   {" "},
        {""},
        {""},
        {""},
        {" "}
    };
}

void startDialogue::Unload()
{
    UnloadPokeSprites();
}

void startDialogue::Update()
{
    dialogue();
}

void startDialogue::dialogue()
{
    if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) && index != dialogues.size() - 1 && dialogues[index] != " ") {
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
        DrawTextEx(ft, TextFormat("d'accord, tu t'appelle %s c'est bien ca ?", name.c_str()), Vector2{ 50, 150 }, 20, 1, Color(BLACK));
        switch (choice({"oui", "non"}, 1, 185))
        {
        case 0:
            getTrainer(0).setName(name);
            cout << getTrainer(0).getFirstName();
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
        switch (choice({ "oui", "non" }, 1, 185))
        {
        case 0:
            getTrainer(1).setName(name);
            cout << getTrainer(1).getFirstName();
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
        DrawTextEx(ft, TextFormat("Vas y %s prend le pokemon qui te plait", getTrainer(0).getFirstName().c_str()), Vector2{50, 100}, 20, 1, Color(BLACK));
        DrawTextureEx(getPokemon(0).GetSprite(), Vector2{ 50, 150 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(6).GetSprite(), Vector2{ 193, 150 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(3).GetSprite(), Vector2{ 336, 150 }, 0, 2.5, Color(WHITE));
        switch (choice({ "Bulbizarre", "Carapuce", "Salamèche"}, 3, 300))
        {
        case 0:
            getTrainer(0).AddPokemon(getPokemon(0));
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        case 1:
            getTrainer(0).AddPokemon(getPokemon(6));
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        case 2:
            getTrainer(0).AddPokemon(getPokemon(3));
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        }
        break;

    case 11:
            DrawTextureEx(getTrainer(0).getTeam()[0].GetSprite(), Vector2{190, 150}, 0, 3, Color(WHITE));
            DrawTextEx(ft, TextFormat("%s a été ajouté à ton équipe !", getTrainer(0).getTeam()[0].GetName().c_str()), Vector2{ 50, 120 }, 20, 1, Color(BLACK));
            setName(name); 
            DrawTextEx(ft, TextFormat(" Comment veux-tu l'appeler ? : %s", name.c_str()), Vector2{ 50, 350 }, 20, 1, Color(BLACK));
            if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) && index != dialogues.size() - 1 && dialogues[index] != " ") {
                getTrainer(0).getTeam()[0].SetName(name);
            }
            break;
    case 12:
        DrawTextEx(ft, TextFormat("C'est au tour de %s de choisir son pokemon !", getTrainer(1).getFirstName().c_str()), Vector2{ 50, 120 }, 20, 1, Color(BLACK));
        if (getTrainer(0).getTeam()[0].GetType() == water) {
            DrawTextEx(ft, TextFormat("%s : Très bien, je choisi Bulbizarre !", getTrainer(1).getFirstName().c_str()), Vector2{ 50, 350 }, 20, 1, Color(BLACK));
            getTrainer(1).AddPokemon(getPokemon(0));

        }
        else if (getTrainer(0).getTeam()[0].GetType() == fire) {
            DrawTextEx(ft, TextFormat("%s : Très bien, je choisi Carapuce !", getTrainer(1).getFirstName().c_str()), Vector2{ 50, 350 }, 20, 1, Color(BLACK));
            getTrainer(1).AddPokemon(getPokemon(6));
        }
        else {
            DrawTextEx(ft, TextFormat("%s : Très bien, je choisi Salamèche !", getTrainer(1).getFirstName().c_str()), Vector2{ 50, 350 }, 20, 1, Color(BLACK));
            getTrainer(1).AddPokemon(getPokemon(3));
        }
        DrawTextureEx(getTrainer(1).getTeam()[0].GetSprite(), Vector2{190, 150}, 0, 3, Color(WHITE));
        break;

    case 13:
        DrawTextEx(ft, TextFormat("%s : Maintenant voyons qui est le meilleur dresseur !", getTrainer(1).getFirstName().c_str()), Vector2{ 50, 185 }, 20, 1, Color(BLACK));
        break;

    case 14:

        int fightResult = combat.StartFight(1);

        if (fightResult == 1) {
            cout << "vous avez gagné !!";
        }
        else if (fightResult == 0) {
            cout << "vous avez perdu";
        }
        break;
    }
}

void startDialogue::setName(std::string& name)
{
    int key = GetKeyPressed();

    if (key != 0 || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        size_t len = name.length();

        if (key == KEY_BACKSPACE) {
            if (len > 0) {
                name.pop_back();
            }
        }
        else if (len < 8 && (key != KEY_ENTER && !IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
            name.push_back(static_cast<char>(key));
        }

        else if (len > 0 && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER))) {
            index++;
        }
    }
}

int startDialogue::choice(const std::vector<std::string>& options, int spacing, float yPos)
{
    int selectedOption = -1;
        for (size_t i = 0; i < options.size(); ++i) {
            DrawTextEx(ft, options[i].c_str(), Vector2{ static_cast < float>(50 + i * 50 * spacing), yPos }, 20, 1, Color(BLACK));

            if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { static_cast<float>(50 + i * 50* spacing), yPos, static_cast<float>(MeasureText(options[i].c_str(), 20)), 30 })) {
                DrawRectangleLines(45 + i*50*spacing, yPos, MeasureText(options[i].c_str(), 20) + 5, 30, BLACK);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    selectedOption = i;
                }
            }
        }

        return selectedOption;
}
