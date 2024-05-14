#include "startDialogue.h"
#include "fight.h"

int startDialogue = 0;
int explorationDialogue = 0;
int fightDialogue = 0;

fight combat = fight();

void startDialogue::Load(Font font)
{
    for (int i = 0; i <= 3; i++) 
    {
        std::string pokeball = "resources/ButtonsIcons/pokeball_" + std::to_string(i + 1) + ".png";
        Image pokeballImage = LoadImage(pokeball.c_str());
        pokeballSprite[i] = LoadTextureFromImage(pokeballImage);
        UnloadImage(pokeballImage);
    }
    fightResult = -1;
    ft = font;
    name = "";
    index = 0;
    LoadPokeSprites();
    LoadTrainers();
    combat.Load(ft);
    dialogues = {
        {"Bienvenue dans le monde magique des POKEMON !"},
        {"Je suis le Professeur Chen."},
        {" "}, // question
        {" "}, // question
        {"et voici mon petit fils."},
  /*5*/      {"Vous etes rivaux depuis votre tendre enfance."},
        {" "}, // question 
        {" "}, // question
        {"Aujourd hui est un grand jour,"},
        {" le jour ou vous allez choisir votre premier pokemon !"},
 /*10*/   {" "},
        {" "},
        {""},
        {""},
        {" "},
 /*15*/   {" "},
        {" "},
        {" "},
        {" "},
    };
    std::string grassPath = "resources/ButtonsIcons/herbes.png";
    std::string lakePath = "resources/ButtonsIcons/canne.png";
    std::string leaguePath = "resources/ButtonsIcons/league.png";
    std::string centerPath = "resources/ButtonsIcons/pokecenter.png";
    std::string cadrePath = "resources/ButtonsIcons/Cadre.png";

    Image grassImage = LoadImage(grassPath.c_str());
    Image lakeImage = LoadImage(lakePath.c_str());
    Image leagueImage = LoadImage(leaguePath.c_str());
    Image centerImage = LoadImage(centerPath.c_str());
    Image cadreImage = LoadImage(cadrePath.c_str());

    centerSprite = LoadTextureFromImage(centerImage);
    leagueSprite = LoadTextureFromImage(leagueImage);
    grassSprite = LoadTextureFromImage(grassImage);
    lakeSprite = LoadTextureFromImage(lakeImage);
    cadreSprite = LoadTextureFromImage(cadreImage);

    UnloadImage(grassImage);
    UnloadImage(lakeImage);
    UnloadImage(leagueImage);
    UnloadImage(centerImage);
    UnloadImage(cadreImage);
}

void startDialogue::Unload()
{
    UnloadPokeSprites();
    UnloadTexture(centerSprite);
    UnloadTexture(leagueSprite);
    UnloadTexture(grassSprite);
    UnloadTexture(lakeSprite);
    UnloadTexture(cadreSprite);
    for (int i = 0; i <= 3; i++)
    {
        UnloadTexture(pokeballSprite[i]);
    }
}

void startDialogue::Update()
{
    DrawTextureEx(cadreSprite, Vector2{0,0}, 0, 1, Color(WHITE));
    dialogue();
}

