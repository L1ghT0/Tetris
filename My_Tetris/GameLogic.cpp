#include "GameLogic.h"


GameLogic::GameLogic()
{
}

GameLogic::~GameLogic(){}

bool GameLogic::shiftFigure(Figure* figure, Map* map, const int& heightFigure, int shiftX, int shiftY)
{
	checkNextLine = false;
	for (int i = 0; i < heightFigure; i++)
	{
		for (int j = 0; j < COORDINATE_F; j++)
		{
			if (figure->ThisFigure[i][j].icon == true && figure->ThisFigure[i + (shiftY)][j].icon != true && shiftY)
			{
				if (map->getMap((figure->coordinate[i].y + (shiftY)), figure->coordinate[j].x) == ' ')
					checkNextLine = true;
				else 
					return false;
			}
			else if (figure->ThisFigure[i][j].icon == true && figure->ThisFigure[i][j + (shiftX)].icon != true && shiftX != 0)
			{
				if (map->getMap(figure->coordinate[i].y, figure->coordinate[j].x + (shiftX)) == ' ')
					checkNextLine = true;
				else
					return false;
			}
		}
	}
	if (checkNextLine && shiftY)
	{
		for (int i = 0; i < COORDINATE_F; i++)
			figure->coordinate[i].y += shiftY;

		return true;
	}
	else if (checkNextLine && shiftX != 0)
	{
		for (int i = 0; i < COORDINATE_F; i++)
			figure->coordinate[i].x += (shiftX);
		return false;
	}
}

void GameLogic::lineDeletion(Map* map)	
{
	int count;
	int countLineDel = 0;
	int numOfLine = 0;
	for (int i = 0; i < COORDINATE_Y; i++)
	{
		count = 0;
		for (int j = 0; j < ((COORDINATE_X / 2) + ((COORDINATE_X / 2) / 4) + 1); j++)
		{
			map->getBoolMap(i, j) ? count++ : count = 0;
			if (count == ((COORDINATE_X / 2) + ((COORDINATE_X / 2) / 4)-1))
			{
				while (j)
				{
					map->setBoolMap(i, j, 0);
					--j;
				}
				countLineDel++;
				numOfLine = i;
				break;
			}
		}
	}
	if (countLineDel)
	{
		while (countLineDel)
		{
			for (int i = numOfLine; i != 0; i--)
			{
				for (int j = 0; j < ((COORDINATE_X / 2) + ((COORDINATE_X / 2) / 4)+1); j++)
				{
					if (map->getBoolMap(i, j))
					{
						map->setBoolMap(i, j, 0);
						map->setBoolMap((i + 1), j, 1);
					}
				}
			}
			countLineDel--;
		}
	}
}

void GameLogic::input(bool& GameOver, Figure* figure, Map* map)
{
	if (_kbhit())
	{	
		ch = _getch();
		switch (ch)
		{
		case 'a': 
			GameLogic::shiftFigure(figure, map, figure->heightFigure, -1, 0);
			break;
		case 'd': 
			GameLogic::shiftFigure(figure, map, figure->heightFigure, 1, 0);
			break;
		case 's': 
			GameLogic::shiftFigure(figure, map, figure->heightFigure, 0, 1);
			break;
		case 'q': 
			figure->inverse(figure);
			break;
		case '`': GameOver = true; break;
		}
	}
}
