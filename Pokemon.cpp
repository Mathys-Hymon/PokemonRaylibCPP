#include "Pokemon.h"
Pokemon::Pokemon(std::string newName, std::string newDescription, PokeType newType, int damage, int newLife, Ability ability1, Ability ability2)
	: name(newName), description(newDescription), level(1), lifePoints(newLife * 5), maxLife(newLife *  5), type(newType)
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

Texture2D& Pokemon::getPokeballSprite()
{
	return pokeballSprite;
}

void Pokemon::SetPokeballSprite(Texture2D NewSprite)
{
	pokeballSprite = NewSprite;
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

float Pokemon::GetLife()
{
	return lifePoints /5;
}

float Pokemon::GetMaxLife()
{
	return maxLife /5;
}

void Pokemon::setLife(int _life)
{
	lifePoints += _life;
	if (lifePoints > maxLife)
	{
		lifePoints = maxLife;
	}

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


