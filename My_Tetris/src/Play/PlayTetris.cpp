#include "PlayTetris.h"

PlayTetris::PlayTetris()
{
	GameOver = false;
	checkFall = true;
	score = 0;
}

int PlayTetris::play(int difficulty)
{
	difficulty = 450 - (difficulty * 95);
	Figure* pFigure = Figure::createFigure();

	std::thread th([&](){
        while (!GameOver)
        {
            gameLogic.input(GameOver, pFigure, &map);
            map.addOnMap(pFigure);
            map.Print_map(this->score);
        }
	});

	while (!GameOver)
	{
		if (!checkFall)
		{
			map.saveFigureOnMap(pFigure);
			this->score += gameLogic.lineRemovalAssembly(&map);
			delete pFigure;
			pFigure = Figure::createFigure();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(difficulty));
		checkFall = gameLogic.shiftFigure(pFigure, &map, pFigure->getHeightFigure(), 0, 1);
		GameOver = gameLogic.gameover(&map, pFigure);
	}
	th.join();
	system("pause");
	OsHelper::m_sysCLaer();
	return this->score;
}





