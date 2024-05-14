#pragma once

#include "Pokemon.h"
#include "Trainer.h"
#include <vector>


    Ability getAbility(int index);
    Pokemon getPokemon(int index);
    Pokemon getRandomPokemon(PokeType type);
    Pokemon getRandomPokemon();
    Ability getRandomAbility(PokeType type);
    Trainer& getTrainer(int index);

    void LoadTrainers();
    void LoadPokeSprites();
    void UnloadPokeSprites();