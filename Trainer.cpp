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

int Trainer::getPokeballs()
{
	return pokeball;
}

void Trainer::RemovePokemon(int index)
{
	pokemons.erase(pokemons.begin() + index);
}

void Trainer::SetPokeballs(int value)
{
	pokeball += value;
}

void Trainer::addPokeball(int _pokeballs)
{
	pokeball += _pokeballs;
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


