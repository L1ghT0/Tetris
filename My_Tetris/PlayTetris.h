#pragma once
#include <ctime>
#include <thread>
#include "Map.h"
#include "GameLogic.h"
#include "Figure.h"
#include "Factory.h"

class PlayTetris
{
public:
	PlayTetris();
	int play(int difficulty);
	int getScore() { return this->score; }

private:
	Map map;
	GameLogic gameLogic;
	bool GameOver = false;
	bool checkFall = true;
	int score;
};

