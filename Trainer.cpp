#include "Trainer.h"

Trainer::Trainer(string newFirstName, string newLastName, string newCatchPhrase, int money, int newLife, vector<Pokemon> newTeam)
	: firstName(newFirstName), lastName(newLastName), catchphrase(newCatchPhrase), money(money), lifePoints(newLife), pokemons(newTeam)
{
}

void Trainer::setName(string newName)
{
	firstName = newName;
}

string& Trainer::getName()
{
	return firstName;
}

void Trainer::AddPokemon(Pokemon newPokemon)
{
	pokemons.push_back(newPokemon);
}
