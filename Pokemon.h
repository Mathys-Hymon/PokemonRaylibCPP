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
    int level = 1;
    int xp = 0;
    int xpToLVL = 5;
    float lifePoints;
    float maxLife;
    int attackdamage;
    PokeType type;
    std::vector<Ability> abilitys;
    std::vector<Ability> abilityChoice;
    Texture2D sprite;
    Texture2D pokeballSprite;

public:

    Pokemon(std::string name, std::string description, PokeType type, int life, int damage, Ability ability1, Ability ability2);

    void SetSprite(Texture& NewSprite);
    Texture2D& GetSprite();
    Texture2D& getPokeballSprite();
    void SetPokeballSprite(Texture2D NewSprite);
    void SetName(string newName);

    string& GetName();
    PokeType GetType();
    void SetAbility(Ability newAbility);
    std::vector<Ability>& GetAbilitys();
    void GetDamage(int Damages);
    float GetLife();
    float GetMaxLife();
    void setLife(int life);
    void FullHeal();
    int GetLevel();
    bool WinFight(int AmountOfXP);
    void LevelUp();
};