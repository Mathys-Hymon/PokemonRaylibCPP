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
	int pokeball = 5;
	int superBall;
	int HyperBall;
	int MasterBall;
	bool defeated;
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
	int getPokeballs(int _typePokeball);
	void addPokeballs(int _typePokeball, int _pokeballs);
	void addMoney(int _money);
	void setDefeated(bool _defeated);
	void AddPokemon(Pokemon newPokemon);
	std::vector<Pokemon>& getTeam();
};

