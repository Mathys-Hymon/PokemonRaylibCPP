#include "fight.h"

void fight::Load(Font font)
{
	index = 0;
	ft = font;
	playerActifPokemon = -1;
	opponentActifPokemon = -1;
	Opponent = -1;
	opponentAbilityIndex = -1;
	abilityIndex = -1;
}


int fight::StartFight(int OpponentIndex)
{
	if (Opponent != OpponentIndex)
	{
		Opponent = OpponentIndex;
		winFight = -1;
	}

	if (opponentActifPokemon == -1 || getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLife() <= 0) 
	{

		if (opponentActifPokemon + 1 < getTrainer(Opponent).getTeam().size())
		{
			DrawTextEx(ft, TextFormat("L adversaire envoie %s !", getTrainer(Opponent).getTeam()[opponentActifPokemon + 1].GetName().c_str()), Vector2{ 220, 220 }, 20, 1, Color(BLACK));
			if (Timer <= 100)
			{
				Timer++;
			}
			else {
				opponentActifPokemon++;
				Timer = 0;
			}
		}
		else 
		{
			if (Timer <= 200)
			{
				DrawTextEx(ft, TextFormat("%s : QUOI !! Incroyable ! J'ai pas pris le bon Pokemon", getTrainer(1).getFirstName().c_str()), Vector2{ 220, 350 }, 20, 1, Color(BLACK));
				Timer++;
			}

			else 
			{
				Timer = 0;
				getTrainer(0).addMoney(getTrainer(OpponentIndex).getMoney());
				winFight = 1;
			}

			
		}

	}
	else if (playerActifPokemon == -1 || getTrainer(0).getTeam()[playerActifPokemon].GetLife() <= 0) {
		playerActifPokemon = ChoosePokemon();
	}

	else if (index == 0)
	{
		std::string name = getTrainer(Opponent).getFirstName();
		std::string lName = getTrainer(Opponent).getLastName();
		std::string catchphrase = getTrainer(Opponent).getCatchPhrase();
		std::string text = name + " " + lName + " : " + catchphrase;

		DrawTextEx(ft, text.c_str(), Vector2{ 220, 220 }, 20, 1, Color(BLACK));
		SwitchDialogue();
	}

	else if (playerTurn) {
		int choice = -1;
		DrawFight(getTrainer(Opponent).getTeam()[opponentActifPokemon]);

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
						DrawTextEx(ft, getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), Vector2{ 401, static_cast<float>(500 + i * 35) }, 25, 1, Color(BLACK));
						if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { 401, static_cast<float>(500 + i * 35), static_cast<float>(MeasureText(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), 25)), 30 })) {
							DrawRectangleLines(391, 500 + i * 35, MeasureText(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetName().c_str(), 25) + 5, 30, BLACK);
							DrawTextEx(ft, TextFormat("TYPE / %s", getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetTypeName().c_str()), Vector2{ 181, 500 }, 25, 1, Color(BLACK));

							std::string abilityPower = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetEnergy()).c_str();
							std::string abilityMaxPower = to_string(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[i].GetMaxEnergy()).c_str();
							std::string textPower = abilityPower + "/" + abilityMaxPower;
							DrawTextEx(ft, textPower.c_str(), Vector2{ 201, 526 }, 20, 1, Color(BLACK));
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
							{
								abilityIndex = i;
								getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].LooseEnergy();
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
					efficacity = "ce n est pas tres efficace";
				}
				else if (DamageCalculator(1, getTrainer(0).getTeam()[playerActifPokemon].GetType(), getTrainer(Opponent).getTeam()[opponentActifPokemon].GetType()) > 1)
				{
					efficacity = "c est tres efficace !!";
				}

				std::string text = name + " utilise " + abilityName + ", " + efficacity;
				
				DrawTextEx(ft, text.c_str(), Vector2{ 200, 538 }, 20, 1, Color(BLACK));

				if (Timer <= 50)
				{
					Timer++;
				}
				else
				{
					if ((getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLife()*5) - DamageCalculator(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetDamage(), getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType()) < 0)
					{
						Timer = 0;
						index = 5;
						
					}
					else 
					{
						getTrainer(Opponent).getTeam()[opponentActifPokemon].GetDamage(DamageCalculator(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetDamage(), getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType()));
						index = 1;
						cout << getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLife();
						playerTurn = false;
						abilityIndex = -1;
						Timer = 0;
					}
				}
			}
			break;

		case 3:   //objets

			DrawTextEx(ft, "aucun objet", Vector2{ 201, 523 }, 20, 1, Color(BLACK));
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
				DrawTextEx(ft, "Tu pensais t en tirer si facilement ?", Vector2{ 201, 523 }, 20, 1, Color(BLACK));
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
				DrawTextEx(ft, "Quoi tu bat en retraite ? Reviens quand tu seras pret", Vector2{ 201, 523 }, 20, 1, Color(BLACK));
				if (Timer <= 100)
				{
					Timer++;
				}
				else
				{
					winFight = 0;
					Timer = 0;
				}
			}
			break;

		case 5: //gainXP
			
			if (Timer <= 200)
			{
				std::string name = getTrainer(0).getTeam()[playerActifPokemon].GetName();
				std::string xpWin = to_string((int)(getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLevel() * (1 / DamageCalculator(1, getTrainer(0).getTeam()[playerActifPokemon].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType()))));
				std::string text = name + " a gagne " + xpWin + " xp";
				DrawTextEx(ft, text.c_str(), Vector2{ 201, 538 }, 25, 1, Color(BLACK));
				Timer++;
			}
			else
			{
				getTrainer(0).getTeam()[playerActifPokemon].WinFight(getTrainer(Opponent).getTeam()[opponentActifPokemon].GetLevel()* (1 / DamageCalculator(1, getTrainer(0).getTeam()[playerActifPokemon].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType())));
				getTrainer(Opponent).getTeam()[opponentActifPokemon].GetDamage(DamageCalculator(getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetDamage(), getTrainer(0).getTeam()[playerActifPokemon].GetAbilitys()[abilityIndex].GetType(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetType()));
				index = 1;
				playerTurn = false;
				abilityIndex = -1;
				Timer = 0;
			}
			break;
		}
	}

	else 
	{
		DrawFight(getTrainer(Opponent).getTeam()[opponentActifPokemon]);
		if (opponentAbilityIndex == -1) 
		{
			opponentAbilityIndex = GetRandomValue(0, getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetAbilitys().size()-1);
		}
		else 
		{
			std::string name = getTrainer(Opponent).getTeam()[opponentActifPokemon].GetName();
			std::string abilityName = getTrainer(Opponent).getTeam()[opponentActifPokemon].GetAbilitys()[opponentAbilityIndex].GetName();
			std::string efficacity = "";

			if (DamageCalculator(1, getTrainer(Opponent).getTeam()[opponentActifPokemon].GetAbilitys()[opponentAbilityIndex].GetType(), getTrainer(0).getTeam()[playerActifPokemon].GetType()) < 1)
			{
				efficacity = "ce n est pas tres efficace";
			}
			else if (DamageCalculator(1, getTrainer(Opponent).getTeam()[opponentActifPokemon].GetAbilitys()[opponentAbilityIndex].GetType(), getTrainer(0).getTeam()[playerActifPokemon].GetType()) > 1)
			{
				efficacity = "c est tres efficace !!";
			}

			std::string text = name + " utilise " + abilityName + ", " + efficacity;

			DrawTextEx(ft, text.c_str(), Vector2{ 200, 538 }, 20, 1, Color(RED));

			if (Timer <= 150)
			{
				Timer++;
			}
			else
			{
				getTrainer(0).getTeam()[playerActifPokemon].GetDamage(DamageCalculator(getTrainer(Opponent).getTeam()[opponentActifPokemon].GetAbilitys()[opponentAbilityIndex].GetDamage(), getTrainer(OpponentIndex).getTeam()[opponentActifPokemon].GetAbilitys()[opponentAbilityIndex].GetType(), getTrainer(0).getTeam()[playerActifPokemon].GetType()));
				index = 1;
				playerTurn = true;
				opponentAbilityIndex = -1;
				Timer = 0;
			}
		}
    }

	if (winFight == 1) 
	{
		getTrainer(Opponent).setDefeated(true);
	}
	return winFight;
}

