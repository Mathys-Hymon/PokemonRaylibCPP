#include "fight.h"

void fight::Load(Font font)
{
	index = 0;
	ft = font;
	playerActifPokemon = -1;
	opponentActifPokemon = -1;
	abilityIndex = -1;
}


int fight::StartFight(int OpponentIndex)
{
	winFight = -1;
	Opponent = OpponentIndex;

	if (opponentActifPokemon == -1 || getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLife() <= 0) {
		if (opponentActifPokemon + 1 <= getTrainer(Opponent).getTeam().size()) {
			DrawTextEx(ft, TextFormat("L'adversaire envoie %s !", getTrainer(Opponent).getTeam()[opponentActifPokemon + 1].GetName().c_str()), Vector2{ 50, 170 }, 20, 1, Color(BLACK));
			if (Timer <= 100)
			{
				Timer++;
			}
			else {
				opponentActifPokemon++;
				Timer = 0;
			}
		}
		else {
			winFight = 1;
		}

	}
	else if (playerActifPokemon == -1 || getTrainer(0).getTeam()[playerActifPokemon].GetLife() <= 0) {
		playerActifPokemon = ChoosePokemon();
	}

	else if (index == 0)
	{
		std::string name = getTrainer(1).getFirstName();
		std::string lName = getTrainer(1).getLastName();
		std::string catchphrase = getTrainer(1).getCatchPhrase();
		std::string text = name + " " + lName + " : " + catchphrase;

		DrawTextEx(ft, text.c_str(), Vector2{ 50, 185 }, 20, 1, Color(BLACK));
		SwitchDialogue();
	}

	else if (playerTurn) {
		int choice = -1;
		DrawFight();

		switch (index)
		{
		case 1:
			Timer = 0;
			switch (Choice({ "ATTAQUE", "OBJET", "FUITE" }, 3)) {
			case 0:
				index = 2;
				break;
			case 1:
				index = 3;
				break;
			case 2:
				index = 4;
				break;
			}
			break;

		case 2:  //attaque
			if (abilityIndex == -1)
			{
				for (int i = 0; i < getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys().size(); i++) {

					if (getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetEnergy() > 0) 
					{
						DrawTextEx(ft, getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), Vector2{ 250, static_cast<float>(360 + i * 35) }, 25, 1, Color(BLACK));
						if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { 250, static_cast<float>(360 + i * 35), static_cast<float>(MeasureText(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), 25)), 30 })) {
							DrawRectangleLines(250, 360 + i * 35, MeasureText(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), 25) + 5, 30, BLACK);
							DrawTextEx(ft, TextFormat("TYPE / %s", getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetTypeName().c_str()), Vector2{ 30, 360 }, 25, 1, Color(BLACK));

							std::string abilityPower = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetEnergy()).c_str();
							std::string abilityMaxPower = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetMaxEnergy()).c_str();
							std::string textPower = abilityPower + "/" + abilityMaxPower;
							DrawTextEx(ft, textPower.c_str(), Vector2{ 50, 385 }, 20, 1, Color(BLACK));
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								abilityIndex = i;
								getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].LooseEnergy();
								//getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].setLife(getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetLife() - DamageCalculator(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetDamage(), getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType()));
							}
						}
					}
					else 
					{
						DrawTextEx(ft, getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), Vector2{ 250, static_cast<float>(360 + i * 35) }, 25, 1, Color(GRAY));
					}

				}
			}

			else
			{
				std::string name = getTrainer(0).getTeam()[playerActifPokemon].GetName();
				std::string abilityName = getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetName();
				std::string efficacity = "";

				if (DamageCalculator(1, getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(Opponent).getTeam()[opponentActifPokemon].GetType()) < 1)
				{
					efficacity = "ce n'est pas très efficace";
				}
				else if (DamageCalculator(1, getTrainer(0).getTeam()[playerActifPokemon].GetType(), getTrainer(Opponent).getTeam()[opponentActifPokemon].GetType()) > 1)
				{
					efficacity = "c'est très efficace !!";
				}
				std::string text = name + " utilise " + abilityName + ", " + efficacity;

				DrawTextEx(ft, to_string(DamageCalculator(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetDamage(), getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType())).c_str(), Vector2{ 50, 385 }, 20, 1, Color(BLACK));
				//DrawTextEx(ft, text.c_str(), Vector2{ 50, 385 }, 20, 1, Color(BLACK));

				if (Timer <= 100)
				{
					Timer++;
				}
				else
				{
					index = 1;
					playerTurn = false;
					abilityIndex = -1;
					Timer = 0;
				}
			}
			break;

		case 3:   //objets

			DrawTextEx(ft, "aucun objet", Vector2{ 50, 385 }, 20, 1, Color(BLACK));
			if (Timer <= 50)
			{
				Timer++;
			}
			else {
				index = 1;
				Timer = 0;
			}
			break;

		case 4:  // Fuite

			if (Opponent == 1) {
				DrawTextEx(ft, "Eh tu pensais t'en tirer si facilement ?", Vector2{ 50, 385 }, 20, 1, Color(BLACK));
				if (Timer <= 50)
				{
					Timer++;
				}
				else 
				{
					index = 1;
					Timer = 0;
				}
			}
			else 
			{
				winFight = 0;
			}
			break;
		}
	}

	else 
	{
		DrawFight();

    }


	return winFight;
}

