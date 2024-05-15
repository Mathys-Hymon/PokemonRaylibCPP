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
	int money = 0;
	int pokeball = 5;
	bool defeated = false;
	float lifePoints;
	float maxLife;
	std::vector<Pokemon> pokemons;

public:

	Trainer(std::string firstName, std::string lastName, std::string catchPhrase, int money, int life, std::vector<Pokemon> team);

	void setName(string newName);
	string& getFirstName();
	string& getLastName();
	string& getCatchPhrase();
	bool getDefeated();
	int getMoney();
	int getPokeballs();
	void RemovePokemon(int index);
	void SetPokeballs(int value);
	void addPokeball(int _pokeballs);
	void addMoney(int _money);
	void setDefeated(bool _defeated);
	void AddPokemon(Pokemon newPokemon);
	std::vector<Pokemon>& getTeam();
};