void fight::WildPokemon(bool isLake)
{
	if (wildPokemonIndex == -1) 
	{
		if (isLake) 
		{
			
		}
		else 
		{

		}
	}
}

int fight::ChoosePokemon()
{
	int pokemonAlive = 0;
	int choice = -1;
	for (int i = 0; i < getTrainer(0).getTeam().size(); i++) {
		if (getTrainer(0).getTeam()[i].GetLife() > 0) {
			pokemonAlive++;

			DrawTextureEx(getTrainer(0).getTeam()[i].GetSprite(), Vector2{ 201, static_cast <float>(238 + i * 50) }, 0, 2, Color(WHITE));
			DrawTextEx(ft, getTrainer(0).getTeam()[i].GetName().c_str(), Vector2{ 301, static_cast <float>(268 + i * 80) }, 20, 1, Color(BLACK));

			std::string pokemonLife = to_string((int)getTrainer(0).getTeam()[i].GetMaxLife()).c_str();
			std::string pokemonMaxLife = to_string((int)getTrainer(0).getTeam()[i].GetLife()).c_str();
			std::string textLife = pokemonLife + "/" + pokemonMaxLife;
			DrawTextEx(ft, textLife.c_str(), Vector2{ 301, static_cast <float>(288 + i * 80) }, 20, 1, Color(BLACK));
			if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { 301, static_cast<float>(268 + i * 80), static_cast<float>(MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20)), 30 })) {
				DrawRectangleLines(291, 268 + i * 80, MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20) + 5, 30, BLACK);
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

