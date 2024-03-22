#pragma once
#include <iostream>
#include "raylib.h"
#include "entityRef.h"
#include <string>
#include <vector>

class fight {
private:
	int playerActifPokemon;
	int winFight;
	int opponentActifPokemon;
	int wildPokemonIndex = -1;
	int Opponent;
	int abilityIndex;
	int opponentAbilityIndex = -1;
	int Timer = 0;
	Font ft;
	int index;
	bool playerTurn = true;

public:
	void Load(Font font);
	int StartFight(int OpponentIndex);
	void WildPokemon(bool isLake);
	int ChoosePokemon();
	void SwitchDialogue();
	void DrawFight(Pokemon _pokemon);
	int Choice(const std::vector<std::string>& options, int spacing);
	float DamageCalculator(int damage, PokeType TypeAttaquant, PokeType TypeDefenseur);
};

