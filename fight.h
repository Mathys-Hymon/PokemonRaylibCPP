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
	bool wildPokemonValid = false;
	int Opponent;
	int abilityIndex;
	int opponentAbilityIndex = -1;
	int Timer = 0;
	Font ft;
	int index;
	int catchAttemp = 0;
	bool playerTurn = true;

	bool AbilitysSet = false;

public:
	fight();
	~fight();

	void Load(Font font);
	int StartFight(int OpponentIndex);
	int WildPokemon();
	int ChoosePokemon();
	void SwitchDialogue();
	void DrawFight(Pokemon _pokemon);
	int Choice(const std::vector<std::string>& options, int spacing);
	float DamageCalculator(int damage, PokeType TypeAttaquant, PokeType TypeDefenseur);
};

