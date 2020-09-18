#pragma once
#include <ctime>
//#include <pthread.h>
#include <thread>
#include "../Map/Map.h"
#include "../Logic/GameLogic.h"
#include "../Figuries/Figure.h"
#include "../Factory/Factory.h"
#include "../OsHelper.h"
#include "IGame.h"
#include <thread>


class PlayTetris : public IGame
{
public:
	PlayTetris();
	int play(int difficulty) override;

private:
	Map map;
	GameLogic gameLogic;
	bool GameOver;
	bool checkFall;
	int score;
};

