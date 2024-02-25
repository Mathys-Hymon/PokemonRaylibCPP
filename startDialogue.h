#pragma once
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>

class startDialogue {
private:
	Font ft;
    std::vector<std::string> dialogues;
	std::string name;
	int index;

public:
	void Load(Font ft);
	void Unload();
	void Update();
	void dialogue();
	void setName(std::string& name);
	int choice(const std::vector<std::string>& options, int spacing);
};
