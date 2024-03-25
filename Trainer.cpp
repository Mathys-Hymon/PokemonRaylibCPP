#include "Trainer.h"

Trainer::Trainer(string newFirstName, string newLastName, string newCatchPhrase, int money, int newLife, vector<Pokemon> newTeam)
	: firstName(newFirstName), lastName(newLastName), catchphrase(newCatchPhrase), money(money), lifePoints(newLife), pokemons(newTeam)
{
}

void Trainer::setName(string newName)
{
	firstName = newName;
}

string& Trainer::getFirstName()
{
	return firstName;
}

string& Trainer::getLastName()
{
	return lastName;
}

string& Trainer::getCatchPhrase()
{
	return catchphrase;
}

bool Trainer::getDefeated()
{
	return defeated;
}

int Trainer::getMoney()
{
	return money;
}

int Trainer::getPokeballs(int _typePokeball)
{
	switch (_typePokeball)
	{
	case 0:
		return pokeball;
		break;

	case 1:
		return superBall;
		break;

	case 2:
		return HyperBall;
		break;

	case 3:
		return MasterBall;
		break;
	}
}

void Trainer::addPokeballs(int _typePokeball, int _pokeballs)
{
	switch (_typePokeball)
	{
	case 0:
		pokeball += _pokeballs;
		break;

	case 1:
		superBall += _pokeballs;
		break;
		
	case 2:
		HyperBall += _pokeballs;
		break;

	case 3:
		MasterBall += _pokeballs;
		break;
	}
	
}

void Trainer::addMoney(int _money)
{
	money += _money;
}

void Trainer::setDefeated(bool _defeated)
{
	defeated = _defeated;
}

void Trainer::AddPokemon(Pokemon newPokemon)
{
	pokemons.push_back(newPokemon);
}


std::vector<Pokemon>& Trainer::getTeam()
{
	return pokemons;
}


