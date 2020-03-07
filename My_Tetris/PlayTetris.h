#pragma once
#include <ctime>
#include <thread>
#include "Map.h"
#include "GameLogic.h"
#include "Figure.h"
#include "Factory.h"

class PlayTetris
{
protected:
	PlayTetris();
	void play(int difficulty);

private:
	Map map;
	GameLogic gameLogic;
	bool GameOver = false;
	bool checkFall = true;
	int score = 0;
};