void startDialogue::dialogue()
{
    if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) && index != dialogues.size() - 1 && dialogues[index] != " ") {
        index++;
        cout << index << endl;
    }
    switch (index)
    {

    default:
        DrawTextEx(ft, dialogues[index].c_str(), Vector2{ 220, 250 }, 20, 1, Color(BLACK));
        break;

    case 2:
        DrawTextEx(ft, " Comment devrais je t'appeler ?", Vector2{ 220, 250 }, 20, 1, Color(BLACK));
        setName(name);
        DrawTextEx(ft, TextFormat("Nom du joueur : %s", name.c_str()), Vector2{ 220, 280 }, 20, 1, Color(BLACK));

        break;

    case 3:
        DrawTextEx(ft, TextFormat("d accord, tu t appelle %s c'est bien ca ?", name.c_str()), Vector2{ 220, 250 }, 20, 1, Color(BLACK));
        switch (choice({"oui", "non"}, 1, 285))
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
        DrawTextEx(ft,"... Heu... C'est quoi son nom deja ?", Vector2{ 220, 250 }, 20, 1, Color(BLACK));
        setName(name);
        DrawTextEx(ft, TextFormat("Nom du rival : %s", name.c_str()), Vector2{ 220, 280 }, 20, 1, Color(BLACK));
        break;

    case 7:
        DrawTextEx(ft, TextFormat("Ah oui je crois me souvenir, c est  %s ", name.c_str()), Vector2{ 220, 250 }, 20, 1, Color(BLACK));
        switch (choice({ "oui", "non" }, 1, 285))
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
        DrawTextEx(ft, TextFormat("Vas y %s prend le pokemon qui te plait", getTrainer(0).getFirstName().c_str()), Vector2{250, 220}, 20, 1, Color(BLACK));
        DrawTextureEx(getPokemon(0).GetSprite(), Vector2{ 200, 280 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(6).GetSprite(), Vector2{ 343, 280 }, 0, 2.5, Color(WHITE));
        DrawTextureEx(getPokemon(3).GetSprite(), Vector2{ 486, 280 }, 0, 2.5, Color(WHITE));
        switch (choice({ "Bulbizarre", "Carapuce", "Salamèche"}, 2.7, 400))
        {
        case 0:
            getTrainer(0).AddPokemon(getPokemon(0));
            getTrainer(0).getTeam()[0].SetPokeballSprite(pokeballSprite[0]);
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        case 1:
            getTrainer(0).AddPokemon(getPokemon(6));
            getTrainer(0).getTeam()[0].SetPokeballSprite(pokeballSprite[0]);
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        case 2:
            getTrainer(0).AddPokemon(getPokemon(3));
            getTrainer(0).getTeam()[0].SetPokeballSprite(pokeballSprite[0]);
            name = getTrainer(0).getTeam()[0].GetName().c_str();
            index++;
            break;
        }
        break;

    case 11:
            DrawTextureEx(getTrainer(0).getTeam()[0].GetSprite(), Vector2{ 343, 200}, 0, 3, Color(WHITE));
            DrawTextEx(ft, TextFormat("%s a ete ajoute a ton équipe !", getTrainer(0).getTeam()[0].GetName().c_str()), Vector2{ 220, 350 }, 20, 1, Color(BLACK));
            setName(name); 
            DrawTextEx(ft, TextFormat(" Comment veux-tu l'appeler ? : %s", name.c_str()), Vector2{ 220, 380 }, 20, 1, Color(BLACK));
            if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER))) {
                getTrainer(0).getTeam()[0].SetName(name);
                index = 12;
            }
            break;

    case 12:
        DrawTextEx(ft, TextFormat("C'est au tour de %s de choisir son pokemon !", getTrainer(1).getFirstName().c_str()), Vector2{ 250, 220 }, 20, 1, Color(BLACK));
        if (getTrainer(0).getTeam()[0].GetType() == water) {
            if (getTrainer(1).getTeam().size() == 0) 
            {
                getTrainer(1).AddPokemon(getPokemon(0));
            }
            DrawTextEx(ft, TextFormat("%s : Tres bien, je choisi Bulbizarre !", getTrainer(1).getFirstName().c_str()), Vector2{ 250, 430 }, 20, 1, Color(BLACK));
        }
        else if (getTrainer(0).getTeam()[0].GetType() == fire) {
            if (getTrainer(1).getTeam().size() == 0) 
            {
                getTrainer(1).AddPokemon(getPokemon(6));
            }
            DrawTextEx(ft, TextFormat("%s : Tres bien, je choisi Carapuce !", getTrainer(1).getFirstName().c_str()), Vector2{ 250, 430 }, 20, 1, Color(BLACK));

        }
        else {
            DrawTextEx(ft, TextFormat("%s : Tres bien, je choisi Salameche !", getTrainer(1).getFirstName().c_str()), Vector2{ 250, 430 }, 20, 1, Color(BLACK));
            if (getTrainer(1).getTeam().size() == 0) 
            {
                getTrainer(1).AddPokemon(getPokemon(3));
            }
        }
        DrawTextureEx(getTrainer(1).getTeam()[0].GetSprite(), Vector2{ 343, 270}, 0, 3, Color(WHITE));
        break;

    case 13:
        DrawTextEx(ft, TextFormat("%s : Maintenant voyons qui est le meilleur dresseur !", getTrainer(1).getFirstName().c_str()), Vector2{ 220, 220 }, 20, 1, Color(BLACK));
        break;

    case 14:

        if (fightResult == -1) 
        {
            fightResult = combat.StartFight(1);
            ~combat.StartFight(1);
        }
        else 
        {
            fightResult = -1;
            index++;
        }
        break;



    case 15: // main menu


        DrawTextureEx(centerSprite, Vector2{ 200, 280 }, 0, 3, Color(WHITE));
        DrawTextureEx(leagueSprite, Vector2{ 343, 280 }, 0, 3, Color(WHITE));
        DrawTextureEx(grassSprite, Vector2{ 486, 280 }, 0, 3, Color(WHITE));

        switch (choice({ "PokeCenter", "pokeLeague", "explorer" }, 3, 400))
        {
        case 0:
            index = 16;
            break;
        case 1:
            index = 17;
            break;
        case 2:
            index = 18;
            break;
        }
        break;


    case 16: // pokecenter
        {

        std::string playerName = getTrainer(0).getFirstName().c_str();
        std::string playerMoney = to_string((int)getTrainer(0).getMoney()).c_str();
        std::string moneyText = playerName + " : " + playerMoney + "P";
        DrawTextEx(ft, moneyText.c_str(), Vector2{ 200 , 180 }, 21, 1, Color(BLACK));
        DrawTextureEx(centerSprite, Vector2{ 320, 200 }, 0, 4, Color(WHITE));

        for (int i = 0; i < getTrainer(0).getTeam().size(); i++)
        {
            DrawTextureEx(getTrainer(0).getTeam()[i].getPokeballSprite(), Vector2{ static_cast <float>(200 + (i * 30)), 368}, 0, 3, Color(WHITE));

            DrawRectangle(static_cast <float>(220 + (i * 30)), 380, (getTrainer(0).getTeam()[i].GetLife() / getTrainer(0).getTeam()[i].GetMaxLife()) * 50, 5, Color(GREEN));
            DrawRectangleLines(static_cast <float>(30 + i), 320, 50, 5, BLACK);
        }


        for (int i = 0; i < 4; i++) 
        {
            DrawTextureEx(pokeballSprite[i], Vector2{ static_cast <float>(206 + (i * 50)), 523 }, 0, 2, Color(WHITE));
            DrawTextEx(ft, to_string(getTrainer(0).getPokeballs(i)).c_str(), Vector2{static_cast <float>(210 + (i * 50)) , 523}, 21, 1, Color(BLACK));
        }
        if (button("RETOUR", { 580,580 }, { 20,20 })) {
            index = 15;
        }
        switch (choice({ "100P", "350P", "500P", "1500P" }, 1, 588))
        {
        case 0:
            if (getTrainer(0).getMoney() >= 100) 
            {
                getTrainer(0).addMoney(-100);
                getTrainer(0).addPokeballs(0, 1);
            }
            break;

        case 1:
            if (getTrainer(0).getMoney() >= 350)
            {
                getTrainer(0).addMoney(-350);
                getTrainer(0).addPokeballs(1, 1);
            }
            break;

        case 2:
            if (getTrainer(0).getMoney() >= 500)
            {
                getTrainer(0).addMoney(-500);
                getTrainer(0).addPokeballs(2, 1);
            }
            break;

        case 3:
            if (getTrainer(0).getMoney() >= 1500)
            {
                getTrainer(0).addMoney(-1500);
                getTrainer(0).addPokeballs(3, 1);
            }
            break;
        }

        for (int i = 0; i < getTrainer(0).getTeam().size(); i++)
        {
            getTrainer(0).getTeam()[i].setLife(1);
        }

        }
        break;

    case 17:  //league pokemon

        if (getTrainer(opponentIndex).getDefeated() == true && fightResult == -1) {
            opponentIndex++;
        }
        else {
            if (fightResult == -1)
            {
                fightResult = combat.StartFight(opponentIndex);
                ~combat.StartFight(opponentIndex);
            }
            else
            {
                fightResult = -1;
               index =  15;
            }
        }

        break;

    case 18:  // partir chasser des pokemons sauvages 

        switch (choice({ "hautes herbes", "lac" }, 3, 438))
        {
        case 0:
            if (fightResult == -1)
            {
                fightResult = combat.WildPokemon(false);
            }
            else
            {
                fightResult = -1;
                index = 15;
            }
            break;

        case 1:
            if (fightResult == -1)
            {
                fightResult = combat.WildPokemon(true);
            }
            else
            {
                fightResult = -1;
                index = 15;
            }
            break;

        default:
            break;
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

int startDialogue::choice(const std::vector<std::string>& options, float spacing, float yPos)
{
    int selectedOption = -1;
        for (size_t i = 0; i < options.size(); ++i) {
            DrawTextEx(ft, options[i].c_str(), Vector2{ static_cast < float>(220 + i * 50 * spacing), yPos }, 20, 1, Color(BLACK));

            if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { static_cast<float>(220 + i * 50* spacing), yPos, static_cast<float>(MeasureText(options[i].c_str(), 20)), 30 })) {
                DrawRectangleLines(210 + i*50*spacing, yPos, MeasureText(options[i].c_str(), 20) + 5, 30, BLACK);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    selectedOption = i;
                }
            }
        }

        return selectedOption;
}

bool startDialogue::button(std::string name, Vector2 pos, Vector2 size)
{
    //DrawRectangle(pos.x - (MeasureText(name.c_str(), 20) + size.x) / 2, pos.y, size.x + static_cast<float>(MeasureText(name.c_str(), 20)), size.y, BLUE);
    DrawTextEx(ft, name.c_str(), {pos.x - (MeasureText(name.c_str(), 20)) / 2, pos.y + size.y / 3}, 20, 0 ,BLACK);

    if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { pos.x - (MeasureText(name.c_str(), 20) + size.x) / 2, pos.y,size.x + static_cast<float>(MeasureText(name.c_str(), 20)), size.y })) {

        DrawRectangleLines(pos.x - (MeasureText(name.c_str(), 20) + size.x) / 2, pos.y, size.x + static_cast<float>(MeasureText(name.c_str(), 20)), size.y, BLACK);
        DrawTextEx(ft, name.c_str(), { pos.x - (MeasureText(name.c_str(), 20)) / 2, pos.y + size.y / 3 }, 20, 0, BLACK);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}
