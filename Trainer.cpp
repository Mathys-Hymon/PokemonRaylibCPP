#include "Trainer.h"

Trainer::Trainer(string newFirstName, string newLastName, string newCatchPhrase, int money, int newLife, vector<Pokemon> newTeam)
	: firstName(newFirstName), lastName(newLastName), catchphrase(newCatchPhrase), money(money), lifePoints(newLife), pokemons(newTeam)
{
}
