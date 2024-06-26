#pragma once
#include <iostream>
#include "fight.h"
#include "raylib.h"
#include <string>
#include <vector>

class startDialogue {
private:
	Font ft;
    std::vector<std::string> dialogues;
	std::string name;
	Texture2D centerSprite;
	Texture2D lakeSprite;
	Texture2D grassSprite;
	Texture2D leagueSprite;
	Texture2D cadreSprite;

	int index;
	int opponentIndex = 1;
	int fightResult;

public:
	void Load(Font ft);
	void Unload();
	void Update();
	void dialogue();
	void setName(std::string& name);
	int choice(const std::vector<std::string>& options, float spacing, float yPos);
	bool button(std::string name, Vector2 pos, Vector2 size);
};
