#include "Pokemon.h"
Pokemon::Pokemon(std::string newName, std::string newDescription, PokeType newType, int newLife, int damage, Ability ability1, Ability ability2)
	: name(newName), description(newDescription), level(1), lifePoints(newLife), maxLife(newLife), type(newType)
{
	abilitys.push_back(ability1);
	abilitys.push_back(ability2);
}

void Pokemon::SetSprite(Texture2D& NewSprite)
{
	sprite = NewSprite;
}

Texture2D& Pokemon::GetSprite()
{
	return sprite;
}

void Pokemon::SetName(string newName)
{
	name = newName;
}

string& Pokemon::GetName()
{
	return name;
}

PokeType Pokemon::GetType()
{
	return type;
}

void Pokemon::SetAbility(Ability newAbility)
{
	abilitys.push_back(newAbility);
}

std::vector<Ability>& Pokemon::GetAbilitys()
{
	return abilitys;
}

void Pokemon::GetDamage(int Damages)
{
	lifePoints -= Damages;
}

int Pokemon::GetLife()
{
	return lifePoints;
}

int Pokemon::GetMaxLife()
{
	return maxLife;
}

int Pokemon::GetLevel()
{
	return level;
}

void Pokemon::WinFight(int AmountOfXP)
{
	if (xp + AmountOfXP < xpToLVL) {
		xp += AmountOfXP;
	}
	else {
		xp = 0;
		level++;
		xpToLVL += level * 2;
	}
	
}


