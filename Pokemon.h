#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Ability.h"

using namespace std;

class Pokemon
{
private:
    std::string name;
    std::string description;
    int level;
    int xp;
    int lifePoints;
    int maxLife;
    int attackdamage;
    PokeType type;
    std::vector<Ability> abilitys;
    Texture2D sprite;

public:

    Pokemon(std::string name, std::string description, PokeType type, int life, int damage, Ability ability1, Ability ability2);

    void SetSprite(Texture2D& NewSprite);
    Texture2D& GetSprite();
    void SetName(string newName);
    string& GetName();
    PokeType GetType();
    void SetAbility(Ability newAbility);
    std::vector<Ability>& GetAbilitys();
    void GetDamage(int Damages);
    int GetLife();
    int GetMaxLife();
};