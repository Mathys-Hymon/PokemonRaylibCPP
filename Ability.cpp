#include "Ability.h"

Ability::Ability(std::string newName, int newDamage, PokeType newType, int Energy)
	: name(newName), damage(newDamage), type(newType), energy(Energy), maxEnergy(Energy)
{
}

std::string& Ability::GetName()
{
	return name;
}

PokeType Ability::GetType()
{
	return type;
}

std::string Ability::GetTypeName()
{
	std::vector<std::string> PokeTypeNames = {
				"normal",
"feu",
"eau",
"plante",
"electrique",
"glace",
"combat",
"poison",
"sol",
"vol",
"psy",
"insecte",
"roche",
"spectre",
"dragon",
"ténèbre",
"acier",
"fée",

	};
	return PokeTypeNames[type];
}

int Ability::GetMaxEnergy()
{
	return maxEnergy;
}

int Ability::GetEnergy()
{
	return energy;
}

int Ability::GetDamage()
{
	return damage;
}

void Ability::LooseEnergy()
{
	energy--;
}

void Ability::ResetEnergy()
{
	energy = maxEnergy;
}




