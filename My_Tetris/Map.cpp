#include "Map.h"


Map::Map()
{
	icon = 220;
	AddFigure = false;
	
	for (int i = 0; i < COORDINATE_Y; i++)
		for (int j = 0; j < COORDINATE_X; j++)
			mapBool[i][j] = 0;
}

Map::~Map()
{

}

void Map::addOnMap(Figure* figure)
{
	for (int i = 0; i < COORDINATE_Y; i++)
	{
		for (int j = 0; j < COORDINATE_X; j++)
		{
			for (int n = 0; n < COORDINATE_Y; n++)
				for (int m = 0; m < COORDINATE_X; m++)
					if (mapBool[n][m])
						map[n][m] = this->icon = 219;

			if (i == 0)
			{
				map[i][j] = this->icon = 220;
			}
			else if (j == 0 || j == ((COORDINATE_X/2)+ ((COORDINATE_X / 2)/4)) || j == (COORDINATE_X-1) || i == (COORDINATE_Y-1))
			{
				map[i][j] = this->icon = 219;
			}
			else
			{
				for (int k = 0; k < COORDINATE_F; k++)
				{
					for (int l = 0; l < COORDINATE_F; l++)
					{
						if (i == figure->Coordinate[k].y && j == figure->Coordinate[l].x && figure->ThisFigure[k][l].icon == 1)
						{
							map[i][j] = this->icon = 219 + 255*(figure->getColor());
							AddFigure = true;
						}
					}
				}
				if (!AddFigure)
				{
					map[i][j] = ' ';
				}
				AddFigure = false;
			}
		}
	}
}

void Map::Print_map()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < COORDINATE_Y; i++)
	{
		for (int j = 0; j < COORDINATE_X; j++)
		{
			if (map[i][j] > 255)
			{
				char x = map[i][j] % 255;
				int colorNum = map[i][j] / 255;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colorNum));
				std::cout << x/*(char)(map[i][j] - 255)*/;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
			}
			else
				std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::saveFigureForMap(Figure* figure)
{
	for (int i = 0; i < COORDINATE_Y; i++)
	{
		for (int j = 0; j < COORDINATE_X; j++)
		{
			for (int k = 0; k < COORDINATE_F; k++)
			{
				for (int l = 0; l < COORDINATE_F; l++)
				{
					if (i == figure->Coordinate[k].y && j == figure->Coordinate[l].x && figure->ThisFigure[k][l].icon == 1)
					{
						mapBool[i][j] = 1;
					}
				}
			}
		}
	}
}

char Map::getMap(int y, int x)
{
	return this->map[y][x];
}

bool Map::getBoolMap(int y, int x)
{
	return this->mapBool[y][x];
}

void Map::setBoolMap(int y, int x, bool icon)
{
	this->mapBool[y][x] = icon;
}

