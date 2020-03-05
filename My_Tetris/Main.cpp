//#include <conio.h>
//#include <Windows.h>
#include <ctime>
#include <thread>
#include "Map.h"
#include "GameLogic.h"
#include "Figure.h"
#include "Factory.h"


int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));
	bool GameOver = false;
	bool checkFall = true;

	Map map;
	GameLogic gameLogic;
	Figure* figure = Factory::figures();
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
			figure = Factory::figures();
			figure->push_figure();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		checkFall = gameLogic.shiftFigure(figure, &map, figure->heightFigure, 0, 1);
		gameLogic.lineDeletion(&map);

	}
	return 0;
}
