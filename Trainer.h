#include "Pokemon.h"
#include <iostream>
#include <string>
#include <vector>


class Trainer
{
private:
	std::string firstName;
	std::string lastName;
	std::string catchphrase;
	int money;
	float lifePoints;
	float maxLife;
	std::vector<Pokemon> pokemons;

public:

	Trainer(std::string firstName, std::string lastName, std::string catchPhrase, int money, int life, std::vector<Pokemon> team);

	void setName(string newName);
	string& getFirstName();
	string& getLastName();
	string& getCatchPhrase();
	void AddPokemon(Pokemon newPokemon);
	std::vector<Pokemon>& getTeam();
};

