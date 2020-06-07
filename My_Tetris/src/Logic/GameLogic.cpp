#include "GameLogic.h"


GameLogic::GameLogic(){}
GameLogic::~GameLogic(){}

bool GameLogic::shiftFigure(Figure* pFigure, Map* pMap, const int& heightFigure,
                            const int shiftX, const int shiftY)
{
	checkNextLine = false;
	for (int i = 0; i < heightFigure; i++)
	{
		for (int j = 0; j < COORDINATE_F; j++)
		{
			if (pFigure->ThisFigure[i][j].icon > 0 && pFigure->ThisFigure[i + (shiftY)][j].icon <= 0 && shiftY)
			{
				if (pMap->getMap((pFigure->Coordinate[i].y + (shiftY)), pFigure->Coordinate[j].x) == ' ')
					checkNextLine = true;
				else 
					return false;
			}
			else if (pFigure->ThisFigure[i][j].icon > 0 && pFigure->ThisFigure[i][j + (shiftX)].icon <= 0 && shiftX != 0)
			{
				if (pMap->getMap(pFigure->Coordinate[i].y, pFigure->Coordinate[j].x + (shiftX)) == ' ')
					checkNextLine = true;
				else
					return false;
			}
		}
	}
	if (checkNextLine && shiftY)    // add new method
	{
		for (int i = 0; i < COORDINATE_F; i++)
			pFigure->Coordinate[i].y += shiftY;
		return true;
	}
	else if (checkNextLine && shiftX != 0)
	{
		for (int i = 0; i < COORDINATE_F; i++)
			pFigure->Coordinate[i].x += (shiftX);
		return false;
	}
}

void GameLogic::lowerTheMap(Map* pMap, int numOfLine)
{
	for (int i = numOfLine; i != 0; i--)
	{
		for (int j = 0; j < ((G_COORDINATE_X / 2) + ((G_COORDINATE_X / 2) / 4)+1); j++)
		{
			if (pMap->getFiguresMap(i, j) > 0)
			{
				pMap->setFiguresMap((i + 1), j, pMap->getFiguresMap(i, j));
				pMap->setFiguresMap(i, j, 0);
			}
		}
	}
}

int GameLogic::LineDeletion(Map* pMap, int& countLines)
{
	int countIconsInLine = 0;
	for (int i = 1; i < G_COORDINATE_Y; i++)
	{
		countIconsInLine = 0;
		for (int j = 0; j < (G_CENTER_OF_MAP + 1); j++)
		{
			pMap->getFiguresMap(i, j) ? countIconsInLine++ : countIconsInLine = 0;
			if (countIconsInLine == ((G_COORDINATE_X / 2) + ((G_COORDINATE_X / 2) / 4) - 1))
			{
				while (j)
				{
					pMap->setFiguresMap(i, j, 0);
					--j;
				}
				countLines++;
				return i;
			}
		}
	}
	return 0;
}

int GameLogic::lineRemovalAssembly(Map* pMap)
{
	int numOfLine = 0;
	int countLines = 0;
	do {
		numOfLine = GameLogic::LineDeletion(pMap, countLines);
		GameLogic::lowerTheMap(pMap, numOfLine);
	} while (numOfLine);
	return GameLogic::increaseScore(countLines);
}

void GameLogic::input(bool& GameOver, Figure* pFigure, Map* pMap)
{
	if (OsHelper::m_kbhit())
	{
	    ch = OsHelper::m_getch();
		switch (ch)
		{
		case 'a': 
			GameLogic::shiftFigure(pFigure, pMap, pFigure->heightFigure, -1, 0);
			break;
		case 'd': 
			GameLogic::shiftFigure(pFigure, pMap, pFigure->heightFigure, 1, 0);
			break;
		case 's': 
			GameLogic::shiftFigure(pFigure, pMap, pFigure->heightFigure, 0, 1);
			break;
		case 'q': 
			pFigure->inverse(pFigure);
			break;
		case '`': 
			GameOver = true; 
			break;
		}
	}
}

int GameLogic::increaseScore(int lines)
{
	int res = 0;
	for (int i = 0; i < lines; lines--)
		res += (lines * 10);
	return res;
}

bool GameLogic::gameover(Map* pMap, Figure* pFigure)
{
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = pFigure->heightFigure; j > 0 ; j--)
			if (pMap->getFiguresMap(j, pFigure->Coordinate[i].x) > 0)
				return true;
	return false;
}
