#pragma once
#include <ctime>
#include <pthread.h>
#include <thread>
#include "../Map/Map.h"
#include "../Logic/GameLogic.h"
#include "../Figuries/Figure.h"
#include "../Factory/Factory.h"
#include "../OsHelper.h"
#include <thread>


class PlayTetris
{
public:
	PlayTetris();
	int play(int difficulty);

private:
	Map map;
	GameLogic gameLogic;
	bool GameOver;
	bool checkFall;
	int score;
};

