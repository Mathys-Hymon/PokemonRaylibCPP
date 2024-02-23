#pragma once

#include "Pokemon.h"
#include "Trainer.h"
#include <vector>

class entityRef {
public:
    static std::vector<Ability> abilitys;
    static std::vector<Pokemon> allPokemons;
    static std::vector<Trainer> trainers;

    void LoadImages();
};