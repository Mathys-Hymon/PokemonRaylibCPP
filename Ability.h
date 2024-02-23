#pragma once
#include "Poketype.h"
#include <iostream>
#include <string>


class Ability
{
private:
	std::string name;
	int damage;
	int energy;
	int maxEnergy;
	PokeType type;
	int useNum;
public:
	Ability(std::string newName, int newDamage, PokeType newType, int Energy);
};