int fight::ChoosePokemon()
{
	int pokemonAlive = 0;
	int choice = -1;
	for (int i = 0; i < getTrainer(0).getTeam().size(); i++) {
		if (getTrainer(0).getTeam()[i].GetLife() > 0) {
			pokemonAlive++;

			DrawTextureEx(getTrainer(0).getTeam()[i].GetSprite(), Vector2{ 50, static_cast <float>(100 + i * 50) }, 0, 2, Color(WHITE));
			DrawTextEx(ft, getTrainer(0).getTeam()[i].GetName().c_str(), Vector2{ 150, static_cast <float>(130 + i * 80) }, 20, 1, Color(BLACK));

			std::string pokemonLife = to_string(getTrainer(0).getTeam()[i].GetMaxLife()).c_str();
			std::string pokemonMaxLife = to_string(getTrainer(0).getTeam()[i].GetLife()).c_str();
			std::string textLife = pokemonLife + "/" + pokemonMaxLife;
			DrawTextEx(ft, textLife.c_str(), Vector2{ 150, static_cast <float>(150 + i * 80) }, 20, 1, Color(BLACK));
			if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { 150, static_cast<float>(130 + i * 80), static_cast<float>(MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20)), 30 })) {
				DrawRectangleLines(140, 130 + i * 80, MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20) + 5, 30, BLACK);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					choice = i;
				}
			}
		}
	}

	if (pokemonAlive == 0) {
		winFight = 0;
		return -1;
	}
	else {
		return choice;
	}
}

void fight::SwitchDialogue()
{
	if ((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)))
	{
		index++;
	}
}

