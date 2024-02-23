#include "Pokemon.h"
Pokemon::Pokemon(std::string newName, std::string newDescription, PokeType newType, float newLife, int damage, Ability ability1, Ability ability2)
	: name(newName), description(newDescription), level(1), lifePoints(newLife), maxLife(newLife), type(newType)
{
	abilitys.push_back(ability1);
	abilitys.push_back(ability2);
}