void fight::DrawFight(Pokemon _pokemon)
{
	//PLAYER
	DrawTextureEx(getTrainer(0).getTeam()[playerActifPokemon].GetSprite(), Vector2{ 186, 348 }, 0, 4, Color(WHITE));
	DrawTextEx(ft, getTrainer(0).getTeam()[playerActifPokemon].GetName().c_str(), Vector2{ 401, 388 }, 40, 1, Color(BLACK));
	DrawTextEx(ft, TextFormat("LVL : %s",to_string(getTrainer(0).getTeam()[playerActifPokemon].GetLevel()).c_str()), Vector2{ 401, 423 }, 15, 1, Color(BLACK));
	DrawTextEx(ft, "HP :", Vector2{ 401, 438}, 20, 1, Color(BLACK));
	DrawRectangle(430, 445, (getTrainer(0).getTeam()[playerActifPokemon].GetLife() / getTrainer(0).getTeam()[playerActifPokemon].GetMaxLife()) *100, 5, Color(GREEN));
	DrawRectangleLines(430, 445, 100, 5, BLACK);
	std::string pokemonMaxLife = to_string((int)getTrainer(0).getTeam()[playerActifPokemon].GetMaxLife()).c_str();
	std::string pokemonLife = to_string((int)getTrainer(0).getTeam()[playerActifPokemon].GetLife()).c_str();
	std::string textLife = pokemonLife + "/" + pokemonMaxLife;
	DrawTextEx(ft, textLife.c_str(), Vector2{ 450 , 453 }, 21, 1, Color(BLACK));

	//Textbox
	DrawRectangle(161, 488, 480, 140, Color(RAYWHITE));
	DrawRectangleLines(161, 488, 480, 140, BLACK);


	//OPPONENT

	DrawTextureEx(_pokemon.GetSprite(), Vector2{ 451, 143 }, 0, 4, Color(WHITE));
	DrawTextEx(ft, _pokemon.GetName().c_str(), Vector2{ 251, 188 }, 40, 1, Color(BLACK));
	DrawTextEx(ft, TextFormat("LVL : %s", to_string(_pokemon.GetLevel()).c_str()), Vector2{ 251, 233 }, 15, 1, Color(BLACK));
	DrawTextEx(ft, "HP :", Vector2{ 251, 248 }, 20, 1, Color(BLACK));
	DrawRectangle(281, 256,(_pokemon.GetLife() / _pokemon.GetMaxLife()) * 100, 5, Color(GREEN));
	DrawRectangleLines(281, 256, 100, 5, BLACK);
}

int fight::Choice(const std::vector<std::string>& options, int spacing)
{
	int selectedOption = -1;
	for (size_t i = 0; i < options.size(); ++i) {
		DrawTextEx(ft, options[i].c_str(), Vector2{ static_cast <float>(204 + i * 50 * spacing), 538 }, 20, 1, Color(BLACK));

		if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { static_cast<float>(204 + i * 50 * spacing), 538, static_cast<float>(MeasureText(options[i].c_str(), 20)), 30 })) {
			DrawRectangleLines(196 + i * 50 * spacing, 538, MeasureText(options[i].c_str(), 20) + 5, 30, BLACK);
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