void fight::DrawFight()
{
	//PLAYER
	DrawTextureEx(getTrainer(0).getTeam()[playerActifPokemon].GetSprite(), Vector2{ 35, 210 }, 0, 4, Color(WHITE));
	DrawTextEx(ft, getTrainer(0).getTeam()[playerActifPokemon].GetName().c_str(), Vector2{ 250, 250 }, 40, 1, Color(BLACK));
	DrawTextEx(ft, TextFormat("LVL : %s",to_string(getTrainer(0).getTeam()[playerActifPokemon].GetLevel()).c_str()), Vector2{ 250, 285 }, 15, 1, Color(BLACK));
	DrawTextEx(ft, "HP :", Vector2{250, 300}, 20, 1, Color(BLACK));
	DrawRectangle(280, 307, (getTrainer(0).getTeam()[playerActifPokemon].GetLife() / getTrainer(0).getTeam()[playerActifPokemon].GetMaxLife()) *100, 5, Color(GREEN));
	DrawRectangleLines(280, 307, 100, 5, BLACK);
	std::string pokemonLife = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetMaxLife()).c_str();
	std::string pokemonMaxLife = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetLife()).c_str();
	std::string textLife = pokemonLife + "/" + pokemonMaxLife;
	DrawTextEx(ft, textLife.c_str(), Vector2{ 290 , 315 }, 21, 1, Color(BLACK));

	//Textbox
	DrawRectangle(10, 350, 480, 140, Color(RAYWHITE));
	DrawRectangleLines(10, 350, 480, 140, BLACK);


	//OPPONENT

	DrawTextureEx(getTrainer(Opponent).getTeam()[opponentActifPokemon].GetSprite(), Vector2{ 300, 5 }, 0, 4, Color(WHITE));
	DrawTextEx(ft, getTrainer(Opponent).getTeam()[opponentActifPokemon].GetName().c_str(), Vector2{ 100, 50 }, 40, 1, Color(BLACK));
	DrawTextEx(ft, TextFormat("LVL : %s", to_string(getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLevel()).c_str()), Vector2{ 100, 95 }, 15, 1, Color(BLACK));
	DrawTextEx(ft, "HP :", Vector2{ 100, 110 }, 20, 1, Color(BLACK));
	DrawRectangle(130, 118, (getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLife() / getTrainer(Opponent).getTeam()[opponentActifPokemon].GetMaxLife()) * 100, 5, Color(GREEN));
	DrawRectangleLines(130, 118, 100, 5, BLACK);
}

int fight::Choice(const std::vector<std::string>& options, int spacing)
{

	int selectedOption = -1;
	for (size_t i = 0; i < options.size(); ++i) {
		DrawTextEx(ft, options[i].c_str(), Vector2{ static_cast <float>(50 + i * 50 * spacing), 400 }, 20, 1, Color(BLACK));

		if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { static_cast<float>(50 + i * 50 * spacing), 400, static_cast<float>(MeasureText(options[i].c_str(), 20)), 30 })) {
			DrawRectangleLines(45 + i * 50 * spacing, 400, MeasureText(options[i].c_str(), 20) + 5, 30, BLACK);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				selectedOption = i;
			}
		}
	}

	return selectedOption;
}

float fight::DamageCalculator(int damage, PokeType TypeAttaquant, PokeType TypeDefenseur)
{
	std::vector<std::vector<float>> matrice = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5f, 0, 1, 1, 0.5f, 1},   // Normal
		{1, 0.5, 0.5, 2, 1, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2, 1}, // Fire
		{1, 2, 0.5, 0.5, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1},   // Water
		{1, 0.5, 2, 0.5, 1, 1, 1, 0.5, 0.5, 2, 1, 0.5, 2, 1, 0.5, 1, 1, 1}, // Grass
		{1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1, 1},   // Electric
		{1, 0.5, 0.5, 2, 1, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5, 1}, // Ice
		{2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2, 0.5}, // Fighting
		{1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 2}, // Poison
		{1, 2, 1, 0.5, 2, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 1, 1},   // Ground
		{1, 1, 1, 2, 0.5, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1},   // Flying
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 0, 1, 1},   // Psychic
		{1, 0.5, 1, 2, 1, 1, 0.5, 0.5, 2, 0.5, 2, 1, 1, 0.5, 1, 2, 1, 0.5}, // Bug
		{1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 1, 1},   // Rock
		{0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1},   // Ghost
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 0.5, 1},   // Dragon
		{1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 0.5, 1, 0.5},   // Dark
		{1, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 0.5}  // Steel
	};

	if (matrice[TypeAttaquant][TypeDefenseur] < 1) 
	{

	}
	else if (matrice[TypeAttaquant][TypeDefenseur] > 1) 
	{

	}
	
	return damage * matrice[TypeAttaquant][TypeDefenseur];
}
