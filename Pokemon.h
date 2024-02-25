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
    float lifePoints;
    float maxLife;
    float attackdamage;
    PokeType type;
    std::vector<Ability> abilitys;
    Texture2D sprite;

public:

    Pokemon(std::string name, std::string description, PokeType type, float life, int damage, Ability ability1, Ability ability2);

    void SetSprite(Texture2D& NewSprite);
    Texture2D& GetSprite();
};