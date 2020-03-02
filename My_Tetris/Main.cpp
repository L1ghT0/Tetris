//#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <thread>
#include "Figure.h"
#include "Map.h"
#include "L_Figure.h"
#include "Back_L_Figure.h"
#include "Z_Figure.h"
#include "Back_Z_Figure.h"
#include "GameLogic.h"
#include "T_Figure.h"
#include "Square_Figure.h"
#include "Line_Figure.h"
int randomForChoise;

Figure* factory() {
	randomForChoise = rand() % 7;
	switch (randomForChoise)
	{
	case(0):
		return new L_Figure();
	case(1):
		return new Back_L_Figure();
	case(2):
		return new Z_Figure();
	case(3):
		return new Back_Z_Figure();
	case(4):
		return new T_Figure();
	case(5):
		return new Square_Figure();
	case(6):
		return new Line_Figure();
	default:
		break;
	}
}


int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));
	bool GameOver = false;
	bool checkFall = true;

	Map map;
	GameLogic gameLogic;
	Figure* figure = factory();
	figure->push_figure();

	std::thread th([&]()
		{
			while (true)
			{
				gameLogic.input(GameOver, figure, &map);
				map.addOnMap(figure);
				map.Print_map();
			}
		});
	th.detach();

	while (!GameOver)
	{
		if (!checkFall)
		{
			map.saveFigureForMap(figure);
			delete figure;
			figure = factory();
			figure->push_figure();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		checkFall = gameLogic.shiftFigure(figure, &map, figure->heightFigure, 0, 1);
		gameLogic.lineDeletion(&map);

	}
	return 0;
}
