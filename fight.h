#pragma once
#include <iostream>
#include "raylib.h"
#include "entityRef.h"
#include <string>
#include <vector>

class fight {
private:
	int playerActifPokemon;
	int opponentActifPokemon;
	Font ft;
	int index;

public:
	void Load(Font font);
	int StartFight(int OpponentIndex);
	int ChoosePokemon();
};

