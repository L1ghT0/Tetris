#include "PlayTetris.h"

PlayTetris::PlayTetris()
{
	GameOver = false;
	checkFall = true;
	score = 0;
}

void PlayTetris::play(int difficulty)
{
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
}
