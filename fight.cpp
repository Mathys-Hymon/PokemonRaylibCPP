#include "fight.h"

void fight::Load(Font font)
{
	index = 0;
	ft = font;
	playerActifPokemon = -1;
}

int fight::StartFight(int OpponentIndex)
{
	int winFight = -1;

	DrawTextEx(ft, to_string(getTrainer(0).getTeam()[0].GetLife()).c_str(), Vector2{50, 20}, 20, 1, Color(BLACK));
	if (playerActifPokemon == -1 || getTrainer(0).getTeam()[playerActifPokemon].GetLife() <= 0) {
		playerActifPokemon = ChoosePokemon();
	}
	else {
		switch (index)
		{
		case 0:
			std::string name = getTrainer(1).getFirstName();
			std::string lName = getTrainer(1).getLastName();
			std::string catchphrase = getTrainer(1).getCatchPhrase();
			std::string text = name + " " + lName + " : " + catchphrase;

			DrawTextEx(ft, text.c_str(), Vector2{ 50, 185 }, 20, 1, Color(BLACK));
			break;
		}
	}


	return winFight;
}

int fight::ChoosePokemon()
{
	int choice = -1;
	for (int i = 0; i < getTrainer(0).getTeam().size(); i++) {
		DrawTextureEx(getTrainer(0).getTeam()[i].GetSprite(), Vector2{ 50, 100 }, 0, 2, Color(WHITE));
		DrawTextEx(ft, getTrainer(0).getTeam()[i].GetName().c_str(), Vector2{50, static_cast <float>(50 + i * 50) }, 20, 1, Color(BLACK));

		if (CheckCollisionPointRec(static_cast<Vector2>(GetMousePosition()), { 50, static_cast<float>(50 + i * 50), static_cast<float>(MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20)), 30 })) {
			DrawRectangleLines(50, 45 + i * 50, MeasureText(getTrainer(0).getTeam()[i].GetName().c_str(), 20) + 5, 30, BLACK);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				choice = i;
			}
		}
	}
	return choice;
}
